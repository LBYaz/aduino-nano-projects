#include <Arduino.h>
#line 1 "C:\\Users\\Intel\\Desktop\\nanostudy\\text01\\text01.ino"
#line 1 "C:\\Users\\Intel\\Desktop\\nanostudy\\text01\\text01.ino"
void setup();
#line 4 "C:\\Users\\Intel\\Desktop\\nanostudy\\text01\\text01.ino"
void loop();
#line 1 "C:\\Users\\Intel\\Desktop\\nanostudy\\text01\\text01.ino"
void setup() {
    pinMode(2, OUTPUT);
}
void loop() {
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);   
    delay(1000);
}
