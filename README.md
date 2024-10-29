

# sketch_oct29a.ino | 基礎 RGB LED 控制



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

# sketch_oct29b.ino | 進階按鈕控制 RGB LED


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





# sketch_oct29d.ino  |  按鈕控制程式

### 硬體定義
```cpp
#define R 32        // 紅色 LED 腳位
#define G 33        // 綠色 LED 腳位
#define B 25        // 藍色 LED 腳位
#define buttonPin 26 // 按鈕腳位
```

### 全域變數
```cpp
int btnState;              // 當前按鈕狀態
int lastbtnState = HIGH;   // 上一次按鈕狀態
int currentStep = 0;       // 當前執行步驟
int brightness = 0;        // LED 亮度值
```

### 程式功能說明

**初始化設定**
- 設定串口通訊速率為 9600
- 設定 RGB LED 腳位為輸出模式
- 設定按鈕腳位為上拉輸入模式
- 初始化所有 LED 為關閉狀態

**主要功能流程**
1. **步驟 0**：紅色 LED 漸增
   - 亮度從 0 增加到 200
   - 其他 LED 保持關閉

2. **步驟 1**：綠色 LED 漸增
   - 亮度從 0 增加到 255
   - 保持紅色 LED 狀態

3. **步驟 2**：藍色 LED 漸增
   - 亮度從 0 增加到 255
   - 保持其他 LED 狀態

4. **步驟 3**：紅色 LED 完成漸增並自動重置
   - 紅色 LED 從 200 增加到 255
   - 達到最大值後自動重置所有 LED
   - 返回步驟 0

**按鈕控制**
```cpp
if (btnState == LOW && lastbtnState == HIGH) {
    currentStep++;    
    if (currentStep > 3) {
        currentStep = 0;
        // 重置所有 LED
    }
    brightness = 0;
    delay(50);  // 防彈跳延遲
}
```

**LED 控制範例（步驟 0）**
```cpp
if (brightness < 200) {
    analogWrite(R, brightness);
    analogWrite(G, 0);
    analogWrite(B, 0);
    brightness++;
    delay(10);
}
```

### 技術特點
- 使用 `switch-case` 結構管理不同步驟
- 實現按鈕防彈跳機制
- 使用 `analogWrite` 實現 LED 漸變效果
- 自動循環功能，無需手動重置
- 每個 LED 獨立控制


