/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/ice/reciprocating/1120.Status.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS
#define __UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/equipment/ice/reciprocating/CylinderStatus.h>

/******************************* Source text **********************************
#
# Generic status message of a piston engine control system.
#
# All integer fields are required unless stated otherwise.
# All floating point fields are optional unless stated otherwise; unknown/unapplicable fields should be set to NaN.
#

#
# Abstract engine state. The flags defined below can provide further elaboration.
# This is a required field.
#
uint2 state
#
# The engine is not running. This is the default state.
# Next states: STARTING, FAULT
#
uint2 STATE_STOPPED = 0
#
# The engine is starting. This is a transient state.
# Next states: STOPPED, RUNNING, FAULT
#
uint2 STATE_STARTING = 1
#
# The engine is running normally.
# Some error flags may be set to indicate non-fatal issues, e.g. overheating.
# Next states: STOPPED, FAULT
#
uint2 STATE_RUNNING = 2
#
# The engine can no longer function.
# The error flags may contain additional information about the nature of the fault.
# Next states: STOPPED.
#
uint2 STATE_FAULT = 3

#
# General status flags.
# Note that not all flags are required. Those that aren't are prepended with a validity flag, which is, obviously,
# always required; when the validity flag is set, it is assumed that the relevant flags are set correctly.
# If the validity flag is cleared, then the state of the relevant flags should be ignored.
# All unused bits must be cleared.
#
uint30 flags
#
# General error. This flag is required, and it can be used to indicate an error condition
# that does not fit any of the other flags.
# Note that the vendor may also report additional status information via the vendor specific status code
# field of the NodeStatus message.
#
uint30 FLAG_GENERAL_ERROR                       = 1
#
# Error of the crankshaft sensor. This flag is optional.
#
uint30 FLAG_CRANKSHAFT_SENSOR_ERROR_SUPPORTED   = 2
uint30 FLAG_CRANKSHAFT_SENSOR_ERROR             = 4
#
# Temperature levels. These flags are optional; either none of them or all of them are supported.
#
uint30 FLAG_TEMPERATURE_SUPPORTED               = 8
uint30 FLAG_TEMPERATURE_BELOW_NOMINAL           = 16      # Under-temperature warning
uint30 FLAG_TEMPERATURE_ABOVE_NOMINAL           = 32      # Over-temperature warning
uint30 FLAG_TEMPERATURE_OVERHEATING             = 64      # Critical overheating
uint30 FLAG_TEMPERATURE_EGT_ABOVE_NOMINAL       = 128     # Exhaust gas over-temperature warning
#
# Fuel pressure. These flags are optional; either none of them or all of them are supported.
#
uint30 FLAG_FUEL_PRESSURE_SUPPORTED             = 256
uint30 FLAG_FUEL_PRESSURE_BELOW_NOMINAL         = 512     # Under-pressure warning
uint30 FLAG_FUEL_PRESSURE_ABOVE_NOMINAL         = 1024    # Over-pressure warning
#
# Detonation warning. This flag is optional.
# This warning is cleared immediately after broadcasting is done if detonation is no longer happening.
#
uint30 FLAG_DETONATION_SUPPORTED                = 2048
uint30 FLAG_DETONATION_OBSERVED                 = 4096    # Detonation condition observed warning
#
# Misfire warning. This flag is optional.
# This warning is cleared immediately after broadcasting is done if misfire is no longer happening.
#
uint30 FLAG_MISFIRE_SUPPORTED                   = 8192
uint30 FLAG_MISFIRE_OBSERVED                    = 16384   # Misfire condition observed warning
#
# Oil pressure. These flags are optional; either none of them or all of them are supported.
#
uint30 FLAG_OIL_PRESSURE_SUPPORTED              = 32768
uint30 FLAG_OIL_PRESSURE_BELOW_NOMINAL          = 65536   # Under-pressure warning
uint30 FLAG_OIL_PRESSURE_ABOVE_NOMINAL          = 131072  # Over-pressure warning
#
# Debris warning. This flag is optional.
#
uint30 FLAG_DEBRIS_SUPPORTED                    = 262144
uint30 FLAG_DEBRIS_DETECTED                     = 524288  # Detection of debris warning

#
# Reserved space
#
void16

#
# Engine load estimate.
# Unit: percent.
# Range: [0, 127].
#
uint7 engine_load_percent

#
# Engine speed.
# Unit: revolutions per minute.
#
uint17 engine_speed_rpm

#
# Spark dwell time.
# Unit: millisecond.
#
float16 spark_dwell_time_ms

#
# Atmospheric (barometric) pressure.
# Unit: kilopascal.
#
float16 atmospheric_pressure_kpa

#
# Engine intake manifold pressure.
# Unit: kilopascal.
#
float16 intake_manifold_pressure_kpa

#
# Engine intake manifold temperature.
# Unit: kelvin.
#
float16 intake_manifold_temperature

#
# Engine coolant temperature.
# Unit: kelvin.
#
float16 coolant_temperature

#
# Oil pressure.
# Unit: kilopascal.
#
float16 oil_pressure

#
# Oil temperature.
# Unit: kelvin.
#
float16 oil_temperature

#
# Fuel pressure.
# Unit: kilopascal.
#
float16 fuel_pressure

#
# Instant fuel consumption estimate.
# The estimated value should be low-pass filtered in order to prevent aliasing effects.
# Unit: (centimeter^3)/minute.
#
float32 fuel_consumption_rate_cm3pm

#
# Estimate of the consumed fuel since the start of the engine.
# This variable MUST be reset when the engine is stopped.
# Unit: centimeter^3.
#
float32 estimated_consumed_fuel_volume_cm3

#
# Throttle position.
# Unit: percent.
#
uint7 throttle_position_percent

#
# The index of the publishing ECU.
#
uint6 ecu_index

#
# Spark plug activity report.
# Can be used during pre-flight tests of the spark subsystem.
#
uint3 spark_plug_usage
#
uint3 SPARK_PLUG_SINGLE         = 0
uint3 SPARK_PLUG_FIRST_ACTIVE   = 1
uint3 SPARK_PLUG_SECOND_ACTIVE  = 2
uint3 SPARK_PLUG_BOTH_ACTIVE    = 3

#
# Per-cylinder status information.
#
CylinderStatus[<=16] cylinder_status
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.ice.reciprocating.Status
saturated uint2 state
saturated uint30 flags
void16
saturated uint7 engine_load_percent
saturated uint17 engine_speed_rpm
saturated float16 spark_dwell_time_ms
saturated float16 atmospheric_pressure_kpa
saturated float16 intake_manifold_pressure_kpa
saturated float16 intake_manifold_temperature
saturated float16 coolant_temperature
saturated float16 oil_pressure
saturated float16 oil_temperature
saturated float16 fuel_pressure
saturated float32 fuel_consumption_rate_cm3pm
saturated float32 estimated_consumed_fuel_volume_cm3
saturated uint7 throttle_position_percent
saturated uint6 ecu_index
saturated uint3 spark_plug_usage
uavcan.equipment.ice.reciprocating.CylinderStatus[<=16] cylinder_status
******************************************************************************/

