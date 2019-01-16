/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/actuator/1010.ArrayCommand.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND
#define __UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/equipment/actuator/Command.h>

/******************************* Source text **********************************
#
# Actuator commands.
# The system supports up to 256 actuators; up to 15 of them can be commanded with one message.
#

Command[<=15] commands
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.actuator.ArrayCommand
uavcan.equipment.actuator.Command[<=15] commands
******************************************************************************/

#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_ID          1010
#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_NAME        "uavcan.equipment.actuator.ArrayCommand"
#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_SIGNATURE   (0xD8A7486238EC3AF3ULL)

#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_MAX_SIZE    ((484 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND_COMMANDS_MAX_LENGTH                       15

typedef struct
{
    // FieldTypes
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uavcan_equipment_actuator_Command* data;                      // Dynamic Array 32bit[15] max items
    } commands;

} uavcan_equipment_actuator_ArrayCommand;

extern
uint32_t uavcan_equipment_actuator_ArrayCommand_encode(uavcan_equipment_actuator_ArrayCommand* source, void* msg_buf);

extern
int32_t uavcan_equipment_actuator_ArrayCommand_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_actuator_ArrayCommand* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_actuator_ArrayCommand_encode_internal(uavcan_equipment_actuator_ArrayCommand* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_actuator_ArrayCommand_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_actuator_ArrayCommand* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_ACTUATOR_ARRAYCOMMAND