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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/diagnostic/32760.Record.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:39.749232 UTC
// Is deprecated: no
// Fixed port ID: 32760
// Full name:     uavcan.diagnostic.Record
// Version:       1.0

#ifndef UAVCAN_DIAGNOSTIC_RECORD_INCLUDED
#define UAVCAN_DIAGNOSTIC_RECORD_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/diagnostic/Severity_1_0.h>
#include <uavcan/time/SynchronizedTimestamp_1_0.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    uavcan_time_SynchronizedTimestamp_1_0 timestamp;
    uavcan_diagnostic_Severity_1_0 severity;
    size_t text_length;
    uint8_t text[112];
} uavcan_diagnostic_Record_1_0;

/// The maximum capacity of uavcan_diagnostic_Record_1_0.text.
static inline size_t uavcan_diagnostic_Record_1_0_text_array_capacity(void)
{
    return (112U);
}

/// If true then uavcan_diagnostic_Record_1_0.text's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_diagnostic_Record_1_0_text_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_diagnostic_Record_1_0.text is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If text is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_diagnostic_Record_1_0_text_array_length(
    const uavcan_diagnostic_Record_1_0* const instance)
{
    return (instance == NULL) ? 0 : instance->text_length;
}

/// Initialize an uavcan_diagnostic_Record_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_diagnostic_Record_1_0_init(uavcan_diagnostic_Record_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        uavcan_time_SynchronizedTimestamp_1_0_init(&(out_instance->timestamp));
        uavcan_diagnostic_Severity_1_0_init(&(out_instance->severity));
        out_instance->text_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_diagnostic_Record_1_0
/// instance.
#define uavcan_diagnostic_Record_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (121U)



/// uavcan_diagnostic_Record_1_0 can only be used with the fixed port identifier defined here.
#define uavcan_diagnostic_Record_1_0_FIXED_PORT_ID (32760U)
/// Serialization of uavcan_diagnostic_Record_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_diagnostic_Record_1_0_serialize(const uavcan_diagnostic_Record_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.time.SynchronizedTimestamp.1.0
    rc = uavcan_time_SynchronizedTimestamp_1_0_serialize(&(in_instance->timestamp), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.time.SynchronizedTimestamp.1.0
    // Begin Structure: uavcan.diagnostic.Severity.1.0
    rc = uavcan_diagnostic_Severity_1_0_serialize(&(in_instance->severity), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.diagnostic.Severity.1.0
    // Begin Structure: saturated uint8[<=112]
    
        if (in_instance->text_length > 112)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->text_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->text, in_instance->text_length * 1);
        offset += in_instance->text_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_diagnostic_Record_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_diagnostic_Record_1_0_deserialize(uavcan_diagnostic_Record_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.time.SynchronizedTimestamp.1.0
    rc = uavcan_time_SynchronizedTimestamp_1_0_deserialize(&(out_instance->timestamp), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.time.SynchronizedTimestamp.1.0
    // Begin Structure: uavcan.diagnostic.Severity.1.0
    rc = uavcan_diagnostic_Severity_1_0_deserialize(&(out_instance->severity), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.diagnostic.Severity.1.0
    // Begin Structure: saturated uint8[<=112]
    
    out_instance->text_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->text_length > 112)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->text, (void*) in_buffer + (offset >> 3), out_instance->text_length * 1);
    offset += out_instance->text_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_DIAGNOSTIC_RECORD */
