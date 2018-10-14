Arduino code to allow custom control of the speed of an antminer s9 fan without causing error messages.

To Change Fan Speed:

Open serial communications with the arduino and set baud rate to 9600
Type number between 0 and 255 to correlate to the fan speed.
Press enter.

Set up:

Connect pin 3 of the arduino to the pwm input wire of fan 1. (Yellow)
Connect pin 9 of the arduino to the pwm input wire of fan 2. (Yellow)
Connect pin 5 of the arduino to the pwm sensor pin of the s9 on the first pin header. (Blue)
Connect pin 6 of the arduino to the pwm sensor pin of the s9 on the second pin header. (Blue)
Bridge the 5v power output pin of the first pin header to the 5v power input pin on fan 1. (Red)
Bridge the 5v power output pin of the second pin header to the 5v power input pin on fan 2. (Red)
Bridge the ground pin of the first pin header to the ground pin on fan 1. (Black)
Bridge the ground pin of the second pin header to the ground pin on fan 2. (Black)
Leave the pwm output pin from the first pin header disconnected.  (Yellow)
Leave the pwm output pin from the second pin header disconnected. (Yellow)
Leave the pwm sensor output from fan 1 disconnected. (Blue)
Leave the pwm sensor output from fan 2 disconnected. (Blue)