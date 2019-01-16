/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/spear/general/20200.PpmMessage.uavcan
 */
#include "spear/general/PpmMessage.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#define CANARD_INTERNAL_ENABLE_TAO  ((uint8_t) 1)
#define CANARD_INTERNAL_DISABLE_TAO ((uint8_t) 0)

/**
  * @brief spear_general_PpmMessage_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t spear_general_PpmMessage_encode_internal(spear_general_PpmMessage* source, void* msg_buf, uint32_t offset, uint8_t root_item)
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->channel_num);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->channel_num;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief spear_general_PpmMessage_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t spear_general_PpmMessage_encode(spear_general_PpmMessage* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = spear_general_PpmMessage_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief spear_general_PpmMessage_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     spear_general_PpmMessage dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @param tao: is tail array optimization used
  * @retval offset or ERROR value if < 0
  */
int32_t spear_general_PpmMessage_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, spear_general_PpmMessage* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao)
{
    int32_t ret = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto spear_general_PpmMessage_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->channel_num = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->channel_num = (float)tmp_float;
#endif
    offset += 16;
    return offset;

spear_general_PpmMessage_error_exit:
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
  * @brief spear_general_PpmMessage_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     spear_general_PpmMessage dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t spear_general_PpmMessage_decode(const CanardRxTransfer* transfer, uint16_t payload_len, spear_general_PpmMessage* dest, uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    /* Backward compatibility support for removing TAO
     *  - first try to decode with TAO DISABLED
     *  - if it fails fall back to TAO ENABLED
     */
    uint8_t tao = CANARD_INTERNAL_DISABLE_TAO;

    while (1)
    {
        // Clear the destination struct
        for (uint32_t c = 0; c < sizeof(spear_general_PpmMessage); c++)
        {
            ((uint8_t*)dest)[c] = 0x00;
        }

        ret = spear_general_PpmMessage_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao);

        if (ret >= 0)
        {
            break;
        }

        if (tao == CANARD_INTERNAL_ENABLE_TAO)
        {
            break;
        }
        tao = CANARD_INTERNAL_ENABLE_TAO;
    }

    return ret;
}