/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/4.GlobalTimeSync.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_GLOBALTIMESYNC
#define __UAVCAN_PROTOCOL_GLOBALTIMESYNC

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Global time synchronization.
# Any node that publishes timestamped data must use this time reference.
#
# Please refer to the specification to learn about the synchronization algorithm.
#

#
# Broadcasting period must be within this range.
#
uint16 MAX_BROADCASTING_PERIOD_MS = 1100            # Milliseconds
uint16 MIN_BROADCASTING_PERIOD_MS = 40              # Milliseconds

#
# Synchronization slaves may switch to a new source if the current master was silent for this amount of time.
#
uint16 RECOMMENDED_BROADCASTER_TIMEOUT_MS = 2200    # Milliseconds

#
# Time in microseconds when the PREVIOUS GlobalTimeSync message was transmitted.
# If this message is the first one, this field must be zero.
#
truncated uint56 previous_transmission_timestamp_usec # Microseconds
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.GlobalTimeSync
truncated uint56 previous_transmission_timestamp_usec
******************************************************************************/

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_ID                  4
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_NAME                "uavcan.protocol.GlobalTimeSync"
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_SIGNATURE           (0x20271116A793C2DBULL)

#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MAX_SIZE            ((56 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MAX_BROADCASTING_PERIOD_MS          1100 // 1100
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_MIN_BROADCASTING_PERIOD_MS            40 // 40
#define UAVCAN_PROTOCOL_GLOBALTIMESYNC_RECOMMENDED_BROADCASTER_TIMEOUT_MS       2200 // 2200

typedef struct
{
    // FieldTypes
    uint64_t   previous_transmission_timestamp_usec; // bit len 56

} uavcan_protocol_GlobalTimeSync;

extern
uint32_t uavcan_protocol_GlobalTimeSync_encode(uavcan_protocol_GlobalTimeSync* source, void* msg_buf);

extern
int32_t uavcan_protocol_GlobalTimeSync_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GlobalTimeSync* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_GlobalTimeSync_encode_internal(uavcan_protocol_GlobalTimeSync* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_GlobalTimeSync_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_GlobalTimeSync* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_GLOBALTIMESYNC