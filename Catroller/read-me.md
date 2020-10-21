<strong>Demo Video:</strong>
https://youtu.be/y3gFuuZoAqY

<strong>Setup:</strong>
Catroller connects to the computer as a USB
keyboard and players bat the balls around to
execute keystrokes. The catroller sits on top of a box with a hole and a hatch in the back for storing the bread-
board and the long wires.

![Image of Yaktocat](https://octodex.github.com/images/yaktocat.png)

<strong>Github Teensey Code:</strong>
https://github.com/Arvi-56/AltArcade/blob/
master/Catroller/final-catroller.ino
The code sends press keystroke when the ball is on top of the photoresistors and re-
lease keystroke when the ball moves away. 
All the keystrokes and their location is ex-
plained in comments and can be changed

with the code at the top. At the moment the
controller is programmed to WASD and
Space.
To calibrate the controller for different rooms
with different lighting adjust the darkness
threshold to the minimum resistance that is
considered to be dark. Higher the threshold,
the darker it needs to be to send a keystroke.
Although if the threshold is too low it can
send keystrokes randomly.

<strong>Circut:</strong>
Uses photoresistors with 10k resistors to
send analog voltage differences according to
how much light there is. Also features LEDs
for lighting and an LED for feedback which
blinks when a keystroke is sent. The whole
rig is set up using a teensey, photoresistors,
leds, a breadboard, and jumpers. Red is
power, orange is ground, and blue is analog
pins (A0, 16, 17, 20, 22, 23)