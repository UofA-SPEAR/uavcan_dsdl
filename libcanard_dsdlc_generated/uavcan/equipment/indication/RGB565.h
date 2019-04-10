/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/embedded/common/uavcan_dsdl/uavcan_dsdl/uavcan/equipment/indication/RGB565.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_INDICATION_RGB565
#define __UAVCAN_EQUIPMENT_INDICATION_RGB565

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Nested type.
# RGB color in the standard 5-6-5 16-bit palette.
# Monocolor lights should interpret this as brightness setpoint: from zero (0, 0, 0) to full brightness (31, 63, 31).
#

uint5 red
uint6 green
uint5 blue
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.indication.RGB565
saturated uint5 red
saturated uint6 green
saturated uint5 blue
******************************************************************************/

#define UAVCAN_EQUIPMENT_INDICATION_RGB565_NAME            "uavcan.equipment.indication.RGB565"
#define UAVCAN_EQUIPMENT_INDICATION_RGB565_SIGNATURE       (0x58A7CEF41951EC34ULL)

#define UAVCAN_EQUIPMENT_INDICATION_RGB565_MAX_SIZE        ((16 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    red;                           // bit len 5
    uint8_t    green;                         // bit len 6
    uint8_t    blue;                          // bit len 5

} uavcan_equipment_indication_RGB565;

extern
uint32_t uavcan_equipment_indication_RGB565_encode(uavcan_equipment_indication_RGB565* source, void* msg_buf);

extern
int32_t uavcan_equipment_indication_RGB565_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_indication_RGB565* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_indication_RGB565_encode_internal(uavcan_equipment_indication_RGB565* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_indication_RGB565_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_indication_RGB565* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_INDICATION_RGB565