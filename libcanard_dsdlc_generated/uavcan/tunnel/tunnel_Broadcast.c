/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/tunnel/2010.Broadcast.uavcan
 */
#include "uavcan/tunnel/Broadcast.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#define CANARD_INTERNAL_ENABLE_TAO  ((uint8_t) 1)
#define CANARD_INTERNAL_DISABLE_TAO ((uint8_t) 0)

/**
  * @brief uavcan_tunnel_Broadcast_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_tunnel_Broadcast_encode_internal(uavcan_tunnel_Broadcast* source, void* msg_buf, uint32_t offset, uint8_t root_item)
{
    uint32_t c = 0;

    // Compound
    offset = uavcan_tunnel_Protocol_encode_internal((void*)&source->protocol, msg_buf, offset, 0);
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->channel_id); // 255
    offset += 8;

    // Dynamic Array (buffer)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 6, (void*)&source->buffer.len);
        offset += 6;
    }

    // - Add array items
    for (c = 0; c < source->buffer.len; c++)
    {
        canardEncodeScalar(msg_buf, offset, 8, (void*)(source->buffer.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_tunnel_Broadcast_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_tunnel_Broadcast_encode(uavcan_tunnel_Broadcast* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_tunnel_Broadcast_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_tunnel_Broadcast_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_tunnel_Broadcast dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @param tao: is tail array optimization used
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_tunnel_Broadcast_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_tunnel_Broadcast* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Compound
    offset = uavcan_tunnel_Protocol_decode_internal(transfer, 0, (void*)&dest->protocol, dyn_arr_buf, offset, tao);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_tunnel_Broadcast_error_exit;
    }

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->channel_id);
    if (ret != 8)
    {
        goto uavcan_tunnel_Broadcast_error_exit;
    }
    offset += 8;

    // Dynamic Array (buffer)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao == CANARD_INTERNAL_ENABLE_TAO)
    {
        //  - Calculate Array length from MSG length
        dest->buffer.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 6 bits
        ret = canardDecodeScalar(transfer, offset, 6, false, (void*)&dest->buffer.len); // 255
        if (ret != 6)
        {
            goto uavcan_tunnel_Broadcast_error_exit;
        }
        offset += 6;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->buffer.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->buffer.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer, offset, 8, false, (void*)*dyn_arr_buf); // 255
            if (ret != 8)
            {
                goto uavcan_tunnel_Broadcast_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_tunnel_Broadcast_error_exit:
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
  * @brief uavcan_tunnel_Broadcast_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_tunnel_Broadcast dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_tunnel_Broadcast_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_tunnel_Broadcast* dest, uint8_t** dyn_arr_buf)
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
        for (uint32_t c = 0; c < sizeof(uavcan_tunnel_Broadcast); c++)
        {
            ((uint8_t*)dest)[c] = 0x00;
        }

        ret = uavcan_tunnel_Broadcast_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao);

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