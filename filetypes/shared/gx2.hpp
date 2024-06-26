//mostly taken from https://github.com/devkitPro/wut/blob/master/include/gx2/enum.h
#pragma once

#include <cstdint>

//use non-scoped enums to allow implicit conversions and related operator things

enum GX2AAMode : uint32_t
{
   GX2_AA_MODE1X                          = 0,
   GX2_AA_MODE2X                          = 1,
   GX2_AA_MODE4X                          = 2
};

enum GX2AlphaToMaskMode : uint32_t
{
   GX2_ALPHA_TO_MASK_MODE_NON_DITHERED    = 0,
   GX2_ALPHA_TO_MASK_MODE_DITHER_0        = 1,
   GX2_ALPHA_TO_MASK_MODE_DITHER_90       = 2,
   GX2_ALPHA_TO_MASK_MODE_DITHER_180      = 3,
   GX2_ALPHA_TO_MASK_MODE_DITHER_270      = 4,
};

enum GX2AttribFormat : uint32_t
{
   GX2_ATTRIB_TYPE_8                      = 0x00,
   GX2_ATTRIB_TYPE_4_4                    = 0x01,
   GX2_ATTRIB_TYPE_16                     = 0x02,
   GX2_ATTRIB_TYPE_16_FLOAT               = 0x03,
   GX2_ATTRIB_TYPE_8_8                    = 0x04,
   GX2_ATTRIB_TYPE_32                     = 0x05,
   GX2_ATTRIB_TYPE_32_FLOAT               = 0x06,
   GX2_ATTRIB_TYPE_16_16                  = 0x07,
   GX2_ATTRIB_TYPE_16_16_FLOAT            = 0x08,
   GX2_ATTRIB_TYPE_10_11_11_FLOAT         = 0x09,
   GX2_ATTRIB_TYPE_8_8_8_8                = 0x0A,
   GX2_ATTRIB_TYPE_10_10_10_2             = 0x0B,
   GX2_ATTRIB_TYPE_32_32                  = 0x0C,
   GX2_ATTRIB_TYPE_32_32_FLOAT            = 0x0D,
   GX2_ATTRIB_TYPE_16_16_16_16            = 0x0E,
   GX2_ATTRIB_TYPE_16_16_16_16_FLOAT      = 0x0F,
   GX2_ATTRIB_TYPE_32_32_32               = 0x10,
   GX2_ATTRIB_TYPE_32_32_32_FLOAT         = 0x11,
   GX2_ATTRIB_TYPE_32_32_32_32            = 0x12,
   GX2_ATTRIB_TYPE_32_32_32_32_FLOAT      = 0x13,

   GX2_ATTRIB_FLAG_INTEGER                = 0x100,
   GX2_ATTRIB_FLAG_SIGNED                 = 0x200,
   GX2_ATTRIB_FLAG_DEGAMMA                = 0x400,
   GX2_ATTRIB_FLAG_SCALED                 = 0x800,

   GX2_ATTRIB_FORMAT_UNORM_8              = GX2_ATTRIB_TYPE_8,
   GX2_ATTRIB_FORMAT_UNORM_8_8            = GX2_ATTRIB_TYPE_8_8,
   GX2_ATTRIB_FORMAT_UNORM_8_8_8_8        = GX2_ATTRIB_TYPE_8_8_8_8,

   GX2_ATTRIB_FORMAT_UINT_8               = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8,
   GX2_ATTRIB_FORMAT_UINT_8_8             = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8,
   GX2_ATTRIB_FORMAT_UINT_8_8_8_8         = GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8_8_8,

   GX2_ATTRIB_FORMAT_SNORM_8              = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8,
   GX2_ATTRIB_FORMAT_SNORM_8_8            = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8_8,
   GX2_ATTRIB_FORMAT_SNORM_8_8_8_8        = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_TYPE_8_8_8_8,

   GX2_ATTRIB_FORMAT_SINT_8               = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8,
   GX2_ATTRIB_FORMAT_SINT_8_8             = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8,
   GX2_ATTRIB_FORMAT_SINT_8_8_8_8         = GX2_ATTRIB_FLAG_SIGNED | GX2_ATTRIB_FLAG_INTEGER | GX2_ATTRIB_TYPE_8_8_8_8,

