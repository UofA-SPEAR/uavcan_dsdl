# SPEAR UAVCAN Data Type Definitions #

This is the place to put any data type definitions you are using.
These should be confirmed by electrical and computer leads before being added.

To keep things consistent, different data types will be grouped into the different 100's.

- Drive is 20000 - 20099
- Arm is 20100 - 20199
- Science is 20200 - 20299

Before merging with master, ALWAYS test using at least one dsdl compiler.

## Naming

NOTE: First letter of a message type must be capitalized. As well, only use characters. (a-z etc)

## Structure ##

- spear
    - general
        - 20200.PpmMessage.uavcan
            - uint8 channel_num
            - int32[<=8] channel_data

## Generating code ##

### libuavcan ###

Make sure python is installed on your system.
Run 
```
bash $ libuavcan/libuavcan/dsdl_compiler/libuavcan_dsdlc spear "-O${HOME}/uavcan_vendor_specific_types"
```

### libcanard

Make sure pyuavcan is installed

Run

```
/path/to/libanard_dsdlc --outdir libcanard_dsdlc_generated spear/ uavcan_dsdl/uavcan/
```

