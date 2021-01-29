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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/si/sample/angle/Quaternion.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:46.999187 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.si.sample.angle.Quaternion
// Version:       1.0

#ifndef UAVCAN_SI_SAMPLE_ANGLE_QUATERNION_INCLUDED
#define UAVCAN_SI_SAMPLE_ANGLE_QUATERNION_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/time/SynchronizedTimestamp_1_0.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    float wxyz[4];
    uavcan_time_SynchronizedTimestamp_1_0 timestamp;
} uavcan_si_sample_angle_Quaternion_1_0;

/// The maximum capacity of uavcan_si_sample_angle_Quaternion_1_0.wxyz.
static inline size_t uavcan_si_sample_angle_Quaternion_1_0_wxyz_array_capacity(void)
{
    return (4U);
}

/// If true then uavcan_si_sample_angle_Quaternion_1_0.wxyz's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_si_sample_angle_Quaternion_1_0_wxyz_array_is_variable_length(void)
{
    return (false);
}

/// If uavcan_si_sample_angle_Quaternion_1_0.wxyz is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If wxyz is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_si_sample_angle_Quaternion_1_0_wxyz_array_length(
    const uavcan_si_sample_angle_Quaternion_1_0* const instance)
{
    /* Not used for fixed arrays. */
    (void)instance;
    return (4U);
}

/// Initialize an uavcan_si_sample_angle_Quaternion_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_si_sample_angle_Quaternion_1_0_init(uavcan_si_sample_angle_Quaternion_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        memset(&(out_instance->wxyz[0]), 0, sizeof(float) * 4);
        uavcan_time_SynchronizedTimestamp_1_0_init(&(out_instance->timestamp));
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_si_sample_angle_Quaternion_1_0
/// instance.
#define uavcan_si_sample_angle_Quaternion_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (23U)


/// Serialization of uavcan_si_sample_angle_Quaternion_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_sample_angle_Quaternion_1_0_serialize(const uavcan_si_sample_angle_Quaternion_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32[4]
    
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->wxyz, in_instance->wxyz_length * 4);
        offset += in_instance->wxyz_length * 32;
    // End Structure: saturated float32[4]
    // Begin Structure: uavcan.time.SynchronizedTimestamp.1.0
    rc = uavcan_time_SynchronizedTimestamp_1_0_serialize(&(in_instance->timestamp), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.time.SynchronizedTimestamp.1.0

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_si_sample_angle_Quaternion_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_sample_angle_Quaternion_1_0_deserialize(uavcan_si_sample_angle_Quaternion_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32[4]
    
    memcpy((void*)out_instance->wxyz, (void*) in_buffer + (offset >> 3), out_instance->wxyz_length * 4);
    offset += out_instance->wxyz_length * 32;
    // End Structure: saturated float32[4]
    // Begin Structure: uavcan.time.SynchronizedTimestamp.1.0
    rc = uavcan_time_SynchronizedTimestamp_1_0_deserialize(&(out_instance->timestamp), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.time.SynchronizedTimestamp.1.0

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_SI_SAMPLE_ANGLE_QUATERNION */
