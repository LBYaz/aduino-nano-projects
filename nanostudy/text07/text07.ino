int digitalInPin = 7;
int ledPin = 13;
void setup() {
  pinMode(digitalInpin,INPUT);
  pinMode(ledPin,OUTPUT);
}
void loop() {
  boolean stat = digitalRead(digitalInPin);
  if(stat == HIGH){
  digitalWrite(ledPin,LOW);
  }else{
  digitalWrite(ledPin,HIGH);
  }

}
