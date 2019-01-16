/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/ahrs/1002.MagneticFieldStrength2.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2
#define __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Magnetic field readings, in Gauss, in body frame.
# SI units are avoided because of float16 range limitations.
#

uint8 sensor_id

float16[3] magnetic_field_ga
float16[<=9] magnetic_field_covariance
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.ahrs.MagneticFieldStrength2
saturated uint8 sensor_id
saturated float16[3] magnetic_field_ga
saturated float16[<=9] magnetic_field_covariance
******************************************************************************/

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_ID    1002
#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_NAME  "uavcan.equipment.ahrs.MagneticFieldStrength2"
#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_SIGNATURE (0xB6AC0C442430297EULL)

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_MAX_SIZE ((204 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_MAGNETIC_FIELD_GA_LENGTH            3
#define UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2_MAGNETIC_FIELD_COVARIANCE_MAX_LENGTH 9

typedef struct
{
    // FieldTypes
    uint8_t    sensor_id;                     // bit len 8
    float      magnetic_field_ga[3];          // Static Array 16bit[3] max items
    struct
    {
        uint8_t    len;                       // Dynamic array length
        float*     data;                      // Dynamic Array 16bit[9] max items
    } magnetic_field_covariance;

} uavcan_equipment_ahrs_MagneticFieldStrength2;

extern
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode(uavcan_equipment_ahrs_MagneticFieldStrength2* source, void* msg_buf);

extern
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_ahrs_MagneticFieldStrength2* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_ahrs_MagneticFieldStrength2_encode_internal(uavcan_equipment_ahrs_MagneticFieldStrength2* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_ahrs_MagneticFieldStrength2_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_ahrs_MagneticFieldStrength2* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_AHRS_MAGNETICFIELDSTRENGTH2