   GX2_ATTRIB_FORMAT_FLOAT_32             = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_FLOAT,
   GX2_ATTRIB_FORMAT_FLOAT_32_32          = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_FLOAT,
   GX2_ATTRIB_FORMAT_FLOAT_32_32_32       = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_32_FLOAT,
   GX2_ATTRIB_FORMAT_FLOAT_32_32_32_32    = GX2_ATTRIB_FLAG_SCALED | GX2_ATTRIB_TYPE_32_32_32_32_FLOAT,
};

enum GX2AttribIndexType : uint32_t
{
   GX2_ATTRIB_INDEX_PER_VERTEX            = 0,
   GX2_ATTRIB_INDEX_PER_INSTANCE          = 1,
};

enum GX2BlendMode : uint32_t
{
   GX2_BLEND_MODE_ZERO                    = 0,
   GX2_BLEND_MODE_ONE                     = 1,
   GX2_BLEND_MODE_SRC_COLOR               = 2,
   GX2_BLEND_MODE_INV_SRC_COLOR           = 3,
   GX2_BLEND_MODE_SRC_ALPHA               = 4,
   GX2_BLEND_MODE_INV_SRC_ALPHA           = 5,
   GX2_BLEND_MODE_DST_ALPHA               = 6,
   GX2_BLEND_MODE_INV_DST_ALPHA           = 7,
   GX2_BLEND_MODE_DST_COLOR               = 8,
   GX2_BLEND_MODE_INV_DST_COLOR           = 9,
   GX2_BLEND_MODE_SRC_ALPHA_SAT           = 10,
   GX2_BLEND_MODE_BOTH_SRC_ALPHA          = 11,
   GX2_BLEND_MODE_BOTH_INV_SRC_ALPHA      = 12,
   GX2_BLEND_MODE_BLEND_FACTOR            = 13,
   GX2_BLEND_MODE_INV_BLEND_FACTOR        = 14,
   GX2_BLEND_MODE_SRC1_COLOR              = 15,
   GX2_BLEND_MODE_INV_SRC1_COLOR          = 16,
   GX2_BLEND_MODE_SRC1_ALPHA              = 17,
   GX2_BLEND_MODE_INV_SRC1_ALPHA          = 18,
};

enum GX2BlendCombineMode : uint32_t
{
   GX2_BLEND_COMBINE_MODE_ADD             = 0,
   GX2_BLEND_COMBINE_MODE_SUB             = 1,
   GX2_BLEND_COMBINE_MODE_MIN             = 2,
   GX2_BLEND_COMBINE_MODE_MAX             = 3,
   GX2_BLEND_COMBINE_MODE_REV_SUB         = 4,
};

enum GX2BufferingMode : uint32_t
{
   GX2_BUFFERING_MODE_SINGLE              = 1,
   GX2_BUFFERING_MODE_DOUBLE              = 2,
   GX2_BUFFERING_MODE_TRIPLE              = 3,
};

enum GX2ChannelMask : uint32_t
{
   GX2_CHANNEL_MASK_R                     = 1,
   GX2_CHANNEL_MASK_G                     = 2,
   GX2_CHANNEL_MASK_RG                    = 3,
   GX2_CHANNEL_MASK_B                     = 4,
   GX2_CHANNEL_MASK_RB                    = 5,
   GX2_CHANNEL_MASK_GB                    = 6,
   GX2_CHANNEL_MASK_RGB                   = 7,
   GX2_CHANNEL_MASK_A                     = 8,
   GX2_CHANNEL_MASK_RA                    = 9,
   GX2_CHANNEL_MASK_GA                    = 10,
   GX2_CHANNEL_MASK_RGA                   = 11,
   GX2_CHANNEL_MASK_BA                    = 12,
   GX2_CHANNEL_MASK_RBA                   = 13,
   GX2_CHANNEL_MASK_GBA                   = 14,
   GX2_CHANNEL_MASK_RGBA                  = 15,
};

enum GX2ClearFlags : uint32_t
{
   GX2_CLEAR_FLAGS_DEPTH                  = 1,
   GX2_CLEAR_FLAGS_STENCIL                = 2,
   GX2_CLEAR_FLAGS_BOTH                   = (GX2_CLEAR_FLAGS_DEPTH | GX2_CLEAR_FLAGS_STENCIL),
};

enum GX2CompareFunction : uint32_t
{
   GX2_COMPARE_FUNC_NEVER                 = 0,
   GX2_COMPARE_FUNC_LESS                  = 1,
   GX2_COMPARE_FUNC_EQUAL                 = 2,
   GX2_COMPARE_FUNC_LEQUAL                = 3,
   GX2_COMPARE_FUNC_GREATER               = 4,
   GX2_COMPARE_FUNC_NOT_EQUAL             = 5,
   GX2_COMPARE_FUNC_GEQUAL                = 6,
   GX2_COMPARE_FUNC_ALWAYS                = 7,
};

enum GX2DrcRenderMode : uint32_t
{
   GX2_DRC_RENDER_MODE_DISABLED           = 0,
   GX2_DRC_RENDER_MODE_SINGLE             = 1,
};

enum GX2EventType : uint32_t
{
   GX2_EVENT_TYPE_START_OF_PIPE_INTERRUPT = 0,
   GX2_EVENT_TYPE_END_OF_PIPE_INTERRUPT   = 1,
   GX2_EVENT_TYPE_VSYNC                   = 2,
   GX2_EVENT_TYPE_FLIP                    = 3,
   GX2_EVENT_TYPE_DISPLAY_LIST_OVERRUN    = 4,
};

enum GX2EndianSwapMode : uint32_t
{
   GX2_ENDIAN_SWAP_NONE                   = 0,
   GX2_ENDIAN_SWAP_8_IN_16                = 1,
   GX2_ENDIAN_SWAP_8_IN_32                = 2,
   GX2_ENDIAN_SWAP_DEFAULT                = 3,
};

enum GX2FetchShaderType : uint32_t
{
   GX2_FETCH_SHADER_TESSELLATION_NONE     = 0,
   GX2_FETCH_SHADER_TESSELLATION_LINE     = 1,
   GX2_FETCH_SHADER_TESSELLATION_TRIANGLE = 2,
   GX2_FETCH_SHADER_TESSELLATION_QUAD     = 3,
};

enum GX2FrontFace : uint32_t
{
  GX2_FRONT_FACE_CCW                      = 0,
  GX2_FRONT_FACE_CW                       = 1,
};

enum GX2IndexType : uint32_t
{
   GX2_INDEX_TYPE_U16_LE                  = 0,
   GX2_INDEX_TYPE_U32_LE                  = 1,
   GX2_INDEX_TYPE_U16                     = 4,
   GX2_INDEX_TYPE_U32                     = 9,
};

enum GX2InvalidateMode : uint32_t
{
   GX2_INVALIDATE_MODE_NONE                = 0,
   GX2_INVALIDATE_MODE_ATTRIBUTE_BUFFER    = 1 << 0,
   GX2_INVALIDATE_MODE_TEXTURE             = 1 << 1,
   GX2_INVALIDATE_MODE_UNIFORM_BLOCK       = 1 << 2,
   GX2_INVALIDATE_MODE_SHADER              = 1 << 3,
   GX2_INVALIDATE_MODE_COLOR_BUFFER        = 1 << 4,
   GX2_INVALIDATE_MODE_DEPTH_BUFFER        = 1 << 5,
   GX2_INVALIDATE_MODE_CPU                 = 1 << 6,
   GX2_INVALIDATE_MODE_STREAM_OUT_BUFFER   = 1 << 7,
   GX2_INVALIDATE_MODE_EXPORT_BUFFER       = 1 << 8,
   GX2_INVALIDATE_MODE_CPU_ATTRIBUTE_BUFFER= GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_ATTRIBUTE_BUFFER,
   GX2_INVALIDATE_MODE_CPU_TEXTURE         = GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_TEXTURE,
   GX2_INVALIDATE_MODE_CPU_SHADER          = GX2_INVALIDATE_MODE_CPU | GX2_INVALIDATE_MODE_SHADER,
};

