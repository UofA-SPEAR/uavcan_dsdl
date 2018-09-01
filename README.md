# SPEAR UAVCAN Data Type Definitions #

This is the place to put any data type definitions you are using.
These should be confirmed by electrical and computer leads before being added.

## Structure ##

- spear
    - drive
        - 20000.DriveCommand.uavcan
            - uint4 wheel - ID of wheel
            - int12 speed - wheel speed (in mm/s)
        - 20001.DriveStatus.uavcan
            -TBD
    - arm
        - 20100.JointCommand.uavcan
            - uint4 joint - ID of joint
            - uint12 angle - angle (in tenths of a degree)
        - 20101.JointStatus.uavcan
            -TBD
