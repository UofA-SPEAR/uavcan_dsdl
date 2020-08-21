// UAVCAN data structure definition.                                                                          +-+ +-+
//                                                                                                            | | | |
// AUTOGENERATED, DO NOT EDIT.                                                                                \  -  /
//                                                                                                              ---
//                                                                                                               o
// +------------------------------------------------------------------------------------------------------------------+
//
// Generator:
// nunavut-0.3.4 (serialization was enabled)
//
//
// Source File:
// /home/david/Documents/Clubs/SPEAR/uavcan_dsdl/public_regulated_data_types/uavcan/file/Path.1.0.uavcan
//
// Template:
// StructureType.j2
//
// Generated at:  2020-08-21 01:54:44.372823 UTC
// Is deprecated: no
// Fixed port ID: None
// Full name:     uavcan.file.Path
// Version:       1.0

#ifndef UAVCAN_FILE_PATH_INCLUDED
#define UAVCAN_FILE_PATH_INCLUDED

#include <nunavut/support/nunavut.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define uavcan_file_Path_1_0_SEPARATOR (47)
#define uavcan_file_Path_1_0_MAX_LENGTH (112)

typedef struct
{
    size_t path_length;
    uint8_t path[112];
} uavcan_file_Path_1_0;

/// The maximum capacity of uavcan_file_Path_1_0.path.
static inline size_t uavcan_file_Path_1_0_path_array_capacity(void)
{
    return (112U);
}

/// If true then uavcan_file_Path_1_0.path's length can vary otherwise it will
/// always be the same as its capacity.
static inline bool uavcan_file_Path_1_0_path_array_is_variable_length(void)
{
    return (true);
}

/// If uavcan_file_Path_1_0.path is a variable length array then this is the current
/// number of items populated in the array starting from index 0. If path is not a variable length array
/// then this is the same as its capacity.
static inline size_t uavcan_file_Path_1_0_path_array_length(
    const uavcan_file_Path_1_0* const instance)
{
    return (instance == NULL) ? 0 : instance->path_length;
}

/// Initialize an uavcan_file_Path_1_0 instance to default values.
/// No memory is allocated within this method.
/// Does nothing if @ref out_instance is NULL.
///
/// @param out_instance A structure instance to Initialize.
static inline void uavcan_file_Path_1_0_init(uavcan_file_Path_1_0* const out_instance)
{
    if (out_instance != NULL)
    {
        out_instance->path_length = 0;
    }
}

/// Contains the maximum number of bytes needed to serialize a(n) uavcan_file_Path_1_0
/// instance.
#define uavcan_file_Path_1_0_MAX_SERIALIZED_REPRESENTATION_SIZE_BYTES \
        (113U)


/// Serialization of uavcan_file_Path_1_0 instance into a byte array.
///
/// @param in_instance   A structure instance to serialize.
/// @param offset        Offset (in bits) of data type in message.
/// @param out_buffer    Output message buffer.
///
/// @returns             Size of encoded data (in bits)
static inline NunavutSignedBitLength uavcan_file_Path_1_0_serialize(const uavcan_file_Path_1_0* in_instance, NunavutUnsignedBitLength offset, uint8_t* const out_buffer)
{
    NunavutSignedBitLength rc = 0;

    if (out_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8[<=112]
    
        if (in_instance->path_length > 112)
        {
            return -NUNAVUT_ERR_INVALID_LEN;
        }
        nunavutSetUxx(out_buffer, offset, in_instance->path_length, 8);
        offset += 8;
        memcpy((void*) out_buffer + (offset>> 3), (void*)in_instance->path, in_instance->path_length * 1);
        offset += in_instance->path_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}

/// Deserialization of byte-array encoding into uavcan_file_Path_1_0 instance.
///
/// @param out_instance      Structure instance to write data to.
/// @param offset            Bit offset of structure in data buffer.
/// @param in_buffer         Message buffer to deserialize.
/// @param buf_size_bytes    Length of input buffer (in bytes) to avoid overflow.
///
/// @returns                 Size of decoded data (in bits)
static inline NunavutSignedBitLength uavcan_file_Path_1_0_deserialize(uavcan_file_Path_1_0* const out_instance, NunavutUnsignedBitLength offset, uint8_t* const in_buffer, const size_t buf_size_bytes)
{
    NunavutSignedBitLength rc = 0;

    if (in_buffer == NULL)
    {
        return -NUNAVUT_ERR_INVALID_BUF;
    }
    
    // Begin Structure: saturated uint8[<=112]
    
    out_instance->path_length = nunavutGetU8(in_buffer, buf_size_bytes, offset, 8);;
    offset += 8;
    if (out_instance->path_length > 112)
    {
        return -NUNAVUT_ERR_INVALID_LEN;
    }
    memcpy((void*)out_instance->path, (void*) in_buffer + (offset >> 3), out_instance->path_length * 1);
    offset += out_instance->path_length * 8;
    // End Structure: saturated uint8[<=112]

    return offset;
}


#ifdef __cplusplus
} /* End extern "C" */
#endif /* __cplusplus */
#endif /* UAVCAN_FILE_PATH */
