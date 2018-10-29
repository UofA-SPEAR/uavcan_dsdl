/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/debug/LogLevel.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DEBUG_LOGLEVEL
#define __UAVCAN_PROTOCOL_DEBUG_LOGLEVEL

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Log message severity
#

uint3 DEBUG    = 0
uint3 INFO     = 1
uint3 WARNING  = 2
uint3 ERROR    = 3
uint3 value
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.debug.LogLevel
saturated uint3 value
******************************************************************************/

#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_NAME                "uavcan.protocol.debug.LogLevel"
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_SIGNATURE           (0x711BF141AF572346ULL)

#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_MAX_SIZE            ((3 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_DEBUG                                  0 // 0
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_INFO                                   1 // 1
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_WARNING                                2 // 2
#define UAVCAN_PROTOCOL_DEBUG_LOGLEVEL_ERROR                                  3 // 3

typedef struct
{
    // FieldTypes
    uint8_t    value;                         // bit len 3

} uavcan_protocol_debug_LogLevel;

extern
uint32_t uavcan_protocol_debug_LogLevel_encode(uavcan_protocol_debug_LogLevel* source, void* msg_buf);

extern
int32_t uavcan_protocol_debug_LogLevel_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_LogLevel* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_debug_LogLevel_encode_internal(uavcan_protocol_debug_LogLevel* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_debug_LogLevel_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_debug_LogLevel* dest, uint8_t** dyn_arr_buf, int32_t offset, uint8_t tao);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DEBUG_LOGLEVEL