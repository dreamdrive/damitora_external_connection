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
int sensorValue[13];  // 取得したアナログの値 (0から1023までの整数値)

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
  for (int i = 0; i < 13; i++) {
    sensorValue[i] = map(analogRead(A0 + i), 0, 1023, -1800, 1800);
  }

  // 送信データ生成
  Serial.print("[");
  for (uint8_t i = 0; i < 13; i++) {
    Serial.print(sensorValue[i]);
    if (i != 12) Serial.print(",");
  }
  Serial.println("]");

  // 20Hz以下に抑えておく(実際はシリアルの送信の時間も加算されてもっと遅くなる)
  delay(50);

}