enum GX2InitAttributes : uint32_t
{
   GX2_INIT_END                           = 0,
   GX2_INIT_CMD_BUF_BASE                  = 1,
   GX2_INIT_CMD_BUF_POOL_SIZE             = 2,
   GX2_INIT_ARGC                          = 7,
   GX2_INIT_ARGV                          = 8,
   GX2_INIT_PROFILE_MODE                  = 9,
   GX2_INIT_TOSS_STAGE                    = 10,
   GX2_INIT_APP_IO_THREAD_STACK_SIZE      = 11,
};

enum GX2LogicOp : uint32_t
{
   GX2_LOGIC_OP_CLEAR                     = 0x00,
   GX2_LOGIC_OP_NOR                       = 0x11,
   GX2_LOGIC_OP_INV_AND                   = 0x22,
   GX2_LOGIC_OP_INV_COPY                  = 0x33,
   GX2_LOGIC_OP_REV_AND                   = 0x44,
   GX2_LOGIC_OP_INV                       = 0x55,
   GX2_LOGIC_OP_XOR                       = 0x66,
   GX2_LOGIC_OP_NOT_AND                   = 0x77,
   GX2_LOGIC_OP_AND                       = 0x88,
   GX2_LOGIC_OP_EQUIV                     = 0x99,
   GX2_LOGIC_OP_NOP                       = 0xAA,
   GX2_LOGIC_OP_INV_OR                    = 0xBB,
   GX2_LOGIC_OP_COPY                      = 0xCC,
   GX2_LOGIC_OP_REV_OR                    = 0xDD,
   GX2_LOGIC_OP_OR                        = 0xEE,
   GX2_LOGIC_OP_SET                       = 0xFF,
};

enum GX2PrimitiveMode : uint32_t
{
   GX2_PRIMITIVE_MODE_POINTS                    = 1,
   GX2_PRIMITIVE_MODE_LINES                     = 2,
   GX2_PRIMITIVE_MODE_LINE_STRIP                = 3,
   GX2_PRIMITIVE_MODE_TRIANGLES                 = 4,
   GX2_PRIMITIVE_MODE_TRIANGLE_FAN              = 5,
   GX2_PRIMITIVE_MODE_TRIANGLE_STRIP            = 6,
   GX2_PRIMITIVE_MODE_LINES_ADJACENCY           = 10,
   GX2_PRIMITIVE_MODE_LINE_STRIP_ADJACENCY      = 11,
   GX2_PRIMITIVE_MODE_TRIANGLES_ADJACENCY       = 12,
   GX2_PRIMITIVE_MODE_TRIANGLE_STRIP_ADJACENCY  = 13,
   GX2_PRIMITIVE_MODE_RECTS                     = 17,
   GX2_PRIMITIVE_MODE_LINE_LOOP                 = 18,
   GX2_PRIMITIVE_MODE_QUADS                     = 19,
   GX2_PRIMITIVE_MODE_QUAD_STRIP                = 20,
};

enum GX2PolygonMode : uint32_t
{
   GX2_POLYGON_MODE_POINT                 = 0,
   GX2_POLYGON_MODE_LINE                  = 1,
   GX2_POLYGON_MODE_TRIANGLE              = 2,
};

enum GX2RenderTarget : uint32_t
{
   GX2_RENDER_TARGET_0                    = 0,
   GX2_RENDER_TARGET_1                    = 1,
   GX2_RENDER_TARGET_2                    = 2,
   GX2_RENDER_TARGET_3                    = 3,
   GX2_RENDER_TARGET_4                    = 4,
   GX2_RENDER_TARGET_5                    = 5,
   GX2_RENDER_TARGET_6                    = 6,
   GX2_RENDER_TARGET_7                    = 7,
};

enum GX2RoundingMode : uint32_t
{
   GX2_ROUNDING_MODE_ROUND_TO_EVEN        = 0,
   GX2_ROUNDING_MODE_TRUNCATE             = 1,
};

enum GX2SamplerVarType : uint32_t
{
   GX2_SAMPLER_VAR_TYPE_SAMPLER_1D        = 0,
   GX2_SAMPLER_VAR_TYPE_SAMPLER_2D        = 1,
   GX2_SAMPLER_VAR_TYPE_SAMPLER_3D        = 3,
   GX2_SAMPLER_VAR_TYPE_SAMPLER_CUBE      = 4,
};

enum GX2ScanTarget : uint32_t
{
   GX2_SCAN_TARGET_TV                     = 1,
   GX2_SCAN_TARGET_DRC                    = 4,
};

enum GX2ShaderMode : uint32_t
{
   GX2_SHADER_MODE_UNIFORM_REGISTER       = 0,
   GX2_SHADER_MODE_UNIFORM_BLOCK          = 1,
   GX2_SHADER_MODE_GEOMETRY_SHADER        = 2,
   GX2_SHADER_MODE_COMPUTE_SHADER         = 3,
};

enum GX2ShaderVarType : uint32_t
{
   GX2_SHADER_VAR_TYPE_VOID               = 0,
   GX2_SHADER_VAR_TYPE_BOOL               = 1,
   GX2_SHADER_VAR_TYPE_INT                = 2,
   GX2_SHADER_VAR_TYPE_UINT               = 3,
   GX2_SHADER_VAR_TYPE_FLOAT              = 4,
   GX2_SHADER_VAR_TYPE_DOUBLE             = 5,
   GX2_SHADER_VAR_TYPE_DOUBLE2            = 6,
   GX2_SHADER_VAR_TYPE_DOUBLE3            = 7,
   GX2_SHADER_VAR_TYPE_DOUBLE4            = 8,
   GX2_SHADER_VAR_TYPE_FLOAT2             = 9,
   GX2_SHADER_VAR_TYPE_FLOAT3             = 10,
   GX2_SHADER_VAR_TYPE_FLOAT4             = 11,
   GX2_SHADER_VAR_TYPE_BOOL2              = 12,
   GX2_SHADER_VAR_TYPE_BOOL3              = 13,
   GX2_SHADER_VAR_TYPE_BOOL4              = 14,
   GX2_SHADER_VAR_TYPE_INT2               = 15,
   GX2_SHADER_VAR_TYPE_INT3               = 16,
   GX2_SHADER_VAR_TYPE_INT4               = 17,
   GX2_SHADER_VAR_TYPE_UINT2              = 18,
   GX2_SHADER_VAR_TYPE_UINT3              = 19,
   GX2_SHADER_VAR_TYPE_UINT4              = 20,
   GX2_SHADER_VAR_TYPE_FLOAT2X2           = 21,
   GX2_SHADER_VAR_TYPE_FLOAT2X3           = 22,
   GX2_SHADER_VAR_TYPE_FLOAT2X4           = 23,
   GX2_SHADER_VAR_TYPE_FLOAT3X2           = 24,
   GX2_SHADER_VAR_TYPE_FLOAT3X3           = 25,
   GX2_SHADER_VAR_TYPE_FLOAT3X4           = 26,
   GX2_SHADER_VAR_TYPE_FLOAT4X2           = 27,
   GX2_SHADER_VAR_TYPE_FLOAT4X3           = 28,
   GX2_SHADER_VAR_TYPE_FLOAT4X4           = 29,
   GX2_SHADER_VAR_TYPE_DOUBLE2X2          = 30,
   GX2_SHADER_VAR_TYPE_DOUBLE2X3          = 31,
   GX2_SHADER_VAR_TYPE_DOUBLE2X4          = 32,
   GX2_SHADER_VAR_TYPE_DOUBLE3X2          = 33,
   GX2_SHADER_VAR_TYPE_DOUBLE3X3          = 34,
   GX2_SHADER_VAR_TYPE_DOUBLE3X4          = 35,
   GX2_SHADER_VAR_TYPE_DOUBLE4X2          = 36,
   GX2_SHADER_VAR_TYPE_DOUBLE4X3          = 37,
   GX2_SHADER_VAR_TYPE_DOUBLE4X4          = 38,
};

enum GX2StencilFunction : uint32_t
{
   GX2_STENCIL_FUNCTION_KEEP              = 0,
   GX2_STENCIL_FUNCTION_ZERO              = 1,
   GX2_STENCIL_FUNCTION_REPLACE           = 2,
   GX2_STENCIL_FUNCTION_INCR_CLAMP        = 3,
   GX2_STENCIL_FUNCTION_DECR_CLAMP        = 4,
   GX2_STENCIL_FUNCTION_INV               = 5,
   GX2_STENCIL_FUNCTION_INCR_WRAP         = 6,
   GX2_STENCIL_FUNCTION_DECR_WRAP         = 7,
};

