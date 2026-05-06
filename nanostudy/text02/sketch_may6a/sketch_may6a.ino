int p2 = 2;
int p3 = 3; 
void setup() {
    pinMode(2, OUTPUT);//数字2管脚输出，led
    pinMode(3,INPUT);//数字3管脚，按钮输入
    }
void loop() {
    boolean value = digitalRead(p3);
    if(value == HIGH){
    digitalWrite(p2, LOW);
    }
    else{
    digitalWrite(p2, HIGH);  
    }  
}