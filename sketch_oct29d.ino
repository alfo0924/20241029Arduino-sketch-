#define R 32
#define G 33
#define B 25
#define buttonPin 26

int btnState;
int lastbtnState = HIGH;
int currentStep = 0;
int brightness = 0;

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
}

void loop() {
  // 讀取按鈕狀態
  btnState = digitalRead(buttonPin);

  // 檢測按鈕按下
  if (btnState == LOW && lastbtnState == HIGH) {
    currentStep++;    
    if (currentStep > 3) {
      currentStep = 0;
      analogWrite(R, 0);
      analogWrite(G, 0);
      analogWrite(B, 0);
    }
    brightness = 0;
    delay(50);  // 消除彈跳
  }
  lastbtnState = btnState;

  switch(currentStep) {
    case 0:  // R 從 0 到 200
      if (brightness < 200) {
        analogWrite(R, brightness);
        analogWrite(G, 0);
        analogWrite(B, 0);
        brightness++;
        delay(10);
      }
      break;
      
    case 1:  // G 從 0 到 255
      if (brightness < 255) {
        analogWrite(G, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    case 2:  // B 從 0 到 255
      if (brightness < 255) {
        analogWrite(B, brightness);
        brightness++;
        delay(10);
      }
      break;
      
    case 3:  // R 從 200 到 255，完成後自動重置
      if (brightness < 55) {
        analogWrite(R, brightness + 200);
        brightness++;
        delay(10);
      } else {
        // 當R達到255時，自動重置所有LED並回到初始狀態
        analogWrite(R, 0);
        analogWrite(G, 0);
        analogWrite(B, 0);
        currentStep = 0;
        brightness = 0;
      }
      break;
  }
}