enum GX2SurfaceDim : uint32_t
{
   GX2_SURFACE_DIM_TEXTURE_1D             = 0,
   GX2_SURFACE_DIM_TEXTURE_2D             = 1,
   GX2_SURFACE_DIM_TEXTURE_3D             = 2,
   GX2_SURFACE_DIM_TEXTURE_CUBE           = 3,
   GX2_SURFACE_DIM_TEXTURE_1D_ARRAY       = 4,
   GX2_SURFACE_DIM_TEXTURE_2D_ARRAY       = 5,
   GX2_SURFACE_DIM_TEXTURE_2D_MSAA        = 6,
   GX2_SURFACE_DIM_TEXTURE_2D_MSAA_ARRAY  = 7,
};

enum GX2SurfaceFormat : uint32_t
{
   GX2_SURFACE_FORMAT_INVALID                   = 0x00,
   GX2_SURFACE_FORMAT_UNORM_R4_G4               = 0x02,
   GX2_SURFACE_FORMAT_UNORM_R4_G4_B4_A4         = 0x0b,
   GX2_SURFACE_FORMAT_UNORM_R8                  = 0x01,
   GX2_SURFACE_FORMAT_UNORM_R8_G8               = 0x07,
   GX2_SURFACE_FORMAT_UNORM_R8_G8_B8_A8         = 0x01a,
   GX2_SURFACE_FORMAT_UNORM_R16                 = 0x05,
   GX2_SURFACE_FORMAT_UNORM_R16_G16             = 0x0f,
   GX2_SURFACE_FORMAT_UNORM_R16_G16_B16_A16     = 0x01f,
   GX2_SURFACE_FORMAT_UNORM_R5_G6_B5            = 0x08,
   GX2_SURFACE_FORMAT_UNORM_R5_G5_B5_A1         = 0x0a,
   GX2_SURFACE_FORMAT_UNORM_A1_B5_G5_R5         = 0x0c,
   GX2_SURFACE_FORMAT_UNORM_R24_X8              = 0x011,
   GX2_SURFACE_FORMAT_UNORM_A2_B10_G10_R10      = 0x01b,
   GX2_SURFACE_FORMAT_UNORM_R10_G10_B10_A2      = 0x019,
   GX2_SURFACE_FORMAT_UNORM_BC1                 = 0x031,
   GX2_SURFACE_FORMAT_UNORM_BC2                 = 0x032,
   GX2_SURFACE_FORMAT_UNORM_BC3                 = 0x033,
   GX2_SURFACE_FORMAT_UNORM_BC4                 = 0x034,
   GX2_SURFACE_FORMAT_UNORM_BC5                 = 0x035,
   GX2_SURFACE_FORMAT_UNORM_NV12                = 0x081,

   GX2_SURFACE_FORMAT_UINT_R8                   = 0x101,
   GX2_SURFACE_FORMAT_UINT_R8_G8                = 0x107,
   GX2_SURFACE_FORMAT_UINT_R8_G8_B8_A8          = 0x11a,
   GX2_SURFACE_FORMAT_UINT_R16                  = 0x105,
   GX2_SURFACE_FORMAT_UINT_R16_G16              = 0x10f,
   GX2_SURFACE_FORMAT_UINT_R16_G16_B16_A16      = 0x11f,
   GX2_SURFACE_FORMAT_UINT_R32                  = 0x10d,
   GX2_SURFACE_FORMAT_UINT_R32_G32              = 0x11d,
   GX2_SURFACE_FORMAT_UINT_R32_G32_B32_A32      = 0x122,
   GX2_SURFACE_FORMAT_UINT_A2_B10_G10_R10       = 0x11b,
   GX2_SURFACE_FORMAT_UINT_R10_G10_B10_A2       = 0x119,
   GX2_SURFACE_FORMAT_UINT_X24_G8               = 0x111,
   GX2_SURFACE_FORMAT_UINT_G8_X24               = 0x11c,

