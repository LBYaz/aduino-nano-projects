// 1. 包含新版红外库的头文件
#include <IRremote.hpp>

// 2. 定义引脚名字（方便改，一看就懂）
const int irReceiverPin = 7;  // 红外接收器信号脚接 D7
const int ledPin = 13;         // 板载LED脚 D13

// 3.  setup：只运行一次（初始化）
void setup() {
  pinMode(ledPin, OUTPUT);     // 把LED脚设置为输出模式
  Serial.begin(9600);          // 开启串口，波特率9600（看打印信息）
  IrReceiver.begin(irReceiverPin); // 启动红外接收功能
}

// 4. loop：不断重复运行
void loop() {
  // 如果**接收到了红外信号**
  if (IrReceiver.decode()) {

    // 把收到的红外码打印到串口监视器（方便你看）
    Serial.print("收到红外码: 0x");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // 判断：是不是我们要的那个按键码
    if (IrReceiver.decodedIRData.decodedRawData == 0xBA45FF00) {
      digitalWrite(ledPin, HIGH);  // 是 → 点亮LED
    } else {
      digitalWrite(ledPin, LOW);   // 不是 → 熄灭LED
    }

    IrReceiver.resume(); // 准备接收下一个信号
  }
}