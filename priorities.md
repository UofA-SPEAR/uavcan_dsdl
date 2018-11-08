# UAVCAN Priority Levels #

The UAVCAN specification defines a 5-bit priority level.
This priority level comes before all other fields in the CAN ID field,
because of this, this priority pre-empts any random or semi-random ordering
that would happen because of other fields.

Functionally, this means messages with a higher priority will be transmitted
instead of a lower priority message if there is a conflict.

## Various levels we should care about ##

This is just a brainstorm here.
No order.

- NodeStatus updates
- Location/position data
- system data (voltage etc.)
- actuator status
- actuator commands
- REALLY IMPORTANT actuator commands
- REALLY IMPORTANT status updates
- armed/disarmed
- random commands (e.g. indicator)
- panic messages (will we ever implement these? who knows)
- FUTURE stuff - like CAN command line or firmware update


### General heirarchy ###

Maybe you disagree. Tell me.

- FUTURE stuff - like CAN command line or firmware update
- NodeStatus updates
- random commands (e.g. indicator)
- Location/position data
- system data (voltage etc.)
- actuator status
- actuator commands
- armed/disarmed
- REALLY IMPORTANT actuator commands
- REALLY IMPORTANT status updates
- panic messages (will we ever implement these? who knows)

Drive before arm.

5 bits is 2^5 is 32 levels (0-31).

Ranges:

#### 0-9

low level stuff. NodeStatus should always be 0 for example.

If the system could run without these, they go here.

#### 10-19

System level commands and status updates.

System needs these to operate, but they can be preempted by another category.

### 20-31

TOP LEVEL. This stuff NEEDS to be listened to. Like the arm/disarm messages, important actuator commands (like if you reaaaaaallly need to stop a wheel).
Panic messages so systems know if something is seriously wrong.


## Conclusion

This is a suggestion for now. This should be discussed with someone else before we decide.
Buut, this does have to be decided. Just for consistency.

Also we need to enumerate every number.
