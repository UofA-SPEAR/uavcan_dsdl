/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/air_data/1020.TrueAirspeed.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED
#define __UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# TAS.
#

float16 true_airspeed           # m/s
float16 true_airspeed_variance  # (m/s)^2
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.air_data.TrueAirspeed
saturated float16 true_airspeed
saturated float16 true_airspeed_variance
******************************************************************************/

#define UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED_ID          1020
#define UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED_NAME        "uavcan.equipment.air_data.TrueAirspeed"
#define UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED_SIGNATURE   (0x306F69E0A591AFAAULL)

#define UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED_MAX_SIZE    ((32 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      true_airspeed;                 // float16 Saturate
    float      true_airspeed_variance;        // float16 Saturate

} uavcan_equipment_air_data_TrueAirspeed;

extern
uint32_t uavcan_equipment_air_data_TrueAirspeed_encode(uavcan_equipment_air_data_TrueAirspeed* source, void* msg_buf);

extern
int32_t uavcan_equipment_air_data_TrueAirspeed_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_TrueAirspeed* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_air_data_TrueAirspeed_encode_internal(uavcan_equipment_air_data_TrueAirspeed* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_air_data_TrueAirspeed_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_air_data_TrueAirspeed* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_AIR_DATA_TRUEAIRSPEED