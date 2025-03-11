int pirPin = 2;  // PIR sensor output pin
int ledPin = 13; // LED pin 

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int motion = digitalRead(pirPin);
  if (motion == HIGH) {  // Motion detected
    Serial.println("Motion detected!");
    digitalWrite(ledPin, HIGH);
    delay(3000); // Delay to prevent multiple triggers
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("No motion");
  }
}
