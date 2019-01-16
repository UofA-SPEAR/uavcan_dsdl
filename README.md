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
    - drive
        - 20000.DriveCommand.uavcan
            - uint4 wheel - ID of wheel
            - int12 speed - wheel speed (in mm/s)
        - 20001.DriveStatus.uavcan
            - uint4 wheel - ID of wheel
            - int12 speed - wheel speed (in mm/s)
    - arm
        - 20100.JointCommand.uavcan
            - uint4 joint - ID of joint
            - uint12 angle - angle (in tenths of a degree)
        - 20101.JointStatus.uavcan
            - uint4 joint - ID of joint
            - uint12 angle - angle (in tenths of a degree)

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
/path/to/libanard_dsdlc --output-dir libcanard_dsdlc_generated spear/ uavcan_dsdl/uavcan/
```

