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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/si/unit/magnetic_field_strength/Vector3.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:49.463264 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.si.unit.magnetic_field_strength.Vector3
// Version:       1.0

#ifndef UAVCAN_SI_UNIT_MAGNETIC_FIELD_STRENGTH_VECTOR3_INCLUDED
#define UAVCAN_SI_UNIT_MAGNETIC_FIELD_STRENGTH_VECTOR3_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    float tesla[3];
} uavcan_si_unit_magnetic_field_strength_Vector3_1_0;

/// The maximum capacity of uavcan_si_unit_magnetic_field_strength_Vector3_1_0.tesla.
static inline size_t uavcan_si_unit_magnetic_field_strength_Vector3_1_0_tesla_array_capacity(void)
{
    return (3U);
}

/// If true then uavcan_si_unit_magnetic_field_strength_Vector3_1_0.tesla's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_si_unit_magnetic_field_strength_Vector3_1_0_tesla_array_is_variable_length(void)
{
    return (false);
}

/// If uavcan_si_unit_magnetic_field_strength_Vector3_1_0.tesla is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If tesla is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_si_unit_magnetic_field_strength_Vector3_1_0_tesla_array_length(
    const uavcan_si_unit_magnetic_field_strength_Vector3_1_0* const instance)
{
    /* Not used for fixed arrays. */
    (void)instance;
    return (3U);
}

/// Initialize an uavcan_si_unit_magnetic_field_strength_Vector3_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_si_unit_magnetic_field_strength_Vector3_1_0_init(uavcan_si_unit_magnetic_field_strength_Vector3_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        memset(&(out_instance->tesla[0]), 0, sizeof(float) * 3);
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_si_unit_magnetic_field_strength_Vector3_1_0
/// instance.
#define uavcan_si_unit_magnetic_field_strength_Vector3_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (12U)


/// Serialization of uavcan_si_unit_magnetic_field_strength_Vector3_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_unit_magnetic_field_strength_Vector3_1_0_serialize(const uavcan_si_unit_magnetic_field_strength_Vector3_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32[3]
    
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->tesla, in_instance->tesla_length * 4);
        offset += in_instance->tesla_length * 32;
    // End Structure: saturated float32[3]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_si_unit_magnetic_field_strength_Vector3_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_unit_magnetic_field_strength_Vector3_1_0_deserialize(uavcan_si_unit_magnetic_field_strength_Vector3_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32[3]
    
    memcpy((void*)out_instance->tesla, (void*) in_buffer + (offset >> 3), out_instance->tesla_length * 4);
    offset += out_instance->tesla_length * 32;
    // End Structure: saturated float32[3]

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_SI_UNIT_MAGNETIC_FIELD_STRENGTH_VECTOR3 */
