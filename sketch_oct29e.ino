#define R 32
#define G 33
#define B 25
#define POT_PIN 13   // 可變電阻的腳位
#define BUTTON_PIN 26 // 按鈕的腳位

int number = 1;
bool flag12 = LOW;
int change = 1;

// 儲存各顏色的亮度值
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);

  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);

  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 設置按鈕為輸入模式並使用內建上拉電阻
  pinMode(POT_PIN, INPUT);            // 設置可變電阻為輸入模式
}

void loop() {
  // 讀取按鈕狀態
  int p12 = digitalRead(BUTTON_PIN);

  // 切換顏色
  if (p12 == LOW && flag12 == LOW) {
    number++;
    flag12 = HIGH;
    delay(200);  // 防抖延遲
  } else if (p12 == HIGH && flag12 == HIGH) {
    flag12 = LOW;
  }

  // 計算當前顏色
  change = number % 3 + 1;

  // 讀取可變電阻的數值，將其映射到 0-255 的範圍
  int potValue = analogRead(POT_PIN);
  int brightness = map(potValue, 0, 4095, 0, 255);

  // 根據當前的顏色狀態，調整對應的 LED 亮度
  switch (change) {
    case 1:  // 控制紅色
      redValue = brightness;
      analogWrite(R, redValue);
      analogWrite(G, greenValue);
      analogWrite(B, blueValue);
      break;
    case 2:  // 控制綠色
      greenValue = brightness;
      analogWrite(G, greenValue);
      analogWrite(R, redValue);
      analogWrite(B, blueValue);
      break;
    case 3:  // 控制藍色
      blueValue = brightness;
      analogWrite(B, blueValue);
      analogWrite(R, redValue);
      analogWrite(G, greenValue);
      break;
  }

  delay(10);  // 稍微延遲，以減少亮度變化的頻率
}
