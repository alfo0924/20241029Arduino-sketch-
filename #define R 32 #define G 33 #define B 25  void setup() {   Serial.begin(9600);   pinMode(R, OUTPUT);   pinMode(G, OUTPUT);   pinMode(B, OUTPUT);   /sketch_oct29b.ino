#define R 32
#define G 33
#define B 25
#define buttonPin 26  // 定義按鈕腳位，請根據實際連接修改

int buttonState;          // 當前按鈕狀態
int lastButtonState = HIGH;   // 上一次按鈕狀態
int currentStep = 0;      // 當前執行步驟
int brightness = 0;       // LED亮度值
bool increasing = true;   // 控制亮度是否在增加

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // 初始化所有LED為關閉狀態
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}

void loop() {
  // 讀取按鈕狀態
  buttonState = digitalRead(buttonPin);

  // 檢測按鈕按下
  if (buttonState == LOW && lastButtonState == HIGH) {
    currentStep++;    // 切換到下一個步驟
    if (currentStep > 4) {
      currentStep = 0;  // 重置步驟
      // 重置所有LED
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
    }
    brightness = 0;     // 重置亮度值
    increasing = true;  // 重置方向為增加
    delay(50);         // 消除彈跳
  }
  lastButtonState = buttonState;

  // 根據當前步驟執行相應的LED控制
  switch (currentStep) {
    case 1:  // R增加到200
      if (increasing && brightness < 200) {
        analogWrite(R, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    case 2:  // G增加到255
      if (increasing && brightness < 255) {
        analogWrite(G, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    case 3:  // B增加到255
      if (increasing && brightness < 255) {
        analogWrite(B, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    case 4:  // R增加到255
      if (increasing && brightness < 255) {
        analogWrite(R, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    default:  // 初始狀態，所有LED關閉
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
      brightness = 0;
      break;
  }
}
