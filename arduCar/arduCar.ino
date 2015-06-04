/* arduCar.ino 
   A program for controlling an RC car hacked with an arduino.
   Connect the two leads from the steering motor to pins 
*/

int driveFWpin = 8;
int driveBWpin = 9;
int steerLEpin = 6;
int steerRIpin = 7;
int driveSpeedPin = 10;
void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

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
