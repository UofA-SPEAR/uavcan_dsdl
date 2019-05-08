/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/embedded/common/uavcan_dsdl/uavcan_dsdl/uavcan/protocol/5.RestartNode.uavcan
 */
#include "uavcan/protocol/RestartNode.h"
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

/**
  * @brief uavcan_protocol_RestartNodeRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_protocol_RestartNodeRequest_encode_internal(uavcan_protocol_RestartNodeRequest* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    source->magic_number = CANARD_INTERNAL_SATURATE_UNSIGNED(source->magic_number, 1099511627775)
    canardEncodeScalar(msg_buf, offset, 40, (void*)&source->magic_number); // 1099511627775
    offset += 40;

    return offset;
}

/**
  * @brief uavcan_protocol_RestartNodeRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_RestartNodeRequest_encode(uavcan_protocol_RestartNodeRequest* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_RestartNodeRequest_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_RestartNodeRequest_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeRequest_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_RestartNodeRequest* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 40, false, (void*)&dest->magic_number);
    if (ret != 40)
    {
        goto uavcan_protocol_RestartNodeRequest_error_exit;
    }
    offset += 40;
    return offset;

uavcan_protocol_RestartNodeRequest_error_exit:
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
  * @brief uavcan_protocol_RestartNodeRequest_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeRequest_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_RestartNodeRequest* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_RestartNodeRequest); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_RestartNodeRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_protocol_RestartNodeResponse_encode_internal(uavcan_protocol_RestartNodeResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    source->ok = CANARD_INTERNAL_SATURATE_UNSIGNED(source->ok, 1)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->ok); // 1
    offset += 1;

    return offset;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_RestartNodeResponse_encode(uavcan_protocol_RestartNodeResponse* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_RestartNodeResponse_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_RestartNodeResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeResponse_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_RestartNodeResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 1, false, (void*)&dest->ok);
    if (ret != 1)
    {
        goto uavcan_protocol_RestartNodeResponse_error_exit;
    }
    offset += 1;
    return offset;

uavcan_protocol_RestartNodeResponse_error_exit:
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
  * @brief uavcan_protocol_RestartNodeResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_RestartNodeResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_RestartNodeResponse_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_RestartNodeResponse* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_RestartNodeResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_RestartNodeResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
