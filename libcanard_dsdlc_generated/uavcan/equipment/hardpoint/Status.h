/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/hardpoint/1071.Status.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_HARDPOINT_STATUS
#define __UAVCAN_EQUIPMENT_HARDPOINT_STATUS

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Generic cargo holder/hardpoint status.
#

uint8 hardpoint_id

float16 payload_weight           # Newton
float16 payload_weight_variance

#
# Meaning is the same as for the command field in the Command message
#
uint16 status
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.hardpoint.Status
saturated uint8 hardpoint_id
saturated float16 payload_weight
saturated float16 payload_weight_variance
saturated uint16 status
******************************************************************************/

#define UAVCAN_EQUIPMENT_HARDPOINT_STATUS_ID               1071
#define UAVCAN_EQUIPMENT_HARDPOINT_STATUS_NAME             "uavcan.equipment.hardpoint.Status"
#define UAVCAN_EQUIPMENT_HARDPOINT_STATUS_SIGNATURE        (0x624A519D42553D82ULL)

#define UAVCAN_EQUIPMENT_HARDPOINT_STATUS_MAX_SIZE         ((56 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    hardpoint_id;                  // bit len 8
    float      payload_weight;                // float16 Saturate
    float      payload_weight_variance;       // float16 Saturate
    uint16_t   status;                        // bit len 16

} uavcan_equipment_hardpoint_Status;

extern
uint32_t uavcan_equipment_hardpoint_Status_encode(uavcan_equipment_hardpoint_Status* source, void* msg_buf);

extern
int32_t uavcan_equipment_hardpoint_Status_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_hardpoint_Status* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_hardpoint_Status_encode_internal(uavcan_equipment_hardpoint_Status* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_hardpoint_Status_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_hardpoint_Status* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_HARDPOINT_STATUS