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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/primitive/array/Natural32.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:46.221286 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.primitive.array.Natural32
// Version:       1.0

#ifndef UAVCAN_PRIMITIVE_ARRAY_NATURAL32_INCLUDED
#define UAVCAN_PRIMITIVE_ARRAY_NATURAL32_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    size_t value_length;
    uint32_t value[64];
} uavcan_primitive_array_Natural32_1_0;

/// The maximum capacity of uavcan_primitive_array_Natural32_1_0.value.
static inline size_t uavcan_primitive_array_Natural32_1_0_value_array_capacity(void)
{
    return (64U);
}

/// If true then uavcan_primitive_array_Natural32_1_0.value's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_primitive_array_Natural32_1_0_value_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_primitive_array_Natural32_1_0.value is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If value is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_primitive_array_Natural32_1_0_value_array_length(
    const uavcan_primitive_array_Natural32_1_0* const instance)
{
    return (instance == NULL) ? 0 : instance->value_length;
}

/// Initialize an uavcan_primitive_array_Natural32_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_primitive_array_Natural32_1_0_init(uavcan_primitive_array_Natural32_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->value_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_primitive_array_Natural32_1_0
/// instance.
#define uavcan_primitive_array_Natural32_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (257U)


/// Serialization of uavcan_primitive_array_Natural32_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_primitive_array_Natural32_1_0_serialize(const uavcan_primitive_array_Natural32_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint32[<=64]
    
        if (in_instance->value_length > 64)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->value_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->value, in_instance->value_length * 4);
        offset += in_instance->value_length * 32;
    // End Structure: saturated uint32[<=64]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_primitive_array_Natural32_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_primitive_array_Natural32_1_0_deserialize(uavcan_primitive_array_Natural32_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint32[<=64]
    
    out_instance->value_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->value_length > 64)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->value, (void*) in_buffer + (offset >> 3), out_instance->value_length * 4);
    offset += out_instance->value_length * 32;
    // End Structure: saturated uint32[<=64]

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_PRIMITIVE_ARRAY_NATURAL32 */
