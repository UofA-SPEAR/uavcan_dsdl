# Message Types #

This document will attempt to document all message types used in the rover and the various
bits of knowledge required to use them.

_TODO:_

- GPS message type
- accel/magnetometer message type
- RC message type

## Arm Messages ##

NodeIDs shall be assigned from 30-39, starting from the base of the arm, increasing to the actuator on the end.

Commands used shall be spear/arm/20100.JointCommand.uavcan, and spear/arm/20101.JointStatus.uavcan.
JointCommands will be sent TO the joints, whereas the JointStatus commands will be published
from the joints periodically.

Joint Statuses have a priority of 12.
Joint Commands have a priority of 13.

## Drive Messages ##

NodeIDs shall be assigned back to front, from 20-29.

Message types shall be spear/drive/20000.DriveCommand.uavcan, and spear/drive/20001.DriveStatus.uavcan.
Same idea as the arm.

Drive Statuses have a priority of 12.
Drive Commands have a priority of 13.

## Status Messages ##

All nodes will publish NodeStatus messages at least once per second.
If a node does not publish in two seconds, it can be considered offline.

The science sensor board (w/ GPS, IMU, and servo outputs) will be node # 10.
- This will publish GPS data on <GPS message type> on priority 10.
- This will publish accel/magnetometer data on <insert data type> on priority 10.
- This will listen to uavcan/equipment/actuator/Command.uavcan on priority 11.
    - Actuators will be numbered 0-n for n servos on the board.

The RC input board will be node # 11. 
- This will publish RC input data on the <insert RC message type>, priority 15.

The battery input boards will be node IDs 40-45 (Comp. batteries 1 & 2, Drive batteries 1-4).
- These will publish battery info using uavcan/equipment/power/1092.BatteryInfo.uavcan
priority 20.
- Based on settings, these boards will shut off battery power on arm/disarm messages.

Indication boards will be anonymous and not publish status messages.
However, they will listen to status messages, based on settings.
(actually maybe they should have IDs so we can set these things over CAN).
