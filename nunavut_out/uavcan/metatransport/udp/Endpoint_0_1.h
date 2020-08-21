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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/metatransport/udp/Endpoint.0.1.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:41.243974 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.metatransport.udp.Endpoint
// Version:       0.1

#ifndef UAVCAN_METATRANSPORT_UDP_ENDPOINT_INCLUDED
#define UAVCAN_METATRANSPORT_UDP_ENDPOINT_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{
    uint8_t ip_address[16];
    uint8_t mac_address[6];
    uint16_t port;
} uavcan_metatransport_udp_Endpoint_0_1;

/// The maximum capacity of uavcan_metatransport_udp_Endpoint_0_1.ip_address.
static inline size_t uavcan_metatransport_udp_Endpoint_0_1_ip_address_array_capacity(void)
{
    return (16U);
}

/// If true then uavcan_metatransport_udp_Endpoint_0_1.ip_address's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_metatransport_udp_Endpoint_0_1_ip_address_array_is_variable_length(void)
{
    return (false);
}

/// If uavcan_metatransport_udp_Endpoint_0_1.ip_address is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If ip_address is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_metatransport_udp_Endpoint_0_1_ip_address_array_length(
    const uavcan_metatransport_udp_Endpoint_0_1* const instance)
{
    /* Not used for fixed arrays. */
    (void)instance;
    return (16U);
}

/// The maximum capacity of uavcan_metatransport_udp_Endpoint_0_1.mac_address.
static inline size_t uavcan_metatransport_udp_Endpoint_0_1_mac_address_array_capacity(void)
{
    return (6U);
}

/// If true then uavcan_metatransport_udp_Endpoint_0_1.mac_address's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_metatransport_udp_Endpoint_0_1_mac_address_array_is_variable_length(void)
{
    return (false);
}

/// If uavcan_metatransport_udp_Endpoint_0_1.mac_address is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If mac_address is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_metatransport_udp_Endpoint_0_1_mac_address_array_length(
    const uavcan_metatransport_udp_Endpoint_0_1* const instance)
{
    /* Not used for fixed arrays. */
    (void)instance;
    return (6U);
}

/// Initialize an uavcan_metatransport_udp_Endpoint_0_1 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_metatransport_udp_Endpoint_0_1_init(uavcan_metatransport_udp_Endpoint_0_1* const out_instance)
{
    if (out_instance != NULL)
    {
        memset(&(out_instance->ip_address[0]), 0, sizeof(uint8_t) * 16);
        memset(&(out_instance->mac_address[0]), 0, sizeof(uint8_t) * 6);
        out_instance->port = 0;
        /* Ignoring 64 padding bit(s). */
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_metatransport_udp_Endpoint_0_1
/// instance.
#define uavcan_metatransport_udp_Endpoint_0_1_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (32U)


/// Serialization of uavcan_metatransport_udp_Endpoint_0_1 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_udp_Endpoint_0_1_serialize(const uavcan_metatransport_udp_Endpoint_0_1* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8[16]
    
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->ip_address, in_instance->ip_address_length * 1);
        offset += in_instance->ip_address_length * 8;
    // End Structure: saturated uint8[16]
    // Begin Structure: saturated uint8[6]
    
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->mac_address, in_instance->mac_address_length * 1);
        offset += in_instance->mac_address_length * 8;
    // End Structure: saturated uint8[6]
    // Begin Structure: saturated uint16
    
        nunavutSetUxx(out_buffer, offset, in_instance->port, 16);
        offset += 16;
    // End Structure: saturated uint16
    // Begin Structure: void64
    offset += 64;
    // End Structure: void64

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_metatransport_udp_Endpoint_0_1 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_udp_Endpoint_0_1_deserialize(uavcan_metatransport_udp_Endpoint_0_1* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8[16]
    
    memcpy((void*)out_instance->ip_address, (void*) in_buffer + (offset >> 3), out_instance->ip_address_length * 1);
    offset += out_instance->ip_address_length * 8;
    // End Structure: saturated uint8[16]
    // Begin Structure: saturated uint8[6]
    
    memcpy((void*)out_instance->mac_address, (void*) in_buffer + (offset >> 3), out_instance->mac_address_length * 1);
    offset += out_instance->mac_address_length * 8;
    // End Structure: saturated uint8[6]
    // Begin Structure: saturated uint16
    out_instance->port = nunavutGetU16(in_buffer, buf_size_bytes, offset, 16);
    offset += 16;
    // End Structure: saturated uint16
    // Begin Structure: void64
    offset += 64;
    // End Structure: void64

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_METATRANSPORT_UDP_ENDPOINT */