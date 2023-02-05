//
// M5Stack 8Angle Potentiometer Unit を使用して だみとら2 の入力装置を自作するサンプルスケッチ
// 作者 : みっちー
// MIT license
//
// 【内容】
//  だみとら2に接続して、M5Stack 8Angle Potentiometer Unitのポテンショメーターを触ると関節が動きます。
//  ポテンショメータが8chしかないので、デジタルスイッチで切り替えて、8chずつ制御します。
//
// 【構成】
// Arduino + Grove Base Shield V2 + M5Stack 8Angle Potentiometer Unit
//
// M5Stack用のライブラリを使用しています。(元のリポジトリはこちら↓)
// M5Stack 8Angle Potentiometer Unit mit STM32F030 (MIT license)
// https://github.com/m5stack/M5Unit-8Angle
//

#include "M5_ANGLE8.h"

M5_ANGLE8 angle8;
int16_t send_value[13];

// LEDのコントロール 1
void TaskRGBLED_1() {
  angle8.setLEDColor(0, 0xffff00, 10);  // 黄色
  angle8.setLEDColor(1, 0xffff00, 10);  // 黄色
  angle8.setLEDColor(2, 0xffff00, 10);  // 黄色
  angle8.setLEDColor(3, 0x00ff00, 10);  // 緑色
  angle8.setLEDColor(4, 0x00ff00, 10);  // 緑色
  angle8.setLEDColor(5, 0x00ff00, 10);  // 緑色
  angle8.setLEDColor(6, 0x00ff00, 10);  // 緑色
  angle8.setLEDColor(7, 0x00ff00, 10);  // 緑色
  angle8.setLEDColor(8, 0xff0000, 10);  // 赤色
}

// LEDのコントロール 2
void TaskRGBLED_2() {
  angle8.setLEDColor(0, 0xffffff, 0);   // 消灯
  angle8.setLEDColor(1, 0xffffff, 0);   // 消灯
  angle8.setLEDColor(2, 0xffffff, 0);   // 消灯
  angle8.setLEDColor(3, 0xff0000, 10);  // 赤色
  angle8.setLEDColor(4, 0xff0000, 10);  // 赤色
  angle8.setLEDColor(5, 0xff0000, 10);  // 赤色
  angle8.setLEDColor(6, 0xff0000, 10);  // 赤色
  angle8.setLEDColor(7, 0xff0000, 10);  // 赤色
  angle8.setLEDColor(8, 0x0000ff, 10);  // 青色
}

void TaskADC12_1(uint16_t delay_t) {

  int16_t sensorValue = 0;
  uint16_t adc_v = 0;

  for (uint8_t i = 0; i < ANGLE8_TOTAL_ADC; i++) {
    adc_v = angle8.getAnalogInput(i, _12bit);
    sensorValue = map(adc_v, 0, 4096, -1800, 1800);
    send_value[i] = sensorValue;
  }
}

void TaskADC12_2(uint16_t delay_t) {

  int16_t sensorValue = 0;
  uint16_t adc_v = 0;

  for (uint8_t i = 3; i < ANGLE8_TOTAL_ADC; i++) {
    adc_v = angle8.getAnalogInput(i, _12bit);
    sensorValue = map(adc_v, 0, 4096, -1800, 1800);
    send_value[i+5] = sensorValue;
  }
}

void setup() {

  // start serial port at 115200bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  while (!angle8.begin(ANGLE8_I2C_ADDR)) {
    Serial.println("angle8 Connect Error");
    delay(100);
  }
}

void loop() {

  if (angle8.getDigitalInput()){
    TaskADC12_1(100);
    TaskRGBLED_1();
  } else{
    TaskADC12_2(100);
    TaskRGBLED_2();
  }

  // 送信データ生成
  Serial.print("[");
  for (uint8_t i = 0; i < 13; i++) {
    Serial.print(send_value[i]);
    if (i != 12) Serial.print(",");
  }
  Serial.println("]");
  
}
