; These modify places in the game's code to work better with randomized entrances.

; Quitting auction normally calls dComIfGp_setNextStage(0.0, "sea", 3, 0xb, 0xff, 0, 1, 0) to put you back on Windfall
; This can be very inconvenient depending on what entrance led to the auction house
; Instead call dStage_changeScene(1, 0.0, 0, 0) and use the same exit as the door
; Then overwrite the exit's wipe type (0xB) with the original auction wipe type (0x0) so the fade out looks correct
.org 0x0205cb8c
    ; f1 already has the correct float arg
    li r3, 1 ; SCLS index in first param
    li r4, 0 ; Mode in second param
    li r5, 0 ; Room number with the SCLS entry in third param (-1 for stage)
    ; This next instruction has a relocation that would overwrite half of whatever we change it to
    addi r6, r6, 0 ; Change it to mess with an unused argument so the relocation is irrelevant
    bl dStage_changeScene
    bl FUN_025200d4 ; get gComIfG_inf_c instance in r3
    li r4, 0 ; Wipe type
    stb r4, 0x514D(r3) ; overwrite the wipe type that the SCLS entry used


; Normally the game checks if you were crawling when you entered a load zone to decide if you should be crawling after the load
; This can lead to some softlocks if you load into a crawlspace from a standing entrance
; Add a check for an unused param (X rotation & 0x0001), and force crawling if it is set
.org 0x02411df4 ; in daPy_lk_c::playerInit
    b custom_crawl_check
.org @NextFreeSpace
.global custom_crawl_check
custom_crawl_check:
    lhz r7, 0x2F8(r24) ; get original X rotation (currently just a copy of spawn X rotation)
    andi. r7, r7, 0x0001 ; mask out our param
    beq crawl_not_forced ; custom param is not set
    
    lbz r7, 0x1177(r9) ; load current mode
    cmpwi r7, 2
    beq crawl_not_forced ; already crawling forward
    cmpwi r7, 3
    beq crawl_not_forced ; already crawling backward

    li r7, 0x2 ; mode 2 (crawling forward)
    stb r7, 0x1177(r9) ; store this mode (is ignored for some spawn types)

crawl_not_forced:
    cmpwi r6, 0xE ; replace the line we overwrote to jump here
    b 0x02411df8

