const int sensorPin = 2;  
const int relayPin = 3;    

void setup() {
  pinMode(sensorPin, INPUT); 
  pinMode(relayPin, OUTPUT);   
  digitalWrite(relayPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  if (sensorState == HIGH) {
    digitalWrite(relayPin, HIGH);
    Serial.println("No obstacle detected → Pump ON");
  } else {
    digitalWrite(relayPin, LOW);
    Serial.println("Obstacle detected → Pump OFF");
  }
  
  delay(100);  
}
