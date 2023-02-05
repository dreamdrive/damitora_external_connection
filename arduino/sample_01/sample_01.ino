//
// 13個のポテンショメーターを使用して だみとら2 の入力装置を自作するサンプルスケッチ
// 作者 : みっちー
// MIT license
//
// 【内容】
//  だみとら2に接続して、13個のポテンショメーターを触ると関節が動きます。
//
// 【構成】
// Arduino Mega + 13個のポテンショメーター(ボリューム)
// ボリュームを使用する際はBカーブを使用すること
// オススメ : 高回転寿命形ポテンショメータ（コネクタケーブル付）　Ｂ１０３　１０ｋΩ（２個入） ／秋月通商
//


int ledPin = 13;      // 動作確認用LED
bool led_f = false;   // LED点灯のフラグ

// だみとら用に13ポートのAD変換ポート番号の確保
int sensorPin00 = A0;    // select the input pin for the potentiometer
int sensorPin01 = A1;    // select the input pin for the potentiometer
int sensorPin02 = A2;    // select the input pin for the potentiometer
int sensorPin03 = A3;    // select the input pin for the potentiometer
int sensorPin04 = A4;    // select the input pin for the potentiometer
int sensorPin05 = A5;    // select the input pin for the potentiometer
int sensorPin06 = A6;    // select the input pin for the potentiometer
int sensorPin07 = A7;    // select the input pin for the potentiometer
int sensorPin08 = A8;    // select the input pin for the potentiometer
int sensorPin09 = A9;    // select the input pin for the potentiometer
int sensorPin10 = A10;    // select the input pin for the potentiometer
int sensorPin11 = A11;    // select the input pin for the potentiometer
int sensorPin12 = A12;    // select the input pin for the potentiometer

// 取得したアナログの値 (0から1023までの整数値)
int sensorValue00 = 0;  // variable to store the value coming from the sensor
int sensorValue01 = 0;  // variable to store the value coming from the sensor
int sensorValue02 = 0;  // variable to store the value coming from the sensor
int sensorValue03 = 0;  // variable to store the value coming from the sensor
int sensorValue04 = 0;  // variable to store the value coming from the sensor
int sensorValue05 = 0;  // variable to store the value coming from the sensor
int sensorValue06 = 0;  // variable to store the value coming from the sensor
int sensorValue07 = 0;  // variable to store the value coming from the sensor
int sensorValue08 = 0;  // variable to store the value coming from the sensor
int sensorValue09 = 0;  // variable to store the value coming from the sensor
int sensorValue10 = 0;  // variable to store the value coming from the sensor
int sensorValue11 = 0;  // variable to store the value coming from the sensor
int sensorValue12 = 0;  // variable to store the value coming from the sensor

void setup() {

  // start serial port at 115200bps:
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // LEDピンの出力
  pinMode(ledPin, OUTPUT);

}

void loop() {

  // LEDの点滅 (動作確認用LED)
  led_f = !led_f;
  digitalWrite(ledPin, led_f);   // turn the LED on (HIGH is the voltage level)

  // アナログの値取得 * 13
  sensorValue00 = map(analogRead(sensorPin00), 0, 1023, -1800, 1800);
  sensorValue01 = map(analogRead(sensorPin01), 0, 1023, -1800, 1800);
  sensorValue02 = map(analogRead(sensorPin02), 0, 1023, -1800, 1800);
  sensorValue03 = map(analogRead(sensorPin03), 0, 1023, -1800, 1800);
  sensorValue04 = map(analogRead(sensorPin04), 0, 1023, -1800, 1800);
  sensorValue05 = map(analogRead(sensorPin05), 0, 1023, -1800, 1800);
  sensorValue06 = map(analogRead(sensorPin06), 0, 1023, -1800, 1800);
  sensorValue07 = map(analogRead(sensorPin07), 0, 1023, -1800, 1800);
  sensorValue08 = map(analogRead(sensorPin08), 0, 1023, -1800, 1800);
  sensorValue09 = map(analogRead(sensorPin09), 0, 1023, -1800, 1800);
  sensorValue10 = map(analogRead(sensorPin10), 0, 1023, -1800, 1800);
  sensorValue11 = map(analogRead(sensorPin11), 0, 1023, -1800, 1800);
  sensorValue12 = map(analogRead(sensorPin12), 0, 1023, -1800, 1800);

  Serial.print("["); // スタートは"["
  Serial.print(sensorValue00);
  Serial.print(",");
  Serial.print(sensorValue01);
  Serial.print(",");
  Serial.print(sensorValue02);
  Serial.print(",");
  Serial.print(sensorValue03);
  Serial.print(",");
  Serial.print(sensorValue04);
  Serial.print(",");
  Serial.print(sensorValue05);
  Serial.print(",");
  Serial.print(sensorValue06);
  Serial.print(",");
  Serial.print(sensorValue07);
  Serial.print(",");
  Serial.print(sensorValue08);
  Serial.print(",");
  Serial.print(sensorValue09);
  Serial.print(",");
  Serial.print(sensorValue10);
  Serial.print(",");
  Serial.print(sensorValue11);
  Serial.print(",");
  Serial.print(sensorValue12);
  Serial.println("]"); // 最後は"]"と改行コードで終わる

  // 20Hz以下に抑えておく(実際はシリアルの送信の時間も加算されてもっと遅くなる)
  delay(50);

}