; This is some untested code that should allow voids to respawn crawling
; Don't believe it is ever needed though
; ; When reloading a room with startCode -1 (voids, ect)
; .org 0x025c1860 ; normally stores 0 to X rotation
;     b load_custom_restart_flag
; .org @NextFreeSpace
; .global load_custom_restart_flag
; load_custom_restart_flag:
;     lbz r5, 0x114B(r8) ; custom flag at +0x3 in dSv_restart_c
;     sth r5, 0x10(r27) ; store to X rotation
;     b 0x025c1864 ; continue
; 
; ; When setting a new restart location
; .org 0x024133d8
;     b set_custom_restart_flag
; .org @NextFreeSpace
; .global set_custom_restart_flag
; set_custom_restart_flag:
;     bl dSv_restart_c_setRoom ; replace the line we overwrote to jump here
;     lhz r4, 0x2F8(r31) ; load original X rotation (copy of the spawn point's X rotation)
;     stb r4, 0x3(r3) ; store flag to restart


; If the game expects you to spawn on KoRL and he is not there, the game will hang
; Instead, check if the spawn type was 5, and fall back to the type 5 spawn without KoRL if it is
.org 0x024136a8
    b boat_spawn_fallback_check
.org @NextFreeSpace
.global boat_spawn_fallback_check
boat_spawn_fallback_check:
    bne continue_with_boat
    cmpwi r24, 5 
    bne continue_with_fail
    b 0x0241382c

continue_with_fail:
    b 0x024136ac

continue_with_boat:
    b 0x024136d0


; When you have the map open on the gamepad screen it only "reloads" when transitions like overworld -> dungeon occur
; When entrances are randomized and you load from a dungeon into another dungeon, it doesn't switch the gamepad map properly and crashes
; Force a map reload if the dungeon changes (TODO: this fix isn't ideal but it averts the crash for now)
.org 0x02657F04 ; code that updates the dungeon map pointer
    b force_map_reload
.org @NextFreeSpace
.global force_map_reload
force_map_reload:
    lwzx r0, r9, r11 ; replace the line we overwrote to jump here
    lwz r12, 0x920(r3) ; load current dungeon map pointer
    cmpw r0, r12
    beq map_pointer_not_changed

    li r12, 0x0
    stw r12, 0x64(r8) ; pretend we were just on an overworld map

map_pointer_not_changed:
    b 0x02657F08 ; continue as normal


; Normally, going through a small key-locked door backwards still requires the key, but does not consume it
; This is a little unintuitive if you don't have these doors memorized and enter a dungeon from a (mini)boss entrance
; Change this behavior so you can open the doors backwards without a key
; (Doors check for keys by looking at the stage info (*not* the UI key counter) in setEventPrm for door10/door12/kddoor)
.org 0x021271A0 ; in daDoor10_c::setEventPrm
    b check_entering_door10_forwards
.org @NextFreeSpace
.global check_entering_door10_forwards
check_entering_door10_forwards:
    lbz r0, 0x3BC(r31) ; what side Link is opening the door from
    cmpwi r0, 0 ; 0 -> opening forwards
    beq door10_entering_lock_forwards
    b 0x021271AC ; continue with opening the door
door10_entering_lock_forwards:
    lbz r0, 0x7B8(r9) ; replace the line we overwrote to jump here
    b 0x021271A4 ; continue to check the key counter
    
.org 0x02129324 ; in daDoor12_c::setEventPrm
    b check_entering_door12_forwards
.org @NextFreeSpace
.global check_entering_door12_forwards
check_entering_door12_forwards:
    lbz r0, 0x3BC(r31) ; what side Link is opening the door from
    cmpwi r0, 0 ; 0 -> opening forwards
    beq door12_entering_lock_forwards
    b 0x02129330 ; continue with opening the door
door12_entering_lock_forwards:
    lbz r12, 0x7B8(r12) ; replace the line we overwrote to jump here
    b 0x02129328 ; continue to check the key counter


; The door on Private Oasis always requires the cabana deed, even from inside the cabana
; This can also be annoying with entrance randomizer, so change it to only require deed when entering
.org 0x021A4548 ; In daKnob00_c::actionVilla
    b check_leaving_cabana
.org @NextFreeSpace
.global check_leaving_cabana
check_leaving_cabana:
    ; Check if Link is open the door from the front
    lbz r0, 0x3BC(r31) ; What side Link is opening the door from
    cmpwi r0, 0 ; 0 -> Opening forwards
    beq cabana_set_normal_event_data

    ; setEventPrm sets event data based on the state the door is in
    ; If we are opening from the back, pretend we are in the waiting state so Deed isn't required
    li r3, 1 ; Wait state
    stb r3, 0x5A4(r31) ; Store to door's state
    mr r3, r31 ; Replace the line we overwrote to jump here
    bl daKnob_00_setEventPrm ; Set event data as if we're in the waiting state

    ; If we don't reset back to the Cabana state, the door will stay permanently in the waiting state on its next execute cycle
    ; This means that walking behind the door on Private Oasis and going back in front unlocks it even without Cabana Deed
    ; Which is definitely undesirable
    li r3, 8 ; Villa state
    stb r3, 0x5A4(r31) ; Restore to door's state so it doesn't break completely
    b 0x021A4550 ; Return
cabana_set_normal_event_data:
    mr r3, r31 ; Replace the line we overwrote to jump here
    b 0x021A454C ; Continue setting up the door event as normal


; Alter savewarping so that players respawn at their last visited ocean sector
; instead of whatever sector the cave/interior/area normally tries to savewarp
; them to. This is so players don't end up savewarping to an island they weren't on.
.org 0x025220C4
    bl set_return_place_as_last_visited_ocean_sector
.org @NextFreeSpace
.global set_return_place_as_last_visited_ocean_sector
set_return_place_as_last_visited_ocean_sector:
    lis r5, some_gfx_ptr@ha
    lwz r5, some_gfx_ptr@l(r5)
    lwz r5, 0x218 (r5)
    lbz r5, 0x3E (r5)
    addi r5, r5, 1
    b 0x025B50DC ; dSv_player_return_place_c::set
