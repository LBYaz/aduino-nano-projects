#include <Servo.h>
Servo myservo;
void setup() {
 myservo.attach(9);
 myservo.write(0);
 delay(1000); 
}

void loop() {
 myservo.write(15);
 delay(1000); 
 myservo.write(30);
 delay(1000); 
 myservo.write(45);
 delay(1000); 
 myservo.write(60);
 delay(1000); 
 myservo.write(75);
 delay(1000); 
 myservo.write(90);
 delay(1000); 
  myservo.write(75);
 delay(1000); 
 myservo.write(60);
 delay(1000); 
 myservo.write(45);
 delay(1000); 
 myservo.write(30);
 delay(1000); 
 myservo.write(15);
 delay(1000); 
 myservo.write(0);
 delay(1000); 
}