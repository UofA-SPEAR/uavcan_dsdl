/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/power/1092.BatteryInfo.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_POWER_BATTERYINFO
#define __UAVCAN_EQUIPMENT_POWER_BATTERYINFO

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Single battery info.
#
# Typical publishing rate should be around 0.2~1 Hz.
#
# Please refer to the Smart Battery data specification for some elaboration.
#

#
# Primary parameters.
# Some fields can be set to NAN if their values are unknown.
# Full charge capacity is expected to slowly reduce as the battery is aging. Normally its estimate is updated after
# every charging cycle.
#
float16 temperature             # [Kelvin]
float16 voltage                 # [Volt]
float16 current                 # [Ampere]
float16 average_power_10sec     # [Watt]        Average power consumption over the last 10 seconds
float16 remaining_capacity_wh   # [Watt hours]  Will be increasing during charging
float16 full_charge_capacity_wh # [Watt hours]  Predicted battery capacity when it is fully charged. Falls with aging
float16 hours_to_full_charge    # [Hours]       Charging is expected to complete in this time; zero if not charging

#
# Status flags.
# Notes:
#  - CHARGING must be always set as long as the battery is connected to a charger, even if the charging is complete.
#  - CHARGED must be cleared immediately when the charger is disconnected.
#
uint11 STATUS_FLAG_IN_USE       = 1     # The battery is currently used as a power supply
uint11 STATUS_FLAG_CHARGING     = 2     # Charger is active
uint11 STATUS_FLAG_CHARGED      = 4     # Charging complete, but the charger is still active
uint11 STATUS_FLAG_TEMP_HOT     = 8     # Battery temperature is above normal
uint11 STATUS_FLAG_TEMP_COLD    = 16    # Battery temperature is below normal
uint11 STATUS_FLAG_OVERLOAD     = 32    # Safe operating area violation
uint11 STATUS_FLAG_BAD_BATTERY  = 64    # This battery should not be used anymore (e.g. low SOH)
uint11 STATUS_FLAG_NEED_SERVICE = 128   # This battery requires maintenance (e.g. balancing, full recharge)
uint11 STATUS_FLAG_BMS_ERROR    = 256   # Battery management system/controller error, smart battery interface error
uint11 STATUS_FLAG_RESERVED_A   = 512   # Keep zero
uint11 STATUS_FLAG_RESERVED_B   = 1024  # Keep zero
uint11 status_flags

#
# State of Health (SOH) estimate, in percent.
# http://en.wikipedia.org/wiki/State_of_health
#
uint7 STATE_OF_HEALTH_UNKNOWN = 127     # Use this constant if SOH cannot be estimated
uint7 state_of_health_pct               # Health of the battery, in percent, optional

#
# Relative State of Charge (SOC) estimate, in percent.
# http://en.wikipedia.org/wiki/State_of_charge
#
uint7 state_of_charge_pct               # Percent of the full charge [0, 100]. This field is required
uint7 state_of_charge_pct_stdev         # SOC error standard deviation; use best guess if unknown

#
# Battery identification.
# Model instance ID must be unique within the same battery model name.
# Model name is a human-readable string that normally should include the vendor name, model name, and chemistry
# type of this battery. This field should be assumed case-insensitive. Example: "Zubax Smart Battery v1.1 LiPo".
#
uint8 battery_id                        # Identifies the battery within this vehicle, e.g. 0 - primary battery
uint32 model_instance_id                # Set to zero if not applicable
uint8[<32] model_name                   # Battery model name
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.power.BatteryInfo
saturated float16 temperature
saturated float16 voltage
saturated float16 current
saturated float16 average_power_10sec
saturated float16 remaining_capacity_wh
saturated float16 full_charge_capacity_wh
saturated float16 hours_to_full_charge
saturated uint11 status_flags
saturated uint7 state_of_health_pct
saturated uint7 state_of_charge_pct
saturated uint7 state_of_charge_pct_stdev
saturated uint8 battery_id
saturated uint32 model_instance_id
saturated uint8[<=31] model_name
******************************************************************************/

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_ID              1092
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_NAME            "uavcan.equipment.power.BatteryInfo"
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_SIGNATURE       (0x249C26548A711966ULL)

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_MAX_SIZE        ((437 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_IN_USE                 1 // 1
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_CHARGING               2 // 2
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_CHARGED                4 // 4
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_TEMP_HOT               8 // 8
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_TEMP_COLD             16 // 16
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_OVERLOAD              32 // 32
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_BAD_BATTERY           64 // 64
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_NEED_SERVICE         128 // 128
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_BMS_ERROR            256 // 256
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_RESERVED_A           512 // 512
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_RESERVED_B          1024 // 1024
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATE_OF_HEALTH_UNKNOWN          127 // 127

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_MODEL_NAME_MAX_LENGTH                         31

typedef struct
{
    // FieldTypes
    float      temperature;                   // float16 Saturate
    float      voltage;                       // float16 Saturate
    float      current;                       // float16 Saturate
    float      average_power_10sec;           // float16 Saturate
    float      remaining_capacity_wh;         // float16 Saturate
    float      full_charge_capacity_wh;       // float16 Saturate
    float      hours_to_full_charge;          // float16 Saturate
    uint16_t   status_flags;                  // bit len 11
    uint8_t    state_of_health_pct;           // bit len 7
    uint8_t    state_of_charge_pct;           // bit len 7
    uint8_t    state_of_charge_pct_stdev;     // bit len 7
    uint8_t    battery_id;                    // bit len 8
    uint32_t   model_instance_id;             // bit len 32
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[31] max items
    } model_name;

} uavcan_equipment_power_BatteryInfo;

extern
uint32_t uavcan_equipment_power_BatteryInfo_encode(uavcan_equipment_power_BatteryInfo* source, void* msg_buf);

extern
int32_t uavcan_equipment_power_BatteryInfo_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_BatteryInfo* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_power_BatteryInfo_encode_internal(uavcan_equipment_power_BatteryInfo* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_power_BatteryInfo_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_BatteryInfo* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_POWER_BATTERYINFO