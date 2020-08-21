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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/node/430.GetInfo.1.0.uavcan
//
// Template:
// ServiceType.j2
//
// Generated at:  2020-08-21 01:54:40.033679 UTC
// Is deprecated: no
// Fixed port ID: 430
// Full name:     uavcan.node.GetInfo
// Version:       1.0

#ifndef UAVCAN_NODE_GET_INFO_INCLUDED
#define UAVCAN_NODE_GET_INFO_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/node/Version_1_0.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */
// +------------------------------------------------------------------------------------------------------------------+
// | Begin service definitions for uavcan_node_GetInfo_1_0
// +------------------------------------------------------------------------------------------------------------------+



typedef struct
{
    uint8_t _dummy_;
} uavcan_node_GetInfo_1_0_Request;

/// Initialize an uavcan_node_GetInfo_1_0_Request instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_GetInfo_1_0_Request_init(uavcan_node_GetInfo_1_0_Request* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->_dummy_ = 0U;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_GetInfo_1_0_Request
/// instance.
#define uavcan_node_GetInfo_1_0_Request_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (0U)


// +------------------------------------------------------------------------------------------------------------------+


typedef struct
{
    uavcan_node_Version_1_0 protocol_version;
    uavcan_node_Version_1_0 hardware_version;
    uavcan_node_Version_1_0 software_version;
    uint64_t software_vcs_revision_id;
    uint8_t unique_id[16];
    size_t name_length;
    uint8_t name[50];
    size_t software_image_crc_length;
    uint64_t software_image_crc[1];
    size_t certificate_of_authenticity_length;
    uint8_t certificate_of_authenticity[222];
} uavcan_node_GetInfo_1_0_Response;

/// The maximum capacity of uavcan_node_GetInfo_1_0_Response.unique_id.
static inline size_t uavcan_node_GetInfo_1_0_Response_unique_id_array_capacity(void)
{
    return (16U);
}

/// If true then uavcan_node_GetInfo_1_0_Response.unique_id's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_GetInfo_1_0_Response_unique_id_array_is_variable_length(void)
{
    return (false);
}

/// If uavcan_node_GetInfo_1_0_Response.unique_id is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If unique_id is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_GetInfo_1_0_Response_unique_id_array_length(
    const uavcan_node_GetInfo_1_0_Response* const instance)
{
    /* Not used for fixed arrays. */
    (void)instance;
    return (16U);
}

/// The maximum capacity of uavcan_node_GetInfo_1_0_Response.name.
static inline size_t uavcan_node_GetInfo_1_0_Response_name_array_capacity(void)
{
    return (50U);
}

/// If true then uavcan_node_GetInfo_1_0_Response.name's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_GetInfo_1_0_Response_name_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_node_GetInfo_1_0_Response.name is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If name is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_GetInfo_1_0_Response_name_array_length(
    const uavcan_node_GetInfo_1_0_Response* const instance)
{
    return (instance == NULL) ? 0 : instance->name_length;
}

/// The maximum capacity of uavcan_node_GetInfo_1_0_Response.software_image_crc.
static inline size_t uavcan_node_GetInfo_1_0_Response_software_image_crc_array_capacity(void)
{
    return (1U);
}

/// If true then uavcan_node_GetInfo_1_0_Response.software_image_crc's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_GetInfo_1_0_Response_software_image_crc_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_node_GetInfo_1_0_Response.software_image_crc is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If software_image_crc is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_GetInfo_1_0_Response_software_image_crc_array_length(
    const uavcan_node_GetInfo_1_0_Response* const instance)
{
    return (instance == NULL) ? 0 : instance->software_image_crc_length;
}

/// The maximum capacity of uavcan_node_GetInfo_1_0_Response.certificate_of_authenticity.
static inline size_t uavcan_node_GetInfo_1_0_Response_certificate_of_authenticity_array_capacity(void)
{
    return (222U);
}

/// If true then uavcan_node_GetInfo_1_0_Response.certificate_of_authenticity's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_node_GetInfo_1_0_Response_certificate_of_authenticity_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_node_GetInfo_1_0_Response.certificate_of_authenticity is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If certificate_of_authenticity is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_node_GetInfo_1_0_Response_certificate_of_authenticity_array_length(
    const uavcan_node_GetInfo_1_0_Response* const instance)
{
    return (instance == NULL) ? 0 : instance->certificate_of_authenticity_length;
}