   GX2_SURFACE_FORMAT_SNORM_R8                  = 0x201,
   GX2_SURFACE_FORMAT_SNORM_R8_G8               = 0x207,
   GX2_SURFACE_FORMAT_SNORM_R8_G8_B8_A8         = 0x21a,
   GX2_SURFACE_FORMAT_SNORM_R16                 = 0x205,
   GX2_SURFACE_FORMAT_SNORM_R16_G16             = 0x20f,
   GX2_SURFACE_FORMAT_SNORM_R16_G16_B16_A16     = 0x21f,
   GX2_SURFACE_FORMAT_SNORM_R10_G10_B10_A2      = 0x219,
   GX2_SURFACE_FORMAT_SNORM_BC4                 = 0x234,
   GX2_SURFACE_FORMAT_SNORM_BC5                 = 0x235,

   GX2_SURFACE_FORMAT_SINT_R8                   = 0x301,
   GX2_SURFACE_FORMAT_SINT_R8_G8                = 0x307,
   GX2_SURFACE_FORMAT_SINT_R8_G8_B8_A8          = 0x31a,
   GX2_SURFACE_FORMAT_SINT_R16                  = 0x305,
   GX2_SURFACE_FORMAT_SINT_R16_G16              = 0x30f,
   GX2_SURFACE_FORMAT_SINT_R16_G16_B16_A16      = 0x31f,
   GX2_SURFACE_FORMAT_SINT_R32                  = 0x30d,
   GX2_SURFACE_FORMAT_SINT_R32_G32              = 0x31d,
   GX2_SURFACE_FORMAT_SINT_R32_G32_B32_A32      = 0x322,
   GX2_SURFACE_FORMAT_SINT_R10_G10_B10_A2       = 0x319,

   GX2_SURFACE_FORMAT_SRGB_R8_G8_B8_A8          = 0x41a,
   GX2_SURFACE_FORMAT_SRGB_BC1                  = 0x431,
   GX2_SURFACE_FORMAT_SRGB_BC2                  = 0x432,
   GX2_SURFACE_FORMAT_SRGB_BC3                  = 0x433,

   GX2_SURFACE_FORMAT_FLOAT_R32                 = 0x80e,
   GX2_SURFACE_FORMAT_FLOAT_R32_G32             = 0x81e,
   GX2_SURFACE_FORMAT_FLOAT_R32_G32_B32_A32     = 0x823,
   GX2_SURFACE_FORMAT_FLOAT_R16                 = 0x806,
   GX2_SURFACE_FORMAT_FLOAT_R16_G16             = 0x810,
   GX2_SURFACE_FORMAT_FLOAT_R16_G16_B16_A16     = 0x820,
   GX2_SURFACE_FORMAT_FLOAT_R11_G11_B10         = 0x816,
   GX2_SURFACE_FORMAT_FLOAT_D24_S8              = 0x811,
   GX2_SURFACE_FORMAT_FLOAT_X8_X24              = 0x81c,
};

enum GX2SurfaceUse : uint32_t
{
   GX2_SURFACE_USE_NONE                         = 0,
   GX2_SURFACE_USE_TEXTURE                      = 1 << 0,
   GX2_SURFACE_USE_COLOR_BUFFER                 = 1 << 1,
   GX2_SURFACE_USE_DEPTH_BUFFER                 = 1 << 2,
   GX2_SURFACE_USE_SCAN_BUFFER                  = 1 << 3,
   GX2_SURFACE_USE_TV                           = 1U << 31, //error if it shifts a signed value
   GX2_SURFACE_USE_TEXTURE_COLOR_BUFFER_TV      = (GX2_SURFACE_USE_TEXTURE | GX2_SURFACE_USE_COLOR_BUFFER | GX2_SURFACE_USE_TV)
};

enum GX2TessellationMode : uint32_t
{
   GX2_TESSELLATION_MODE_DISCRETE         = 0,
   GX2_TESSELLATION_MODE_CONTINUOUS       = 1,
   GX2_TESSELLATION_MODE_ADAPTIVE         = 2,
};

