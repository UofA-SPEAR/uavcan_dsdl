/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/camera_gimbal/1040.AngularCommand.uavcan
 */
#include "uavcan/equipment/camera_gimbal/AngularCommand.h"
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
  * @brief uavcan_equipment_camera_gimbal_AngularCommand_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns new offset
  */
uint32_t uavcan_equipment_camera_gimbal_AngularCommand_encode_internal(uavcan_equipment_camera_gimbal_AngularCommand* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item))
{
    uint32_t c = 0;

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->gimbal_id); // 255
    offset += 8;

    // Compound
    offset = uavcan_equipment_camera_gimbal_Mode_encode_internal(&source->mode, msg_buf, offset, 0);
    // Static array (quaternion_xyzw)
    for (c = 0; c < 4; c++)
    {
        canardEncodeScalar(msg_buf, offset, 16, (void*)(source->quaternion_xyzw + c)); // 32767
        offset += 16;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_camera_gimbal_AngularCommand_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_camera_gimbal_AngularCommand_encode(uavcan_equipment_camera_gimbal_AngularCommand* source, void* msg_buf)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_camera_gimbal_AngularCommand_encode_internal(source, msg_buf, offset, 1);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_camera_gimbal_AngularCommand_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_camera_gimbal_AngularCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval new offset or ERROR value if < 0
  */
int32_t uavcan_equipment_camera_gimbal_AngularCommand_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_camera_gimbal_AngularCommand* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->gimbal_id);
    if (ret != 8)
    {
        goto uavcan_equipment_camera_gimbal_AngularCommand_error_exit;
    }
    offset += 8;

    // Compound
    offset = uavcan_equipment_camera_gimbal_Mode_decode_internal(transfer, payload_len, &dest->mode, dyn_arr_buf, offset);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_camera_gimbal_AngularCommand_error_exit;
    }

    // Static array (quaternion_xyzw)
    for (c = 0; c < 4; c++)
    {
        ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)(dest->quaternion_xyzw + c));
        if (ret != 16)
        {
            goto uavcan_equipment_camera_gimbal_AngularCommand_error_exit;
        }
        offset += 16;
    }
    return offset;

uavcan_equipment_camera_gimbal_AngularCommand_error_exit:
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
  * @brief uavcan_equipment_camera_gimbal_AngularCommand_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_camera_gimbal_AngularCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_camera_gimbal_AngularCommand_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_camera_gimbal_AngularCommand* dest,
  uint8_t** dyn_arr_buf)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_camera_gimbal_AngularCommand); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_camera_gimbal_AngularCommand_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset);

    return ret;
}
