/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/equipment/gnss/1063.Fix2.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_GNSS_FIX2
#define __UAVCAN_EQUIPMENT_GNSS_FIX2

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/Timestamp.h>
#include <uavcan/equipment/gnss/ECEFPositionVelocity.h>

/******************************* Source text **********************************
#
# GNSS ECEF and LLA navigation solution with uncertainty.
#

#
# Global network-synchronized time, if available, otherwise zero.
#
uavcan.Timestamp timestamp

#
# Time solution.
# The method and number of leap seconds which were in use for deriving the timestamp are
# defined in the fields below.
#
uavcan.Timestamp gnss_timestamp

#
# Method used for deriving the GNSS timestamp field.
# This data type relies on the following definitions:
#
#   Leap seconds  - Accumulated one-second adjustments applied to UTC since 1972.
#                   For reference, on May 2017, the number of leap seconds was equal 27.
#                   The number of leap seconds is taken from the field num_leap_seconds.
#                   Refer to https://en.wikipedia.org/wiki/Leap_second for a general overview.
#
#   TAI timestamp - The number of microseconds between the current TAI time and
#                   the TAI time at UTC 1970-01-01T00:00:00.
#
#   UTC timestamp - The number of microseconds between the current UTC time and
#                   UTC 1970-01-01T00:00:00.
#                   UTC can be expressed via TAI as follows (in seconds):
#                       UTC = TAI - num_leap_seconds - 10
#                   And via GPS (in seconds):
#                       UTC = GPS - num_leap_seconds + 9
#
#   GPS timestamp - The number of microseconds between the current GPS time and
#                   the GPS time at UTC 1970-01-01T00:00:00.
#                   GPS time can be expressed via TAI as follows (in seconds):
#                       GPS = TAI - 19
#
uint3 GNSS_TIME_STANDARD_NONE = 0  # Time is unknown
uint3 GNSS_TIME_STANDARD_TAI  = 1
uint3 GNSS_TIME_STANDARD_UTC  = 2
uint3 GNSS_TIME_STANDARD_GPS  = 3
uint3 gnss_time_standard

void13   # Reserved space

#
# Accumulated one-second adjustments applied to UTC since 1972.
# The number must agree with the currently correct number of UTC leap seconds. If this cannot
# be garanteed, the field must be set to NUM_LEAP_SECONDS_UNKNOWN.
#
uint8 NUM_LEAP_SECONDS_UNKNOWN = 0
uint8 num_leap_seconds

#
# Position and velocity solution
#
int37 longitude_deg_1e8            # Longitude degrees multiplied by 1e8 (approx. 1 mm per LSB)
int37 latitude_deg_1e8             # Latitude degrees multiplied by 1e8 (approx. 1 mm per LSB on equator)
int27 height_ellipsoid_mm          # Height above ellipsoid in millimeters
int27 height_msl_mm                # Height above mean sea level in millimeters

float32[3] ned_velocity            # NED frame (north-east-down) in meters per second

#
# Fix status
#
uint6 sats_used

uint2 STATUS_NO_FIX    = 0
uint2 STATUS_TIME_ONLY = 1
uint2 STATUS_2D_FIX    = 2
uint2 STATUS_3D_FIX    = 3
uint2 status

#
# GNSS Mode
#
uint4 MODE_SINGLE      = 0
uint4 MODE_DGPS        = 1
uint4 MODE_RTK         = 2
uint4 MODE_PPP         = 3
uint4 mode

#
# GNSS Sub mode
#
uint6 SUB_MODE_DGPS_OTHER    = 0
uint6 SUB_MODE_DGPS_SBAS     = 1

uint6 SUB_MODE_RTK_FLOAT     = 0
uint6 SUB_MODE_RTK_FIXED     = 1

uint6 sub_mode

#
# Precision
#
float16[<=36] covariance    # Position and velocity covariance. Units are
                            # m^2 for position, (m/s)^2 for velocity and
                            # m^2/s for position/velocity.

float16 pdop

#
# Position and velocity solution in ECEF, if available
#
ECEFPositionVelocity[<=1] ecef_position_velocity
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.gnss.Fix2
uavcan.Timestamp timestamp
uavcan.Timestamp gnss_timestamp
saturated uint3 gnss_time_standard
void13
saturated uint8 num_leap_seconds
saturated int37 longitude_deg_1e8
saturated int37 latitude_deg_1e8
saturated int27 height_ellipsoid_mm
saturated int27 height_msl_mm
saturated float32[3] ned_velocity
saturated uint6 sats_used
saturated uint2 status
saturated uint4 mode
saturated uint6 sub_mode
saturated float16[<=36] covariance
saturated float16 pdop
uavcan.equipment.gnss.ECEFPositionVelocity[<=1] ecef_position_velocity
******************************************************************************/

