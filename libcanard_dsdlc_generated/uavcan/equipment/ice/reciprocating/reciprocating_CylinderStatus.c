/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/ice/reciprocating/CylinderStatus.uavcan
 */
#include "uavcan/equipment/ice/reciprocating/CylinderStatus.h"
#include "canard.h"

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#ifndef CANARD_INTERNAL_SATURATE_UNSIGNED
#define CANARD_INTERNAL_SATURATE_UNSIGNED(x, max) ( ((x) > max) ? max : (x) );
#endif

#if defined(__GNUC__)
# define CANARD_MAYBE_UNUSED(x) x __attribute__((unused))
#else
# define CANARD_MAYBE_UNUSED(x) x
#endif

/**
  * @brief uavcan_equipment_ice_reciprocating_CylinderStatus_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_ice_reciprocating_CylinderStatus_encode_internal(uavcan_equipment_ice_reciprocating_CylinderStatus* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->ignition_timing_deg);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->ignition_timing_deg;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->injection_time_ms);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->injection_time_ms;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->cylinder_head_temperature);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->cylinder_head_temperature;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->exhaust_gas_temperature);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->exhaust_gas_temperature;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->lambda_coefficient);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->lambda_coefficient;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_ice_reciprocating_CylinderStatus_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_ice_reciprocating_CylinderStatus_encode(uavcan_equipment_ice_reciprocating_CylinderStatus* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_ice_reciprocating_CylinderStatus_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_ice_reciprocating_CylinderStatus_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_ice_reciprocating_CylinderStatus dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_ice_reciprocating_CylinderStatus_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_ice_reciprocating_CylinderStatus* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
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
        goto uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->ignition_timing_deg = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->ignition_timing_deg = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->injection_time_ms = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->injection_time_ms = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->cylinder_head_temperature = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->cylinder_head_temperature = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->exhaust_gas_temperature = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->exhaust_gas_temperature = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->lambda_coefficient = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->lambda_coefficient = (float)tmp_float;
#endif
    offset += 16;
    return offset;

uavcan_equipment_ice_reciprocating_CylinderStatus_error_exit:
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
  * @brief uavcan_equipment_ice_reciprocating_CylinderStatus_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_ice_reciprocating_CylinderStatus dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_ice_reciprocating_CylinderStatus_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_ice_reciprocating_CylinderStatus* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_ice_reciprocating_CylinderStatus); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_ice_reciprocating_CylinderStatus_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
