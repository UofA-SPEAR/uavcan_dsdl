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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/metatransport/can/DataFD.0.1.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:41.720545 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.metatransport.can.DataFD
// Version:       0.1

#ifndef UAVCAN_METATRANSPORT_CAN_DATA_FD_INCLUDED
#define UAVCAN_METATRANSPORT_CAN_DATA_FD_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/metatransport/can/ArbitrationID_0_1.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    uavcan_metatransport_can_ArbitrationID_0_1 arbitration_id;
    size_t data_length;
    uint8_t data[64];
} uavcan_metatransport_can_DataFD_0_1;

/// The maximum capacity of uavcan_metatransport_can_DataFD_0_1.data.
static inline size_t uavcan_metatransport_can_DataFD_0_1_data_array_capacity(void)
{
    return (64U);
}

/// If true then uavcan_metatransport_can_DataFD_0_1.data's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_metatransport_can_DataFD_0_1_data_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_metatransport_can_DataFD_0_1.data is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If data is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_metatransport_can_DataFD_0_1_data_array_length(
    const uavcan_metatransport_can_DataFD_0_1* const instance)
{
    return (instance == NULL) ? 0 : instance->data_length;
}

/// Initialize an uavcan_metatransport_can_DataFD_0_1 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_metatransport_can_DataFD_0_1_init(uavcan_metatransport_can_DataFD_0_1* const out_instance)
{
    if (out_instance != NULL)
    {
        uavcan_metatransport_can_ArbitrationID_0_1_init(&(out_instance->arbitration_id));
        out_instance->data_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_metatransport_can_DataFD_0_1
/// instance.
#define uavcan_metatransport_can_DataFD_0_1_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (70U)


/// Serialization of uavcan_metatransport_can_DataFD_0_1 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_can_DataFD_0_1_serialize(const uavcan_metatransport_can_DataFD_0_1* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.metatransport.can.ArbitrationID.0.1
    rc = uavcan_metatransport_can_ArbitrationID_0_1_serialize(&(in_instance->arbitration_id), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.metatransport.can.ArbitrationID.0.1
    // Begin Structure: saturated uint8[<=64]
    
        if (in_instance->data_length > 64)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->data_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->data, in_instance->data_length * 1);
        offset += in_instance->data_length * 8;
    // End Structure: saturated uint8[<=64]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_metatransport_can_DataFD_0_1 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_can_DataFD_0_1_deserialize(uavcan_metatransport_can_DataFD_0_1* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.metatransport.can.ArbitrationID.0.1
    rc = uavcan_metatransport_can_ArbitrationID_0_1_deserialize(&(out_instance->arbitration_id), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.metatransport.can.ArbitrationID.0.1
    // Begin Structure: saturated uint8[<=64]
    
    out_instance->data_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->data_length > 64)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->data, (void*) in_buffer + (offset >> 3), out_instance->data_length * 1);
    offset += out_instance->data_length * 8;
    // End Structure: saturated uint8[<=64]

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_METATRANSPORT_CAN_DATA_FD */
