// UAVCAN data structure definition.                                                                          +-+ +-+
//                                                                                                            | | | |
// AUTOGENERATED, DO NOT EDIT.                                                                                \  -  /
//                                                                                                              ---
//                                                                                                               o
// +------------------------------------------------------------------------------------------------------------------+
//
// Generator:
// nunavut-0.3.4 (serialization was enabled)
//
//
// Source File:
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/primitive/scalar/Integer16.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:45.021861 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.primitive.scalar.Integer16
// Version:       1.0

#ifndef UAVCAN_PRIMITIVE_SCALAR_INTEGER16_INCLUDED
#define UAVCAN_PRIMITIVE_SCALAR_INTEGER16_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    int16_t value;
} uavcan_primitive_scalar_Integer16_1_0;

/// Initialize an uavcan_primitive_scalar_Integer16_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_primitive_scalar_Integer16_1_0_init(uavcan_primitive_scalar_Integer16_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->value = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_primitive_scalar_Integer16_1_0
/// instance.
#define uavcan_primitive_scalar_Integer16_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (2U)


/// Serialization of uavcan_primitive_scalar_Integer16_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_primitive_scalar_Integer16_1_0_serialize(const uavcan_primitive_scalar_Integer16_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated int16
    
        nunavutSetIxx(out_buffer, offset, in_instance->value, 16);
        offset += 16;
    // End Structure: saturated int16

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_primitive_scalar_Integer16_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_primitive_scalar_Integer16_1_0_deserialize(uavcan_primitive_scalar_Integer16_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated int16
    out_instance->value = nunavutGetI16(in_buffer, buf_size_bytes, offset, 16);
    offset += 16;
    // End Structure: saturated int16

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_PRIMITIVE_SCALAR_INTEGER16 */