enum GX2TexBorderType : uint32_t
{
   GX2_TEX_BORDER_TYPE_TRANSPARENT_BLACK  = 0,
   GX2_TEX_BORDER_TYPE_BLACK              = 1,
   GX2_TEX_BORDER_TYPE_WHITE              = 2,
   GX2_TEX_BORDER_TYPE_VARIABLE           = 3,
};

enum GX2TexClampMode : uint32_t
{
   GX2_TEX_CLAMP_MODE_WRAP                = 0,
   GX2_TEX_CLAMP_MODE_MIRROR              = 1,
   GX2_TEX_CLAMP_MODE_CLAMP               = 2,
   GX2_TEX_CLAMP_MODE_MIRROR_ONCE         = 3,
   GX2_TEX_CLAMP_MODE_CLAMP_BORDER        = 6,
};

enum GX2TexMipFilterMode : uint32_t
{
   GX2_TEX_MIP_FILTER_MODE_NONE           = 0,
   GX2_TEX_MIP_FILTER_MODE_POINT          = 1,
   GX2_TEX_MIP_FILTER_MODE_LINEAR         = 2,
};

enum GX2TexMipPerfMode : uint32_t
{
   GX2_TEX_MIP_PERF_MODE_DISABLE          = 0,
};

enum GX2TexXYFilterMode : uint32_t
{
   GX2_TEX_XY_FILTER_MODE_POINT          = 0,
   GX2_TEX_XY_FILTER_MODE_LINEAR         = 1,
};

enum GX2TexAnisoRatio : uint32_t
{
   GX2_TEX_ANISO_RATIO_NONE               = 0,
};

enum GX2TexZFilterMode : uint32_t
{
   GX2_TEX_Z_FILTER_MODE_NONE             = 0,
   GX2_TEX_Z_FILTER_MODE_POINT            = 1,
   GX2_TEX_Z_FILTER_MODE_LINEAR           = 2,
};

enum GX2TexZPerfMode : uint32_t
{
   GX2_TEX_Z_PERF_MODE_DISABLED           = 0,
};

enum GX2TileMode : uint32_t
{
   GX2_TILE_MODE_DEFAULT                  = 0,
   GX2_TILE_MODE_LINEAR_ALIGNED           = 1,
   GX2_TILE_MODE_TILED_1D_THIN1           = 2,
   GX2_TILE_MODE_TILED_1D_THICK           = 3,
   GX2_TILE_MODE_TILED_2D_THIN1           = 4,
   GX2_TILE_MODE_TILED_2D_THIN2           = 5,
   GX2_TILE_MODE_TILED_2D_THIN4           = 6,
   GX2_TILE_MODE_TILED_2D_THICK           = 7,
   GX2_TILE_MODE_TILED_2B_THIN1           = 8,
   GX2_TILE_MODE_TILED_2B_THIN2           = 9,
   GX2_TILE_MODE_TILED_2B_THIN4           = 0xA,
   GX2_TILE_MODE_TILED_2B_THICK           = 0xB,
   GX2_TILE_MODE_TILED_3D_THIN1           = 0xC,
   GX2_TILE_MODE_TILED_3D_THICK           = 0xD,
   GX2_TILE_MODE_TILED_3B_THIN1           = 0xE,
   GX2_TILE_MODE_TILED_3B_THICK           = 0xF,
   GX2_TILE_MODE_LINEAR_SPECIAL           = 0x10,
};

enum GX2TVRenderMode : uint32_t
{
   GX2_TV_RENDER_MODE_DISABLED            = 0,
   GX2_TV_RENDER_MODE_STANDARD_480P       = 1,
   GX2_TV_RENDER_MODE_WIDE_480P           = 2,
   GX2_TV_RENDER_MODE_WIDE_720P           = 3,
   GX2_TV_RENDER_MODE_WIDE_1080P          = 5,
};

enum GX2TVScanMode : uint32_t
{
   GX2_TV_SCAN_MODE_NONE                  = 0,
   GX2_TV_SCAN_MODE_576I                  = 1,
   GX2_TV_SCAN_MODE_480I                  = 2,
   GX2_TV_SCAN_MODE_480P                  = 3,
   GX2_TV_SCAN_MODE_720P                  = 4,
   GX2_TV_SCAN_MODE_1080I                 = 6,
   GX2_TV_SCAN_MODE_1080P                 = 7,
};
