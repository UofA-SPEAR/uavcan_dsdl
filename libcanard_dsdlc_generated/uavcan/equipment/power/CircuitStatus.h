/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/power/1091.CircuitStatus.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS
#define __UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Generic electrical circuit info.
#

uint16 circuit_id

float16 voltage
float16 current

uint8 ERROR_FLAG_OVERVOLTAGE  = 1
uint8 ERROR_FLAG_UNDERVOLTAGE = 2
uint8 ERROR_FLAG_OVERCURRENT  = 4
uint8 ERROR_FLAG_UNDERCURRENT = 8
uint8 error_flags
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.power.CircuitStatus
saturated uint16 circuit_id
saturated float16 voltage
saturated float16 current
saturated uint8 error_flags
******************************************************************************/

#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_ID            1091
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_NAME          "uavcan.equipment.power.CircuitStatus"
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_SIGNATURE     (0x8313D33D0DDDA115ULL)

#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_MAX_SIZE      ((56 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_ERROR_FLAG_OVERVOLTAGE           1 // 1
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_ERROR_FLAG_UNDERVOLTAGE          2 // 2
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_ERROR_FLAG_OVERCURRENT           4 // 4
#define UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS_ERROR_FLAG_UNDERCURRENT          8 // 8

typedef struct
{
    // FieldTypes
    uint16_t   circuit_id;                    // bit len 16
    float      voltage;                       // float16 Saturate
    float      current;                       // float16 Saturate
    uint8_t    error_flags;                   // bit len 8

} uavcan_equipment_power_CircuitStatus;

extern
uint32_t uavcan_equipment_power_CircuitStatus_encode(uavcan_equipment_power_CircuitStatus* source, void* msg_buf);

extern
int32_t uavcan_equipment_power_CircuitStatus_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_CircuitStatus* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_power_CircuitStatus_encode_internal(uavcan_equipment_power_CircuitStatus* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_power_CircuitStatus_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_CircuitStatus* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_POWER_CIRCUITSTATUS