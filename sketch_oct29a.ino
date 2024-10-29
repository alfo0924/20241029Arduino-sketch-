#define R 32
#define G 33
#define B 25

void setup() {
  Serial.begin(9600);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  // pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(R,LOW);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
}

void loop() {
for(int i=0 ; i<255 ; i++)
{
  analogWrite(R,i);
  delay(10);
}

}
