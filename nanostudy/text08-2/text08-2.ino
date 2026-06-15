const int AO_PIN = A0;
const float R0 = 10000.0;    // 板载分压固定电阻10k
const float B = 3950.0;       // 主流NTC参数，不对再换3435
const float T0 = 298.15;      // 25℃开尔文

float getTemp()
{
  int adc = analogRead(AO_PIN);
  float Vao = adc * 5.0 / 1023.0;
  // 正确NTC阻值计算
  float Rntc = R0 * Vao / (5.0 - Vao);

  // 标准B值温度公式
  float ratio = Rntc / R0;
  float tempK = 1.0 / ((log(ratio) / B) + (1.0 / T0));
  float tempC = tempK - 273.15;
  return tempC;
}

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int adcVal = analogRead(AO_PIN);
  float temp = getTemp();
  Serial.print("ADC:");
  Serial.print(adcVal);
  Serial.print("  Temp:");
  Serial.print(temp,1);
  Serial.println(" ℃");
  delay(500);
}