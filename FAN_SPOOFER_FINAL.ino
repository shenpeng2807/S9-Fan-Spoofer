//Noah Page
//S9 Fan Faker

#include <EEPROM.h>
int epromAddress = 0; //The address (think array value) that the current desired fan speed eprom will be stored at
int currentSpeed = 0; //The desired fan speed (local)
//52 is the correct PWM to fake the s9 at
int counter = 0;
void setup() {
  Serial.begin(9600); //Begins serial communication at 9600 bauds
  Serial.setTimeout(1000); //Wait 1 second
  pinMode(3, OUTPUT); //To send to the new fan to tell it how fast to spin
  pinMode(9, OUTPUT); //To send to the new fan to tell it how fast to spin
  pinMode(5, OUTPUT); //To send to the board to pretend that its spinning X speed
  pinMode(6, OUTPUT); //To send to the board to pretend that its spinning X speed
  Serial.println("Noah's Antminer Fan Spoofer V1.7");
  Serial.println("ENTERING FAN SPOOF MODE");
  analogWrite(6, 52); //Start sending the board the fake speed
  analogWrite(5, 52); //Start sending the board the fake speed
  EEPROM.get(epromAddress, currentSpeed); //Retrieve the eprom and set to int current speed
  currentSpeed = currentSpeed  + 256;
}
void loop() {
  analogWrite(6, 52); //Keep sending the board the fake speed
  analogWrite(5, 52); //Keep sending the board the fake speed
  analogWrite(3, currentSpeed); //Keep sending the real fan the desired speed
  analogWrite(9, currentSpeed); //Keep sending the real fan the desired speed
  Serial.println("Please enter the new fan speed multiplier between 1 (off) and 255 (full speed)");
  int input3 = Serial.parseInt(); //int input 2 = whatever the usr types in
  if (input3 > 0 && input3 < 256) {
    EEPROM.write(epromAddress, input3); //Set the eprom desired fan speed to input2
    EEPROM.get(epromAddress, currentSpeed);
    currentSpeed = currentSpeed  + 256;
    Serial.println("Fan speed adjustment successful");
  }
  //Serial.println(currentSpeed); //For debugging Only!

}
