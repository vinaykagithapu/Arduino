#define sensor 2
#define red 3
 
void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(red,OUTPUT);
}
 
void loop() {
  bool value = digitalRead(sensor);
  if(value == HIGH) {
    digitalWrite(red, HIGH);
    Serial.println("Line detected");
  } else {
    digitalWrite(red, LOW);
    Serial.println("Line NOT detected");
  }
  delay(500);
}