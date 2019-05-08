/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/4.GetTransportStats.uavcan
 */
#include "uavcan/protocol/GetTransportStats.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#ifndef CANARD_INTERNAL_SATURATE_UNSIGNED
#define CANARD_INTERNAL_SATURATE_UNSIGNED(x, max) ( ((x) >= max) ? max : (x) );
#endif

#if defined(__GNUC__)
# define CANARD_MAYBE_UNUSED(x) x __attribute__((unused))
#else
# define CANARD_MAYBE_UNUSED(x) x
#endif

uint32_t uavcan_protocol_GetTransportStatsRequest_encode_internal(uavcan_protocol_GetTransportStatsRequest* CANARD_MAYBE_UNUSED(source),
  void* CANARD_MAYBE_UNUSED(msg_buf),
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    return offset;
}

uint32_t uavcan_protocol_GetTransportStatsRequest_encode(uavcan_protocol_GetTransportStatsRequest* CANARD_MAYBE_UNUSED(source), void* CANARD_MAYBE_UNUSED(msg_buf))
{
    return 0;
}

int32_t uavcan_protocol_GetTransportStatsRequest_decode_internal(const CanardRxTransfer* CANARD_MAYBE_UNUSED(transfer),
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_GetTransportStatsRequest* CANARD_MAYBE_UNUSED(dest),
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    return offset;
}

int32_t uavcan_protocol_GetTransportStatsRequest_decode(const CanardRxTransfer* CANARD_MAYBE_UNUSED(transfer),
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_GetTransportStatsRequest* CANARD_MAYBE_UNUSED(dest),
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf))
{
    return 0;
}

/**
  * @brief uavcan_protocol_GetTransportStatsResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_protocol_GetTransportStatsResponse_encode_internal(uavcan_protocol_GetTransportStatsResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    uint32_t c = 0;

    source->transfers_tx = CANARD_INTERNAL_SATURATE_UNSIGNED(source->transfers_tx, 281474976710655)
    canardEncodeScalar(msg_buf, offset, 48, (void*)&source->transfers_tx); // 281474976710655
    offset += 48;

    source->transfers_rx = CANARD_INTERNAL_SATURATE_UNSIGNED(source->transfers_rx, 281474976710655)
    canardEncodeScalar(msg_buf, offset, 48, (void*)&source->transfers_rx); // 281474976710655
    offset += 48;

    source->transfer_errors = CANARD_INTERNAL_SATURATE_UNSIGNED(source->transfer_errors, 281474976710655)
    canardEncodeScalar(msg_buf, offset, 48, (void*)&source->transfer_errors); // 281474976710655
    offset += 48;

    // Dynamic Array (can_iface_stats)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 2, (void*)&source->can_iface_stats.len);
        offset += 2;
    }

    // - Add array items
    for (c = 0; c < source->can_iface_stats.len; c++)
    {
        offset = uavcan_protocol_CANIfaceStats_encode_internal((void*)&source->can_iface_stats.data[c], msg_buf, offset, 0);
    }

    return offset;
}

/**
  * @brief uavcan_protocol_GetTransportStatsResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_GetTransportStatsResponse_encode(uavcan_protocol_GetTransportStatsResponse* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_GetTransportStatsResponse_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_GetTransportStatsResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_GetTransportStatsResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_protocol_GetTransportStatsResponse_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_GetTransportStatsResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 48, false, (void*)&dest->transfers_tx);
    if (ret != 48)
    {
        goto uavcan_protocol_GetTransportStatsResponse_error_exit;
    }
    offset += 48;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 48, false, (void*)&dest->transfers_rx);
    if (ret != 48)
    {
        goto uavcan_protocol_GetTransportStatsResponse_error_exit;
    }
    offset += 48;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 48, false, (void*)&dest->transfer_errors);
    if (ret != 48)
    {
        goto uavcan_protocol_GetTransportStatsResponse_error_exit;
    }
    offset += 48;

    // Dynamic Array (can_iface_stats)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len)
    {
        //  - Calculate Array length from MSG length
        dest->can_iface_stats.len = ((payload_len * 8) - offset ) / 144; // 144 bit array item size
    }
    else
    {
        // - Array length 2 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 2,
                                 false,
                                 (void*)&dest->can_iface_stats.len); // 0
        if (ret != 2)
        {
            goto uavcan_protocol_GetTransportStatsResponse_error_exit;
        }
        offset += 2;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->can_iface_stats.data = (uavcan_protocol_CANIfaceStats*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->can_iface_stats.len; c++)
    {
        offset = uavcan_protocol_CANIfaceStats_decode_internal(transfer,
                                                0,
                                                (void*)&dest->can_iface_stats.data[c],
                                                dyn_arr_buf,
                                                offset);
    }
    return offset;

uavcan_protocol_GetTransportStatsResponse_error_exit:
    if (ret < 0)
    {
        return ret;
    }
    else
    {
        return -CANARD_ERROR_INTERNAL;
    }
}

/**
  * @brief uavcan_protocol_GetTransportStatsResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_GetTransportStatsResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_GetTransportStatsResponse_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_GetTransportStatsResponse* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_GetTransportStatsResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_GetTransportStatsResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
