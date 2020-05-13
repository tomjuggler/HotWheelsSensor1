//add another sensor and we have it!!!!

const int ledPin = 2;
const int ldrPin = A0;
int num = 0;
long currentMillis = 0;
long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);


}

void loop() {
  int ldrStatus = analogRead(ldrPin);
  //  Serial.println(ldrStatus);
  if (ldrStatus < 8) {
    if (millis() - previousMillis > 100) {
      Serial.print("CAR!! ");
      Serial.println(num++);
      Serial.println(millis()-previousMillis); //time from one lap to next!
    }
    previousMillis = millis();
  }

}
