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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/node/435.ExecuteCommand.1.0.uavcan
//
// Template:
// ServiceType.j2
//
// Generated at:  2020-08-21 01:54:39.894411 UTC
// Is deprecated: no
// Fixed port ID: 435
// Full name:     uavcan.node.ExecuteCommand
// Version:       1.0

#ifndef UAVCAN_NODE_EXECUTE_COMMAND_INCLUDED
#define UAVCAN_NODE_EXECUTE_COMMAND_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
// +------------------------------------------------------------------------------------------------------------------+
// | Begin service definitions for uavcan_node_ExecuteCommand_1_0
// +------------------------------------------------------------------------------------------------------------------+


#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_RESTART (65535)
#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_POWER_OFF (65534)
#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_BEGIN_SOFTWARE_UPDATE (65533)
#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_FACTORY_RESET (65532)
#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_EMERGENCY_STOP (65531)
#define uavcan_node_ExecuteCommand_1_0_Request_COMMAND_STORE_PERSISTENT_STATES (65530)

typedef struct
{
    uint16_t command;
    size_t parameter_length;
    uint8_t parameter[112];
} uavcan_node_ExecuteCommand_1_0_Request;

/// The maximum capacity of uavcan_node_ExecuteCommand_1_0_Request.parameter.
static inline size_t uavcan_node_ExecuteCommand_1_0_Request_parameter_array_capacity(void)
{
    return (112U);
}

/// If true then uavcan_node_ExecuteCommand_1_0_Request.parameter's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_ExecuteCommand_1_0_Request_parameter_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_node_ExecuteCommand_1_0_Request.parameter is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If parameter is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_ExecuteCommand_1_0_Request_parameter_array_length(
    const uavcan_node_ExecuteCommand_1_0_Request* const instance)
{
    return (instance == NULL) ? 0 : instance->parameter_length;
}

/// Initialize an uavcan_node_ExecuteCommand_1_0_Request instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_ExecuteCommand_1_0_Request_init(uavcan_node_ExecuteCommand_1_0_Request* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->command = 0;
        out_instance->parameter_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_ExecuteCommand_1_0_Request
/// instance.
#define uavcan_node_ExecuteCommand_1_0_Request_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (115U)


// +------------------------------------------------------------------------------------------------------------------+

#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_SUCCESS (0)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_FAILURE (1)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_NOT_AUTHORIZED (2)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_BAD_COMMAND (3)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_BAD_PARAMETER (4)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_BAD_STATE (5)
#define uavcan_node_ExecuteCommand_1_0_Response_STATUS_INTERNAL_ERROR (6)

typedef struct
{
    uint8_t status;
} uavcan_node_ExecuteCommand_1_0_Response;

/// Initialize an uavcan_node_ExecuteCommand_1_0_Response instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_ExecuteCommand_1_0_Response_init(uavcan_node_ExecuteCommand_1_0_Response* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->status = 0;
        /* Ignoring 48 padding bit(s). */
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_ExecuteCommand_1_0_Response
/// instance.
#define uavcan_node_ExecuteCommand_1_0_Response_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (7U)



/// uavcan_node_ExecuteCommand_1_0 can only be used with the fixed port identifier defined here.
#define uavcan_node_ExecuteCommand_1_0_FIXED_PORT_ID (435U)

/// Serialization of uavcan_node_ExecuteCommand_1_0_Request instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_ExecuteCommand_1_0_Request_serialize(const uavcan_node_ExecuteCommand_1_0_Request* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint16
    
        nunavutSetUxx(out_buffer, offset, in_instance->command, 16);
        offset += 16;
    // End Structure: saturated uint16
    // Begin Structure: saturated uint8[<=112]
    
        if (in_instance->parameter_length > 112)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->parameter_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->parameter, in_instance->parameter_length * 1);
        offset += in_instance->parameter_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_ExecuteCommand_1_0_Request instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_ExecuteCommand_1_0_Request_deserialize(uavcan_node_ExecuteCommand_1_0_Request* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint16
    out_instance->command = nunavutGetU16(in_buffer, buf_size_bytes, offset, 16);
    offset += 16;
    // End Structure: saturated uint16
    // Begin Structure: saturated uint8[<=112]
    
    out_instance->parameter_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->parameter_length > 112)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->parameter, (void*) in_buffer + (offset >> 3), out_instance->parameter_length * 1);
    offset += out_instance->parameter_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}


/// Serialization of uavcan_node_ExecuteCommand_1_0_Response instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_ExecuteCommand_1_0_Response_serialize(const uavcan_node_ExecuteCommand_1_0_Response* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8
    
        nunavutSetUxx(out_buffer, offset, in_instance->status, 8);
        offset += 8;
    // End Structure: saturated uint8
    // Begin Structure: void48
    offset += 48;
    // End Structure: void48

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_ExecuteCommand_1_0_Response instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_ExecuteCommand_1_0_Response_deserialize(uavcan_node_ExecuteCommand_1_0_Response* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8
    out_instance->status = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);
    offset += 8;
    // End Structure: saturated uint8
    // Begin Structure: void48
    offset += 48;
    // End Structure: void48

    return offset;
}


// +------------------------------------------------------------------------------------------------------------------+
// | End service definitions for uavcan_node_ExecuteCommand_1_0
// +------------------------------------------------------------------------------------------------------------------+

#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_NODE_EXECUTE_COMMAND */
