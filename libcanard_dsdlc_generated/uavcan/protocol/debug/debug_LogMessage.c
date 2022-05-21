/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/embedded/common/uavcan_dsdl/uavcan_dsdl/uavcan/protocol/debug/16383.LogMessage.uavcan
 */
#include "uavcan/protocol/debug/LogMessage.h"
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
  * @brief uavcan_protocol_debug_LogMessage_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_protocol_debug_LogMessage_encode_internal(uavcan_protocol_debug_LogMessage* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    uint32_t c = 0;

    // Compound
    offset = uavcan_protocol_debug_LogLevel_encode_internal(&source->level, msg_buf, offset, 0);

    // Dynamic Array (source)
    // - Add array length
    canardEncodeScalar(msg_buf, offset, 5, (void*)&source->source.len);
    offset += 5;

    // - Add array items
    for (c = 0; c < source->source.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->source.data + c));// 255
        offset += 8;
    }

    // Dynamic Array (text)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 7, (void*)&source->text.len);
        offset += 7;
    }

    // - Add array items
    for (c = 0; c < source->text.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->text.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_debug_LogMessage_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_debug_LogMessage_encode(uavcan_protocol_debug_LogMessage* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_debug_LogMessage_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_debug_LogMessage_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_debug_LogMessage dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_protocol_debug_LogMessage_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_debug_LogMessage* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Compound
    offset = uavcan_protocol_debug_LogLevel_decode_internal(transfer, payload_len, &dest->level, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_debug_LogMessage_error_exit;
    }

    // Dynamic Array (source)
    //  - Array length, not last item 5 bits
    ret = canardDecodeScalar(transfer,
                             (uint32_t)offset,
                             5,
                             false,
                             (void*)&dest->source.len); // 255
    if (ret != 5)
    {
        goto uavcan_protocol_debug_LogMessage_error_exit;
    }
    offset += 5;

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->source.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->source.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     8,
                                     false,
                                     (void*)*dyn_arr_buf); // 255
            if (ret != 8)
            {
                goto uavcan_protocol_debug_LogMessage_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }

    // Dynamic Array (text)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len)
    {
        //  - Calculate Array length from MSG length
        dest->text.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 7 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 7,
                                 false,
                                 (void*)&dest->text.len); // 255
        if (ret != 7)
        {
            goto uavcan_protocol_debug_LogMessage_error_exit;
        }
        offset += 7;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->text.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->text.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     8,
                                     false,
                                     (void*)*dyn_arr_buf); // 255
            if (ret != 8)
            {
                goto uavcan_protocol_debug_LogMessage_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_debug_LogMessage_error_exit:
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
  * @brief uavcan_protocol_debug_LogMessage_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_debug_LogMessage dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_debug_LogMessage_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_debug_LogMessage* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_debug_LogMessage); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_debug_LogMessage_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}