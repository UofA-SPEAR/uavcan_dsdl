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
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/metatransport/can/Manifestation.0.1.uavcan
//
// Template:
// UnionType.j2
//
// Generated at:  2020-08-21 01:54:42.003550 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.metatransport.can.Manifestation
// Version:       0.1

#ifndef UAVCAN_METATRANSPORT_CAN_MANIFESTATION_INCLUDED
#define UAVCAN_METATRANSPORT_CAN_MANIFESTATION_INCLUDED

#include <nunavut/support/nunavut.h>
#include <uavcan/metatransport/can/DataClassic_0_1.h>
#include <uavcan/metatransport/can/DataFD_0_1.h>
#include <uavcan/metatransport/can/Error_0_1.h>
#include <uavcan/metatransport/can/RTR_0_1.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


typedef struct
{    
    uint8_t _tag_;
    union
    {
        uavcan_metatransport_can_Error_0_1 _error;
        uavcan_metatransport_can_DataFD_0_1 data_fd;
        uavcan_metatransport_can_DataClassic_0_1 data_classic;
        uavcan_metatransport_can_RTR_0_1 remote_transmission_request;
    };
} uavcan_metatransport_can_Manifestation_0_1;

/// Initialize an uavcan_metatransport_can_Manifestation_0_1 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_metatransport_can_Manifestation_0_1_init(uavcan_metatransport_can_Manifestation_0_1* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->_tag_ = 0;
        uavcan_metatransport_can_Error_0_1_init(&(out_instance->_error));
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_metatransport_can_Manifestation_0_1
/// instance.
#define uavcan_metatransport_can_Manifestation_0_1_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (71U)


/// Determine if a given uavcan_metatransport_can_Manifestation_0_1 tagged union is currently tagged as
/// error. If so, then uavcan_metatransport_can_Manifestation_0_1->error
/// can be accessed safely.
static inline bool uavcan_metatransport_can_Manifestation_0_1_is_error(const uavcan_metatransport_can_Manifestation_0_1* const tagged_union_ptr)
{
    return ((tagged_union_ptr != NULL) && tagged_union_ptr->_tag_ == 0);
}

/// Determine if a given uavcan_metatransport_can_Manifestation_0_1 tagged union is currently tagged as
/// data_fd. If so, then uavcan_metatransport_can_Manifestation_0_1->data_fd
/// can be accessed safely.
static inline bool uavcan_metatransport_can_Manifestation_0_1_is_data_fd(const uavcan_metatransport_can_Manifestation_0_1* const tagged_union_ptr)
{
    return ((tagged_union_ptr != NULL) && tagged_union_ptr->_tag_ == 1);
}

/// Determine if a given uavcan_metatransport_can_Manifestation_0_1 tagged union is currently tagged as
/// data_classic. If so, then uavcan_metatransport_can_Manifestation_0_1->data_classic
/// can be accessed safely.
static inline bool uavcan_metatransport_can_Manifestation_0_1_is_data_classic(const uavcan_metatransport_can_Manifestation_0_1* const tagged_union_ptr)
{
    return ((tagged_union_ptr != NULL) && tagged_union_ptr->_tag_ == 2);
}

/// Determine if a given uavcan_metatransport_can_Manifestation_0_1 tagged union is currently tagged as
/// remote_transmission_request. If so, then uavcan_metatransport_can_Manifestation_0_1->remote_transmission_request
/// can be accessed safely.
static inline bool uavcan_metatransport_can_Manifestation_0_1_is_remote_transmission_request(const uavcan_metatransport_can_Manifestation_0_1* const tagged_union_ptr)
{
    return ((tagged_union_ptr != NULL) && tagged_union_ptr->_tag_ == 3);
}

/// Serialization of uavcan_metatransport_can_Manifestation_0_1 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_can_Manifestation_0_1_serialize(const uavcan_metatransport_can_Manifestation_0_1* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Union: uavcan_metatransport_can_Manifestation_0_1
    nunavutSetUxx(out_buffer, offset, in_instance->_tag_, 8);
    offset += 8;
    if (uavcan_metatransport_can_Manifestation_0_1_is_error(in_instance))
    {
        rc = uavcan_metatransport_can_Error_0_1_serialize(&(in_instance->_error), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_data_fd(in_instance))
    {
        rc = uavcan_metatransport_can_DataFD_0_1_serialize(&(in_instance->data_fd), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_data_classic(in_instance))
    {
        rc = uavcan_metatransport_can_DataClassic_0_1_serialize(&(in_instance->data_classic), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_remote_transmission_request(in_instance))
    {
        rc = uavcan_metatransport_can_RTR_0_1_serialize(&(in_instance->remote_transmission_request), offset, out_buffer);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else
    {
        return -NUNAVUT_ERR_INVALID_TAG;
    }
    // End Union: uavcan_metatransport_can_Manifestation_0_1

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_metatransport_can_Manifestation_0_1 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_metatransport_can_Manifestation_0_1_deserialize(uavcan_metatransport_can_Manifestation_0_1* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Union: uavcan.metatransport.can.Manifestation.0.1
    out_instance->_tag_ = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);
    offset += 8;
    if (uavcan_metatransport_can_Manifestation_0_1_is_error(out_instance))
    {
        rc = uavcan_metatransport_can_Error_0_1_deserialize(&(out_instance->_error), offset, in_buffer, buf_size_bytes);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_data_fd(out_instance))
    {
        rc = uavcan_metatransport_can_DataFD_0_1_deserialize(&(out_instance->data_fd), offset, in_buffer, buf_size_bytes);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_data_classic(out_instance))
    {
        rc = uavcan_metatransport_can_DataClassic_0_1_deserialize(&(out_instance->data_classic), offset, in_buffer, buf_size_bytes);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else if (uavcan_metatransport_can_Manifestation_0_1_is_remote_transmission_request(out_instance))
    {
        rc = uavcan_metatransport_can_RTR_0_1_deserialize(&(out_instance->remote_transmission_request), offset, in_buffer, buf_size_bytes);
        if (rc < 0)
        {
            return rc;
        }
        offset = rc;
    }
    else
    {
        return -NUNAVUT_ERR_INVALID_TAG;
    }
    // End Union: uavcan.metatransport.can.Manifestation.0.1

    return offset;
}



#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_METATRANSPORT_CAN_MANIFESTATION */
