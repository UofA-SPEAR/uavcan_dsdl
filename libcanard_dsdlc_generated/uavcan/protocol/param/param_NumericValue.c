/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/param/NumericValue.uavcan
 */
#include "uavcan/protocol/param/NumericValue.h"
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
  * @brief uavcan_protocol_param_NumericValue_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_protocol_param_NumericValue_encode_internal(uavcan_protocol_param_NumericValue* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    // Max Union Tag Value
    CANARD_ASSERT(source->union_tag <= 2);

    // Union Tag 2 bits
    canardEncodeScalar(msg_buf, offset, 2, (void*)&source->union_tag); // 2 bits
    offset += 2;

    if (source->union_tag == 0) {
    // Compound
    offset = uavcan_protocol_param_Empty_encode_internal(&source->empty, msg_buf, offset, 0);
    }
    else if (source->union_tag == 1) {
    canardEncodeScalar(msg_buf, offset, 64, (void*)&source->integer_value); // 9223372036854775807
    offset += 64;

    }
    else if (source->union_tag == 2) {
    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->real_value); // 2147483647
    offset += 32;

    }

    return offset;
}

/**
  * @brief uavcan_protocol_param_NumericValue_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_param_NumericValue_encode(uavcan_protocol_param_NumericValue* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_param_NumericValue_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_param_NumericValue_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_NumericValue dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_NumericValue_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_param_NumericValue* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;

    // Get Union Tag
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 2, false, (void*)&dest->union_tag); // 2
    if (ret != 2)
    {
        goto uavcan_protocol_param_NumericValue_error_exit;
    }
    offset += 2;

    if (dest->union_tag == 0)
    {
    // Compound
    offset = uavcan_protocol_param_Empty_decode_internal(transfer, payload_len, &dest->empty, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_NumericValue_error_exit;
    }
    }
    else if (dest->union_tag == 1)
    {
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 64, true, (void*)&dest->integer_value);
    if (ret != 64)
    {
        goto uavcan_protocol_param_NumericValue_error_exit;
    }
    offset += 64;
    }
    else if (dest->union_tag == 2)
    {
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->real_value);
    if (ret != 32)
    {
        goto uavcan_protocol_param_NumericValue_error_exit;
    }
    offset += 32;
    }
    return offset;

uavcan_protocol_param_NumericValue_error_exit:
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
  * @brief uavcan_protocol_param_NumericValue_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_NumericValue dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_NumericValue_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_param_NumericValue* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_param_NumericValue); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_param_NumericValue_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
