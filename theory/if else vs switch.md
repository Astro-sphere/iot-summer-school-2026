# if-else vs switch-case

if-else checks conditions one by one. It can handle ranges and more complex conditions, like value less than 300, or x greater than 5 and y less than 10. It is very flexible, but it becomes long and messy when there are many options to check.

switch-case checks a single variable against a list of fixed values, like case 1, case 2, case 3. It is cleaner and easier to read when you are comparing one variable to many exact values. But it only works for exact matches, not ranges or conditions, and each case needs a break statement.

So the main difference is that if-else is flexible and good for conditions and ranges, while switch-case is neater and better when one variable has many fixed options.

Where they are used in IoT:

if-else is used for checking sensor ranges. For example, in my street light program I used if value less than 300 to turn the LED on, else turn it off.

switch-case is used for handling commands or states. For example, a command received over Bluetooth where R turns on the red LED and G turns on the green LED, or switching between states like IDLE, RUNNING and STOPPED in a state machine.
