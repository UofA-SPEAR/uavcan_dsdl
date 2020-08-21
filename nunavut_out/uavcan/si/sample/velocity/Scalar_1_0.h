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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/si/sample/velocity/Scalar.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:47.987078 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.si.sample.velocity.Scalar
// Version:       1.0

#ifndef UAVCAN_SI_SAMPLE_VELOCITY_SCALAR_INCLUDED
#define UAVCAN_SI_SAMPLE_VELOCITY_SCALAR_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/time/SynchronizedTimestamp_1_0.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    float meter_per_second;
    uavcan_time_SynchronizedTimestamp_1_0 timestamp;
} uavcan_si_sample_velocity_Scalar_1_0;

/// Initialize an uavcan_si_sample_velocity_Scalar_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_si_sample_velocity_Scalar_1_0_init(uavcan_si_sample_velocity_Scalar_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->meter_per_second = 0;
        uavcan_time_SynchronizedTimestamp_1_0_init(&(out_instance->timestamp));
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_si_sample_velocity_Scalar_1_0
/// instance.
#define uavcan_si_sample_velocity_Scalar_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (11U)


/// Serialization of uavcan_si_sample_velocity_Scalar_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_sample_velocity_Scalar_1_0_serialize(const uavcan_si_sample_velocity_Scalar_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32
    
        nunavutSetF32(out_buffer, offset, in_instance->meter_per_second);
        offset += 32;
    // End Structure: saturated float32
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

/// Deserialization of byte-array encoding into uavcan_si_sample_velocity_Scalar_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_si_sample_velocity_Scalar_1_0_deserialize(uavcan_si_sample_velocity_Scalar_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated float32
    out_instance->meter_per_second = nunavutGetF32(in_buffer, buf_size_bytes, offset);
    offset += 32;
    // End Structure: saturated float32
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
#endif /* UAVCAN_SI_SAMPLE_VELOCITY_SCALAR */
