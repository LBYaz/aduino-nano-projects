// 引脚常量定义
const int AO_PIN = A0;
const int LED_PIN = 13;
const int BEEP_PIN = 12;

// NTC固定参数
const float R0 = 10000.0;
const float B = 3950.0;
const float T0 = 298.15;

// 计时标记变量
unsigned long beepStartTime = 0;
bool isBeeping = false;

// 接收ADC数值计算温度
float getTemp(int adc)
{
  float Vao = adc * 5.0 / 1023.0;
  float Rntc = R0 * Vao / (5.0 - Vao);
  float ratio = Rntc / R0;
  float tempK = 1.0 / ((log(ratio) / B) + (1.0 / T0));
  float tempC = tempK - 273.15;
  return tempC;
}

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);
  // 初始状态灯、蜂鸣器关闭
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BEEP_PIN, LOW);
}

void loop()
{
  // 只读取一次温度ADC
  int adcVal = analogRead(AO_PIN);
  float temp = getTemp(adcVal);

  Serial.print("ADC：");
  Serial.print(adcVal);
  Serial.print(" 温度：");
  Serial.print(temp,1);
  Serial.println(" ℃");

  unsigned long now = millis(); // 获取开机总毫秒时间

  if (!isBeeping) // 当前不在蜂鸣倒计时状态
  {
    if (temp > 30.0) // 温度大于30℃触发
    {
      digitalWrite(LED_PIN, HIGH);  // 13脚灯亮起
      digitalWrite(BEEP_PIN, HIGH); // 蜂鸣器开启
      beepStartTime = now;           // 记录触发时间
      isBeeping = true;              // 标记进入鸣叫状态
    }
  }
  else // 正在鸣叫中，判断是否满10秒
  {
    if (now - beepStartTime >= 10000) // 10000毫秒=10秒
    {
      digitalWrite(LED_PIN, LOW);
      digitalWrite(BEEP_PIN, LOW);
      isBeeping = false; // 结束鸣叫，恢复等待下次超温
    }
  }

  delay(500);
}