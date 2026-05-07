int p2 = 2;
int p3 = 3;
int p10 = 10; 
void setup() {
    pinMode(2, OUTPUT);//数字2管脚输出，led
    pinMode(3,OUTPUT);
    pinMode(10,INPUT);//数字10管脚，振动模块输入
    }
void loop() {
    boolean value = digitalRead(p10);
    if(value == HIGH){
    digitalWrite(p2, HIGH);
    digitalWrite(p3, HIGH);
    }
    else{
    digitalWrite(p2, LOW);  
    digitalWrite(p3, LOW);
    }  
}