/// Initialize an uavcan_node_GetInfo_1_0_Response instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_node_GetInfo_1_0_Response_init(uavcan_node_GetInfo_1_0_Response* const out_instance)
{
    if (out_instance != NULL)
    {
        uavcan_node_Version_1_0_init(&(out_instance->protocol_version));
        uavcan_node_Version_1_0_init(&(out_instance->hardware_version));
        uavcan_node_Version_1_0_init(&(out_instance->software_version));
        out_instance->software_vcs_revision_id = 0;
        memset(&(out_instance->unique_id[0]), 0, sizeof(uint8_t) * 16);
        out_instance->name_length = 0;
        out_instance->software_image_crc_length = 0;
        out_instance->certificate_of_authenticity_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_node_GetInfo_1_0_Response
/// instance.
#define uavcan_node_GetInfo_1_0_Response_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (313U)



/// uavcan_node_GetInfo_1_0 can only be used with the fixed port identifier defined here.
#define uavcan_node_GetInfo_1_0_FIXED_PORT_ID (430U)

/// Serialization of uavcan_node_GetInfo_1_0_Request instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_GetInfo_1_0_Request_serialize(const uavcan_node_GetInfo_1_0_Request* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_GetInfo_1_0_Request instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_GetInfo_1_0_Request_deserialize(uavcan_node_GetInfo_1_0_Request* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    

    return offset;
}


/// Serialization of uavcan_node_GetInfo_1_0_Response instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_GetInfo_1_0_Response_serialize(const uavcan_node_GetInfo_1_0_Response* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_serialize(&(in_instance->protocol_version), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_serialize(&(in_instance->hardware_version), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_serialize(&(in_instance->software_version), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: saturated uint64
    
        nunavutSetUxx(out_buffer, offset, in_instance->software_vcs_revision_id, 64);
        offset += 64;
    // End Structure: saturated uint64
    // Begin Structure: saturated uint8[16]
    
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->unique_id, in_instance->unique_id_length * 1);
        offset += in_instance->unique_id_length * 8;
    // End Structure: saturated uint8[16]
    // Begin Structure: saturated uint8[<=50]
    
        if (in_instance->name_length > 50)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->name_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->name, in_instance->name_length * 1);
        offset += in_instance->name_length * 8;
    // End Structure: saturated uint8[<=50]
    // Begin Structure: saturated uint64[<=1]
    
        if (in_instance->software_image_crc_length > 1)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->software_image_crc_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->software_image_crc, in_instance->software_image_crc_length * 8);
        offset += in_instance->software_image_crc_length * 64;
    // End Structure: saturated uint64[<=1]
    // Begin Structure: saturated uint8[<=222]
    
        if (in_instance->certificate_of_authenticity_length > 222)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->certificate_of_authenticity_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->certificate_of_authenticity, in_instance->certificate_of_authenticity_length * 1);
        offset += in_instance->certificate_of_authenticity_length * 8;
    // End Structure: saturated uint8[<=222]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_node_GetInfo_1_0_Response instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_node_GetInfo_1_0_Response_deserialize(uavcan_node_GetInfo_1_0_Response* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_deserialize(&(out_instance->protocol_version), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_deserialize(&(out_instance->hardware_version), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: uavcan.node.Version.1.0
    rc = uavcan_node_Version_1_0_deserialize(&(out_instance->software_version), offset, in_buffer, buf_size_bytes);
    if (rc < 0)
    {
        return rc;
    }
    offset = rc;
    // End Structure: uavcan.node.Version.1.0
    // Begin Structure: saturated uint64
    out_instance->software_vcs_revision_id = nunavutGetU64(in_buffer, buf_size_bytes, offset, 64);
    offset += 64;
    // End Structure: saturated uint64
    // Begin Structure: saturated uint8[16]
    
    memcpy((void*)out_instance->unique_id, (void*) in_buffer + (offset >> 3), out_instance->unique_id_length * 1);
    offset += out_instance->unique_id_length * 8;
    // End Structure: saturated uint8[16]
    // Begin Structure: saturated uint8[<=50]
    
    out_instance->name_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->name_length > 50)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->name, (void*) in_buffer + (offset >> 3), out_instance->name_length * 1);
    offset += out_instance->name_length * 8;
    // End Structure: saturated uint8[<=50]
    // Begin Structure: saturated uint64[<=1]
    
    out_instance->software_image_crc_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->software_image_crc_length > 1)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->software_image_crc, (void*) in_buffer + (offset >> 3), out_instance->software_image_crc_length * 8);
    offset += out_instance->software_image_crc_length * 64;
    // End Structure: saturated uint64[<=1]
    // Begin Structure: saturated uint8[<=222]
    
    out_instance->certificate_of_authenticity_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->certificate_of_authenticity_length > 222)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->certificate_of_authenticity, (void*) in_buffer + (offset >> 3), out_instance->certificate_of_authenticity_length * 1);
    offset += out_instance->certificate_of_authenticity_length * 8;
    // End Structure: saturated uint8[<=222]

    return offset;
}


// +------------------------------------------------------------------------------------------------------------------+
// | End service definitions for uavcan_node_GetInfo_1_0
// +------------------------------------------------------------------------------------------------------------------+

#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_NODE_GET_INFO */