#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_ID       1120
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_NAME     "uavcan.equipment.ice.reciprocating.Status"
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_SIGNATURE (0xD38AA3EE75537EC6ULL)

#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_MAX_SIZE ((1565 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_STATE_STOPPED               0 // 0
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_STATE_STARTING              1 // 1
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_STATE_RUNNING               2 // 2
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_STATE_FAULT                 3 // 3
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_GENERAL_ERROR          1 // 1
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_CRANKSHAFT_SENSOR_ERROR_SUPPORTED          2 // 2
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_CRANKSHAFT_SENSOR_ERROR          4 // 4
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_TEMPERATURE_SUPPORTED          8 // 8
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_TEMPERATURE_BELOW_NOMINAL         16 // 16
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_TEMPERATURE_ABOVE_NOMINAL         32 // 32
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_TEMPERATURE_OVERHEATING         64 // 64
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_TEMPERATURE_EGT_ABOVE_NOMINAL        128 // 128
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_FUEL_PRESSURE_SUPPORTED        256 // 256
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_FUEL_PRESSURE_BELOW_NOMINAL        512 // 512
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_FUEL_PRESSURE_ABOVE_NOMINAL       1024 // 1024
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_DETONATION_SUPPORTED       2048 // 2048
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_DETONATION_OBSERVED       4096 // 4096
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_MISFIRE_SUPPORTED       8192 // 8192
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_MISFIRE_OBSERVED      16384 // 16384
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_OIL_PRESSURE_SUPPORTED      32768 // 32768
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_OIL_PRESSURE_BELOW_NOMINAL      65536 // 65536
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_OIL_PRESSURE_ABOVE_NOMINAL     131072 // 131072
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_DEBRIS_SUPPORTED     262144 // 262144
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_FLAG_DEBRIS_DETECTED     524288 // 524288
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_SPARK_PLUG_SINGLE           0 // 0
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_SPARK_PLUG_FIRST_ACTIVE          1 // 1
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_SPARK_PLUG_SECOND_ACTIVE          2 // 2
#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_SPARK_PLUG_BOTH_ACTIVE          3 // 3

#define UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS_CYLINDER_STATUS_MAX_LENGTH             16

typedef struct
{
    // FieldTypes
    uint8_t    state;                         // bit len 2
    uint32_t   flags;                         // bit len 30
    // void16
    uint8_t    engine_load_percent;           // bit len 7
    uint32_t   engine_speed_rpm;              // bit len 17
    float      spark_dwell_time_ms;           // float16 Saturate
    float      atmospheric_pressure_kpa;      // float16 Saturate
    float      intake_manifold_pressure_kpa;  // float16 Saturate
    float      intake_manifold_temperature;   // float16 Saturate
    float      coolant_temperature;           // float16 Saturate
    float      oil_pressure;                  // float16 Saturate
    float      oil_temperature;               // float16 Saturate
    float      fuel_pressure;                 // float16 Saturate
    float      fuel_consumption_rate_cm3pm;   // float32 Saturate
    float      estimated_consumed_fuel_volume_cm3; // float32 Saturate
    uint8_t    throttle_position_percent;     // bit len 7
    uint8_t    ecu_index;                     // bit len 6
    uint8_t    spark_plug_usage;              // bit len 3
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uavcan_equipment_ice_reciprocating_CylinderStatus* data;                      // Dynamic Array 80bit[16] max items
    } cylinder_status;

} uavcan_equipment_ice_reciprocating_Status;

extern
uint32_t uavcan_equipment_ice_reciprocating_Status_encode(uavcan_equipment_ice_reciprocating_Status* source, void* msg_buf);

extern
int32_t uavcan_equipment_ice_reciprocating_Status_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_ice_reciprocating_Status* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_ice_reciprocating_Status_encode_internal(uavcan_equipment_ice_reciprocating_Status* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_ice_reciprocating_Status_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_ice_reciprocating_Status* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_ICE_RECIPROCATING_STATUS