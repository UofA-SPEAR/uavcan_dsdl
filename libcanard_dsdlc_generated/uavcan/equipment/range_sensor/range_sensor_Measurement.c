/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/embedded/common/uavcan_dsdl/uavcan_dsdl/uavcan/equipment/range_sensor/1050.Measurement.uavcan
 */
#include "uavcan/equipment/range_sensor/Measurement.h"
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
  * @brief uavcan_equipment_range_sensor_Measurement_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_range_sensor_Measurement_encode_internal(uavcan_equipment_range_sensor_Measurement* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_encode_internal(&source->timestamp, msg_buf, offset, 0);
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->sensor_id); // 255
    offset += 8;

    // Compound
    offset = uavcan_CoarseOrientation_encode_internal(&source->beam_orientation_in_body_frame, msg_buf, offset, 0);

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->field_of_view);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->field_of_view;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;
    source->sensor_type = CANARD_INTERNAL_SATURATE_UNSIGNED(source->sensor_type, 31)
    canardEncodeScalar(msg_buf, offset, 5, (void*)&source->sensor_type); // 31
    offset += 5;

    source->reading_type = CANARD_INTERNAL_SATURATE_UNSIGNED(source->reading_type, 7)
    canardEncodeScalar(msg_buf, offset, 3, (void*)&source->reading_type); // 7
    offset += 3;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->range);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->range;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_range_sensor_Measurement_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_range_sensor_Measurement_encode(uavcan_equipment_range_sensor_Measurement* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_range_sensor_Measurement_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_range_sensor_Measurement_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_range_sensor_Measurement dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_range_sensor_Measurement_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_range_sensor_Measurement* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // Compound
    offset = uavcan_Timestamp_decode_internal(transfer, 0, &dest->timestamp, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }

    ret = canardDecodeScalar(transfer, offset, 8, false, (void*)&dest->sensor_id);
    if (ret != 8)
    {
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }
    offset += 8;

    // Compound
    offset = uavcan_CoarseOrientation_decode_internal(transfer, 0, &dest->beam_orientation_in_body_frame, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->field_of_view = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->field_of_view = (float)tmp_float;
#endif
    offset += 16;

    ret = canardDecodeScalar(transfer, offset, 5, false, (void*)&dest->sensor_type);
    if (ret != 5)
    {
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }
    offset += 5;

    ret = canardDecodeScalar(transfer, offset, 3, false, (void*)&dest->reading_type);
    if (ret != 3)
    {
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }
    offset += 3;

    // float16 special handling
    ret = canardDecodeScalar(transfer, offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_range_sensor_Measurement_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->range = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->range = (float)tmp_float;
#endif
    offset += 16;
    return offset;

uavcan_equipment_range_sensor_Measurement_error_exit:
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
  * @brief uavcan_equipment_range_sensor_Measurement_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_range_sensor_Measurement dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_range_sensor_Measurement_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_range_sensor_Measurement* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_range_sensor_Measurement); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_range_sensor_Measurement_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
