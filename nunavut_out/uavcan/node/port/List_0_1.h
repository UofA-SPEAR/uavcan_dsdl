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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/node/port/431.List.0.1.uavcan
//
// Template:
// ServiceType.j2
//
// Generated at:  2020-08-21 01:54:40.966095 UTC
// Is deprecated: no
// Fixed port ID: 431
// Full name:     uavcan.node.port.List
// Version:       0.1

#ifndef UAVCAN_NODE_PORT_LIST_INCLUDED
#define UAVCAN_NODE_PORT_LIST_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/node/port/ID_1_0.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
// +------------------------------------------------------------------------------------------------------------------+
// | Begin service definitions for uavcan_node_port_List_0_1
// +------------------------------------------------------------------------------------------------------------------+



typedef struct
{
    uavcan_node_port_ID_1_0 port_id_lower_boundary;
} uavcan_node_port_List_0_1_Request;

/// Initialize an uavcan_node_port_List_0_1_Request instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_port_List_0_1_Request_init(uavcan_node_port_List_0_1_Request* const out_instance)
{
    if (out_instance != NULL)
    {
        uavcan_node_port_ID_1_0_init(&(out_instance->port_id_lower_boundary));
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_port_List_0_1_Request
/// instance.
#define uavcan_node_port_List_0_1_Request_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (3U)


// +------------------------------------------------------------------------------------------------------------------+


typedef struct
{
    size_t port_ids_length;
    uint16_t port_ids[128];
} uavcan_node_port_List_0_1_Response;

/// The maximum capacity of uavcan_node_port_List_0_1_Response.port_ids.
static inline size_t uavcan_node_port_List_0_1_Response_port_ids_array_capacity(void)
{
    return (128U);
}

/// If true then uavcan_node_port_List_0_1_Response.port_ids's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_port_List_0_1_Response_port_ids_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_node_port_List_0_1_Response.port_ids is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If port_ids is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_port_List_0_1_Response_port_ids_array_length(
    const uavcan_node_port_List_0_1_Response* const instance)
{
    return (instance == NULL) ? 0 : instance->port_ids_length;
}

/// Initialize an uavcan_node_port_List_0_1_Response instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_port_List_0_1_Response_init(uavcan_node_port_List_0_1_Response* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->port_ids_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_port_List_0_1_Response
/// instance.
#define uavcan_node_port_List_0_1_Response_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (257U)



/// uavcan_node_port_List_0_1 can only be used with the fixed port identifier defined here.
#define uavcan_node_port_List_0_1_FIXED_PORT_ID (431U)

/// Serialization of uavcan_node_port_List_0_1_Request instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_port_List_0_1_Request_serialize(const uavcan_node_port_List_0_1_Request* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.node.port.ID.1.0
    rc = uavcan_node_port_ID_1_0_serialize(&(in_instance->port_id_lower_boundary), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.node.port.ID.1.0

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_port_List_0_1_Request instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_port_List_0_1_Request_deserialize(uavcan_node_port_List_0_1_Request* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.node.port.ID.1.0
    rc = uavcan_node_port_ID_1_0_deserialize(&(out_instance->port_id_lower_boundary), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.node.port.ID.1.0

    return offset;
}


/// Serialization of uavcan_node_port_List_0_1_Response instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_port_List_0_1_Response_serialize(const uavcan_node_port_List_0_1_Response* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint16[<=128]
    
        if (in_instance->port_ids_length > 128)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->port_ids_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->port_ids, in_instance->port_ids_length * 2);
        offset += in_instance->port_ids_length * 16;
    // End Structure: saturated uint16[<=128]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_port_List_0_1_Response instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_port_List_0_1_Response_deserialize(uavcan_node_port_List_0_1_Response* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint16[<=128]
    
    out_instance->port_ids_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->port_ids_length > 128)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->port_ids, (void*) in_buffer + (offset >> 3), out_instance->port_ids_length * 2);
    offset += out_instance->port_ids_length * 16;
    // End Structure: saturated uint16[<=128]

    return offset;
}


// +------------------------------------------------------------------------------------------------------------------+
// | End service definitions for uavcan_node_port_List_0_1
// +------------------------------------------------------------------------------------------------------------------+

#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_NODE_PORT_LIST */
