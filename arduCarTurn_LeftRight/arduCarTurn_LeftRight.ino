/* arduCarMove_Ten.ino 
   A program for controlling an RC car hacked with an arduino.
   Moves the car forward for ten seconds
   Please note that this program does not contain anything that makes the car
   move. It only contains the base code.
   
   Author: Aidan Sciortino
   Contributors:
   
   
   **Components Necessary**
   -Arduino Uno
   -L293D Dual Half-H bridge Motor Driver
   -Cheap RC car
   -Wires
   -Connection Method (breadboard, perfboard and solder, etc)
   
   Connect the two leads from the steering motor to the output pins 4Y and 3Y on the L293D
   Connect the two leads from the drive motor to pins 1Y and 2Y on the L293D
   Connect 1,2EN on the L293D to pin 10 on the Arduino Uno
   Connect 3,4EN to +5V
   Connect 1A to Pin 8 on the Arduino
   Connect 2A to pin 9 on the Arduino
   Connect 4A to pin 6 on the Arduino
   Connect 5A to pin 7 on the Arduino
   Connect VCC1 to +5V
   Connect all Ground pins to ground.
   Connect VCC2 to whatever voltage your original Car used. (You can tell by looking at the battery)
*/
//Make variables that correspond with output pins. Change these numbers if you use different Pins
const int driveFWpin = 9; //1A on the L293D
const int driveBWpin = 8; //2A on the L293D
const int steerLEpin = 7; //4A on the L293D
const int steerRIpin = 6; //3A on the L293D
const int driveSpeedPin = 10; //1,2EN on the L293D

void setup() {
  //Set up all switching pins as outputs
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
 steerLeft();
 delay(1000);
 stopSteer();
 steerRight();
 delay(1000);
 stopSteer();
}
void driveForward(int fastness) {
 digitalWrite(driveBWpin, LOW);
 analogWrite(driveSpeedPin, fastness);
 digitalWrite(driveFWpin, HIGH);
}
void driveBackward(int fastness) {
 digitalWrite(driveFWpin, LOW);
 analogWrite(driveSpeedPin, fastness);
 digitalWrite(driveBWpin, HIGH);
}
void steerRight(){
  digitalWrite(steerLEpin, LOW);
  digitalWrite(steerRIpin, HIGH);
}
void steerLeft(){
  digitalWrite(steerRIpin, LOW);
  digitalWrite(steerLEpin, HIGH);
}
void stopSteer(){
  digitalWrite(steerRIpin, LOW);
  digitalWrite(steerLEpin, LOW);
}
void stopDrive(){
 digitalWrite(driveFWpin, LOW);
 digitalWrite(driveBWpin, LOW); 
}
