# System States

A system state is the current condition or mode that a device is in at a given moment. Instead of doing everything at once, the system stays in one state at a time and behaves differently depending on which state it is in. It moves from one state to another when a certain event happens, and this is called a state transition.

For example, a traffic light has the states red, yellow and green. It stays in one state at a time and switches to the next after a timer. Similarly, a vending machine has states like idle, coin inserted, item selected and dispensing.

How to manage them:

The usual way is to store the current state in a variable, often a number or a named list of states like IDLE, RUNNING and STOPPED. Then switch-case or if-else is used to decide what the device should do in each state, with a separate block of code for each one. The state is changed when an event happens, such as a button press, a sensor reading or a timer finishing, by updating the state variable to the next state. This whole design is called a state machine, and it keeps the code organised and predictable instead of tangled.

Why it matters in IoT:

IoT devices often wait for events and then react, like a button press, a sensor crossing a threshold, or a network message. Managing states clearly makes the device reliable and easier to debug, because you always know exactly what mode it is in and what it should do next. For example, my reaction game moves through phases: waiting, then green light on, then measuring the reaction time.
