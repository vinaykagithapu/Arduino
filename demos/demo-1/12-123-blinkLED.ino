/*
Blinks two LEDs.
One is redLED, it will blink first for 710ms in the loop
Another is blueLED, it will blink as 1,2.. 1,2,3 in the loop
*/

// Define variables
int blueLED = 12;
int redLED = 13;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin blueLED & redLED as an output.
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  delay(10);                      // wait for a 10 milli-seconds
  digitalWrite(redLED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(710);                      // wait for a 710 milli-seconds
  digitalWrite(redLED, LOW);   // turn the LED off by making the voltage LOW

  int i = 0;
  do {
    i++;
    delay(110);
    digitalWrite(blueLED, HIGH);
    delay(110);
    digitalWrite(blueLED, LOW);
  } while (i < 2);

  delay(140);
  int j = 0;
  do {
    j++;
    delay(80);
    digitalWrite(blueLED, HIGH);
    delay(80);
    digitalWrite(blueLED, LOW);
  } while (j < 3);

}
