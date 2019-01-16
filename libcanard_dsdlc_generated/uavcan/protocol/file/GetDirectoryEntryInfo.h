/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/isthatme/Documents/Clubs/SPEAR/dsdl/uavcan_dsdl/uavcan/protocol/file/46.GetDirectoryEntryInfo.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO
#define __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/file/EntryType.h>
#include <uavcan/protocol/file/Error.h>
#include <uavcan/protocol/file/Path.h>

/******************************* Source text **********************************
#
# This service can be used to retrieve a remote directory listing, one entry per request.
#
# The client should query each entry independently, iterating 'entry_index' from 0 until the last entry is passed,
# in which case the server will report that there is no such entry (via the fields 'entry_type' and 'error').
#
# The entry_index shall be applied to the ordered list of directory entries (e.g. alphabetically ordered). The exact
# sorting criteria does not matter as long as it provides the same ordering for subsequent service calls.
#

uint32 entry_index

Path directory_path

---

Error error

EntryType entry_type

Path entry_full_path  # Ignored/Empty if such entry does not exist.
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.GetDirectoryEntryInfo
saturated uint32 entry_index
uavcan.protocol.file.Path directory_path
---
uavcan.protocol.file.Error error
uavcan.protocol.file.EntryType entry_type
uavcan.protocol.file.Path entry_full_path
******************************************************************************/

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_ID      46
#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_NAME    "uavcan.protocol.file.GetDirectoryEntryInfo"
#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_SIGNATURE (0x8C46E8AB568BDA79ULL)

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_REQUEST_MAX_SIZE ((1640 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint32_t   entry_index;                   // bit len 32
    uavcan_protocol_file_Path directory_path;                //

} uavcan_protocol_file_GetDirectoryEntryInfoRequest;

extern
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source, void* msg_buf);

extern
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest, uint8_t** dyn_arr_buf, int32_t offset);

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_RESPONSE_MAX_SIZE ((1632 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uavcan_protocol_file_Error error;                         //
    uavcan_protocol_file_EntryType entry_type;                    //
    uavcan_protocol_file_Path entry_full_path;               //

} uavcan_protocol_file_GetDirectoryEntryInfoResponse;

extern
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source, void* msg_buf);

extern
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest, uint8_t** dyn_arr_buf);

extern
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item);

extern
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest, uint8_t** dyn_arr_buf, int32_t offset);

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO