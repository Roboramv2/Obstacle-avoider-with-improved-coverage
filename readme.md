# Obstacle Avoider with improved coverage
***

### Components used

1. Arduino Uno

2. Base of cheap RC car:
    * Removed inbuilt driver IC and radio.
    * Removed battery case.
    * Motors left in their housings with pins exposed for access.
  
3. SG-90:
    * Servo motor for controlled rotation
    * [Datasheet](http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf)

4. HC-SR04:
    * Measure distance using reflection of sound
    * [Datasheet](https://datasheetspdf.com/pdf-file/1380136/ETC/HC-SR04/1)

5. Wires, Cardboard and Tape

### Points noted:

* Without a driver IC, the motor does not get enough current from the digital output of the Arduino. This is overcome in this project by combining dual pins in parallel to double the current output of control signals. A possible alternative would be to use a BJT transistor to prove vcc directly and act as a switch.
* Usage of servo motor improves the angle covered by the ultrasonic sensor and also allows directional decisions based on observations instead of trial and error as seen in traditional obstacle avoiders, which cannot check their sides for possible routes.
* 9V alkaline batteries get depleted very fast due to use of servo and ultrasonic sensor, a lithium battery would prove to be a reliable replacement.
* Since we need to provide vcc for both components and there is only one 5V pin on the arduino, the HC-SR04 is connected to 3.3V instead, which is sufficient for its performance.