#define UAVCAN_EQUIPMENT_GNSS_FIX2_ID                      1063
#define UAVCAN_EQUIPMENT_GNSS_FIX2_NAME                    "uavcan.equipment.gnss.Fix2"
#define UAVCAN_EQUIPMENT_GNSS_FIX2_SIGNATURE               (0xCA41E7000F37435FULL)

#define UAVCAN_EQUIPMENT_GNSS_FIX2_MAX_SIZE                ((1769 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_GNSS_FIX2_GNSS_TIME_STANDARD_NONE                    0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_GNSS_TIME_STANDARD_TAI                     1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX2_GNSS_TIME_STANDARD_UTC                     2 // 2
#define UAVCAN_EQUIPMENT_GNSS_FIX2_GNSS_TIME_STANDARD_GPS                     3 // 3
#define UAVCAN_EQUIPMENT_GNSS_FIX2_NUM_LEAP_SECONDS_UNKNOWN                   0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_STATUS_NO_FIX                              0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_STATUS_TIME_ONLY                           1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX2_STATUS_2D_FIX                              2 // 2
#define UAVCAN_EQUIPMENT_GNSS_FIX2_STATUS_3D_FIX                              3 // 3
#define UAVCAN_EQUIPMENT_GNSS_FIX2_MODE_SINGLE                                0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_MODE_DGPS                                  1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX2_MODE_RTK                                   2 // 2
#define UAVCAN_EQUIPMENT_GNSS_FIX2_MODE_PPP                                   3 // 3
#define UAVCAN_EQUIPMENT_GNSS_FIX2_SUB_MODE_DGPS_OTHER                        0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_SUB_MODE_DGPS_SBAS                         1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX2_SUB_MODE_RTK_FLOAT                         0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX2_SUB_MODE_RTK_FIXED                         1 // 1

#define UAVCAN_EQUIPMENT_GNSS_FIX2_NED_VELOCITY_LENGTH                                   3
#define UAVCAN_EQUIPMENT_GNSS_FIX2_COVARIANCE_MAX_LENGTH                                 36
#define UAVCAN_EQUIPMENT_GNSS_FIX2_ECEF_POSITION_VELOCITY_MAX_LENGTH                     1

typedef struct
{
    // FieldTypes
    uavcan_Timestamp timestamp;                     //
    uavcan_Timestamp gnss_timestamp;                //
    uint8_t    gnss_time_standard;            // bit len 3
    // void13
    uint8_t    num_leap_seconds;              // bit len 8
    int64_t    longitude_deg_1e8;             // bit len 37
    int64_t    latitude_deg_1e8;              // bit len 37
    int32_t    height_ellipsoid_mm;           // bit len 27
    int32_t    height_msl_mm;                 // bit len 27
    float      ned_velocity[3];               // Static Array 32bit[3] max items
    uint8_t    sats_used;                     // bit len 6
    uint8_t    status;                        // bit len 2
    uint8_t    mode;                          // bit len 4
    uint8_t    sub_mode;                      // bit len 6
    struct
    {
        uint8_t    len;                       // Dynamic array length
        float*     data;                      // Dynamic Array 16bit[36] max items
    } covariance;
    float      pdop;                          // float16 Saturate
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uavcan_equipment_gnss_ECEFPositionVelocity* data;                      // Dynamic Array 792bit[1] max items
    } ecef_position_velocity;

} uavcan_equipment_gnss_Fix2;

extern
uint32_t uavcan_equipment_gnss_Fix2_encode(uavcan_equipment_gnss_Fix2* source, void* msg_buf);

extern
int32_t uavcan_equipment_gnss_Fix2_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Fix2* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_equipment_gnss_Fix2_encode_internal(uavcan_equipment_gnss_Fix2* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_equipment_gnss_Fix2_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Fix2* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_GNSS_FIX2