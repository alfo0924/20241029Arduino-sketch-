

### sketch_oct29a.ino：基礎 RGB LED 控制



```cpp
#define R 32
#define G 33
#define B 25

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}

void loop() {
  for(int i=0 ; i<255 ; i++) {
    analogWrite(R,i);
    delay(10);
  }
}
```

**功能特點**：
- 只控制紅色 LED
- 紅色 LED 會從 0 持續增加亮度到 255
- 沒有互動功能
- 循環執行，達到最大亮度後會重新開始

### sketch_oct29b.ino：進階按鈕控制 RGB LED


```cpp
#define R 32
#define G 33
#define B 25
#define buttonPin 26
```

**主要變數說明**：
- `buttonState`：記錄當前按鈕狀態
- `lastButtonState`：記錄上一次按鈕狀態
- `currentStep`：追蹤當前執行步驟
- `brightness`：控制 LED 亮度
- `increasing`：控制亮度增減方向

**功能特點**：
- 使用按鈕控制 LED 狀態切換
- 具有防彈跳處理（delay 50ms）
- 分步驟控制不同 LED：
  1. 紅色 LED 漸增至 200
  2. 綠色 LED 漸增至 255
  3. 藍色 LED 漸增至 255
  4. 紅色 LED 漸增至 255
  5. 全部重置為 0


