/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/navigation/2000.GlobalNavigationSolution.uavcan
 */
#include "uavcan/navigation/GlobalNavigationSolution.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#define CANARD_INTERNAL_ENABLE_TAO  ((uint8_t) 1)
#define CANARD_INTERNAL_DISABLE_TAO ((uint8_t) 0)

/**
  * @brief uavcan_navigation_GlobalNavigationSolution_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_navigation_GlobalNavigationSolution_encode_internal(uavcan_navigation_GlobalNavigationSolution* source, void* msg_buf, uint32_t offset, uint8_t root_item)
{
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_encode_internal((void*)&source->timestamp, msg_buf, offset, 0);
    canardEncodeScalar(msg_buf, offset, 64, (void*)&source->longitude); // 9223372036854775807
    offset += 64;

    canardEncodeScalar(msg_buf, offset, 64, (void*)&source->latitude); // 9223372036854775807
    offset += 64;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->height_ellipsoid); // 2147483647
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->height_msl); // 2147483647
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->height_agl); // 2147483647
    offset += 32;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->height_baro); // 2147483647
    offset += 32;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->qnh_hpa);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->qnh_hpa;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;
    // Static array (orientation_xyzw)
    for (c = 0; c < 4; c++)
    {
        canardEncodeScalar(msg_buf, offset, 32, (void*)(source->orientation_xyzw + c)); // 2147483647
        offset += 32;
    }

    // Dynamic Array (pose_covariance)
    // - Add array length
    canardEncodeScalar(msg_buf, offset, 6, (void*)&source->pose_covariance.len);
    offset += 6;

    // - Add array items
    for (c = 0; c < source->pose_covariance.len; c++)
    {
        canardEncodeScalar(msg_buf, offset, 16, (void*)(source->pose_covariance.data + c));// 32767
        offset += 16;
    }

    // Static array (linear_velocity_body)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 32, (void*)(source->linear_velocity_body + c)); // 2147483647
        offset += 32;
    }

    // Static array (angular_velocity_body)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 32, (void*)(source->angular_velocity_body + c)); // 2147483647
        offset += 32;
    }

    // Static array (linear_acceleration_body)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 16, (void*)(source->linear_acceleration_body + c)); // 32767
        offset += 16;
    }

    // Dynamic Array (velocity_covariance)
    if (! root_item)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 6, (void*)&source->velocity_covariance.len);
        offset += 6;
    }

    // - Add array items
    for (c = 0; c < source->velocity_covariance.len; c++)
    {
        canardEncodeScalar(msg_buf, offset, 16, (void*)(source->velocity_covariance.data + c));// 32767
        offset += 16;
    }

    return offset;
}

/**
  * @brief uavcan_navigation_GlobalNavigationSolution_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_navigation_GlobalNavigationSolution_encode(uavcan_navigation_GlobalNavigationSolution* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_navigation_GlobalNavigationSolution_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_navigation_GlobalNavigationSolution_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_navigation_GlobalNavigationSolution dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @param tao: is tail array optimization used
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_navigation_GlobalNavigationSolution_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_navigation_GlobalNavigationSolution* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao)
{
    int32_t ret = 0;
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_decode_internal(transfer, 0, (void*)&dest->timestamp, dyn_arr_buf, offset, tao);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }

    ret = canardDecodeScalar(transfer, offset, 64, false, (void*)&dest->longitude);
    if (ret != 64)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 64;

    ret = canardDecodeScalar(transfer, offset, 64, false, (void*)&dest->latitude);
    if (ret != 64)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 64;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->height_ellipsoid);
    if (ret != 32)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->height_msl);
    if (ret != 32)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->height_agl);
    if (ret != 32)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 32;

    ret = canardDecodeScalar(transfer, offset, 32, false, (void*)&dest->height_baro);
    if (ret != 32)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 32;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->qnh_hpa = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->qnh_hpa = (float)tmp_float;
#endif
    offset += 16;

    // Static array (orientation_xyzw)
    for (c = 0; c < 4; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 32, false, (void*)(dest->orientation_xyzw + c));
        if (ret != 32)
        {
            goto uavcan_navigation_GlobalNavigationSolution_error_exit;
        }
        offset += 32;
    }

    // Dynamic Array (pose_covariance)
    //  - Array length, not last item 6 bits
    ret = canardDecodeScalar(transfer, offset, 6, false, (void*)&dest->pose_covariance.len); // 32767
    if (ret != 6)
    {
        goto uavcan_navigation_GlobalNavigationSolution_error_exit;
    }
    offset += 6;

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->pose_covariance.data = (float*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->pose_covariance.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer, offset, 16, false, (void*)*dyn_arr_buf); // 32767
            if (ret != 16)
            {
                goto uavcan_navigation_GlobalNavigationSolution_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((float*)*dyn_arr_buf) + 1);
        }
        offset += 16;
    }

    // Static array (linear_velocity_body)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 32, false, (void*)(dest->linear_velocity_body + c));
        if (ret != 32)
        {
            goto uavcan_navigation_GlobalNavigationSolution_error_exit;
        }
        offset += 32;
    }

    // Static array (angular_velocity_body)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 32, false, (void*)(dest->angular_velocity_body + c));
        if (ret != 32)
        {
            goto uavcan_navigation_GlobalNavigationSolution_error_exit;
        }
        offset += 32;
    }

    // Static array (linear_acceleration_body)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, offset, 16, false, (void*)(dest->linear_acceleration_body + c));
        if (ret != 16)
        {
            goto uavcan_navigation_GlobalNavigationSolution_error_exit;
        }
        offset += 16;
    }

    // Dynamic Array (velocity_covariance)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao == CANARD_INTERNAL_ENABLE_TAO)
    {
        //  - Calculate Array length from MSG length
        dest->velocity_covariance.len = ((payload_len * 8) - offset ) / 16; // 16 bit array item size
    }
    else
    {
        // - Array length 6 bits
        ret = canardDecodeScalar(transfer, offset, 6, false, (void*)&dest->velocity_covariance.len); // 32767
        if (ret != 6)
        {
            goto uavcan_navigation_GlobalNavigationSolution_error_exit;
        }
        offset += 6;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->velocity_covariance.data = (float*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->velocity_covariance.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer, offset, 16, false, (void*)*dyn_arr_buf); // 32767
            if (ret != 16)
            {
                goto uavcan_navigation_GlobalNavigationSolution_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((float*)*dyn_arr_buf) + 1);
        }
        offset += 16;
    }
    return offset;

uavcan_navigation_GlobalNavigationSolution_error_exit:
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
  * @brief uavcan_navigation_GlobalNavigationSolution_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_navigation_GlobalNavigationSolution dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_navigation_GlobalNavigationSolution_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_navigation_GlobalNavigationSolution* dest, uint8_t** dyn_arr_buf)
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
        for (uint32_t c = 0; c < sizeof(uavcan_navigation_GlobalNavigationSolution); c++)
        {
            ((uint8_t*)dest)[c] = 0x00;
        }

        ret = uavcan_navigation_GlobalNavigationSolution_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao);

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
