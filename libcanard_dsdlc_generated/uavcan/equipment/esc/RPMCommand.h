/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/embedded/common/uavcan_dsdl/uavcan_dsdl/uavcan/equipment/esc/1031.RPMCommand.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND
#define __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Simple RPM setpoint.
# The ESC should automatically clamp the setpoint according to the minimum and maximum supported RPM;
# for example, given a ESC that operates in the range 100 to 10000 RPM, a setpoint of 1 RPM will be clamped to 100 RPM.
# Negative values indicate reverse rotation.
#

int18[<=20] rpm
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.esc.RPMCommand
saturated int18[<=20] rpm
******************************************************************************/

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_ID                 1031
#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_NAME               "uavcan.equipment.esc.RPMCommand"
#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_SIGNATURE          (0xCE0F9F621CF7E70BULL)

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_MAX_SIZE           ((365 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_RPM_MAX_LENGTH                                   20

typedef struct
{
    // FieldTypes
    struct
    {
        uint8_t    len;                       // Dynamic array length
        int32_t*   data;                      // Dynamic Array 18bit[20] max items
    } rpm;

} uavcan_equipment_esc_RPMCommand;

extern
uint32_t uavcan_equipment_esc_RPMCommand_encode(uavcan_equipment_esc_RPMCommand* source, void* msg_buf);

extern
int32_t uavcan_equipment_esc_RPMCommand_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RPMCommand* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_esc_RPMCommand_encode_internal(uavcan_equipment_esc_RPMCommand* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_esc_RPMCommand_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RPMCommand* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND