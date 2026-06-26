int AO = A0;
int DO = 2;
void setup(){
  Serial.begin(9600);默认
  pinMode(DO,INPUT);
}
void loop(){
  int adc = analogRead(AO);
  int doState = digitalRead(DO);
  Serial.print("ADC原始值：");
  Serial.print(adc);
  Serial.print(" DO电平：");
  Serial.println(doState);
  delay(500);
}