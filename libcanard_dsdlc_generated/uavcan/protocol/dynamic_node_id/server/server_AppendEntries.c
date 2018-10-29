/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/dynamic_node_id/server/30.AppendEntries.uavcan
 */
#include "uavcan/protocol/dynamic_node_id/server/AppendEntries.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#define CANARD_INTERNAL_ENABLE_TAO  ((uint8_t) 1)
#define CANARD_INTERNAL_DISABLE_TAO ((uint8_t) 0)

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode_internal(uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item)
{
    uint32_t c = 0;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->term); // 4294967295
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->prev_log_term); // 4294967295
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->prev_log_index); // 255
    offset += 8;

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->leader_commit); // 255
    offset += 8;

    // Dynamic Array (entries)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 1, (void*)&source->entries.len);
        offset += 1;
    }

    // - Add array items
    for (c = 0; c < source->entries.len; c++)
    {
        offset += uavcan_protocol_dynamic_node_id_server_Entry_encode_internal((void*)&source->entries.data[c], msg_buf, offset, 0);
    }

    return offset;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode(uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @param tao: is tail array optimization used
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->term);
    if (ret != 32)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->prev_log_term);
    if (ret != 32)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->prev_log_index);
    if (ret != 8)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit;
    }
    offset += 8;

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->leader_commit);
    if (ret != 8)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit;
    }
    offset += 8;

    // Dynamic Array (entries)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao == CANARD_INTERNAL_ENABLE_TAO)
    {
        //  - Calculate Array length from MSG length
        dest->entries.len = ((payload_len * 8) - offset ) / 168; // 168 bit array item size
    }
    else
    {
        // - Array length 1 bits
        ret = canardDecodeScalar(transfer, offset, 1, false, (void*)&dest->entries.len); // 0
        if (ret != 1)
        {
            goto uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit;
        }
        offset += 1;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->entries.data = (uavcan_protocol_dynamic_node_id_server_Entry*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->entries.len; c++)
    {
        offset += uavcan_protocol_dynamic_node_id_server_Entry_decode_internal(transfer, 0, (void*)&dest->entries.data[c], dyn_arr_buf, offset, tao);
    }
    return offset;

uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_error_exit:
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
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest* dest, uint8_t** dyn_arr_buf)
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
        for (uint32_t c = 0; c < sizeof(uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest); c++)
        {
            ((uint8_t*)dest)[c] = 0x00;
        }

        ret = uavcan_protocol_dynamic_node_id_server_AppendEntriesRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao);

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

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode_internal(uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item)
{
    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->term); // 4294967295
    offset += 32;

    source->success = CANARD_INTERNAL_SATURATE(source->success, 0)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->success); // 0
    offset += 1;

    return offset;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode(uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @param tao: is tail array optimization used
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->term);
    if (ret != 32)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 1, false, (void*)&dest->success);
    if (ret != 1)
    {
        goto uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_error_exit;
    }
    offset += 1;
    return offset;

uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_error_exit:
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
  * @brief uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse* dest, uint8_t** dyn_arr_buf)
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
        for (uint32_t c = 0; c < sizeof(uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse); c++)
        {
            ((uint8_t*)dest)[c] = 0x00;
        }

        ret = uavcan_protocol_dynamic_node_id_server_AppendEntriesResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao);

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
