//Processing serial code with traffic light start..
//Two sensors on Arduino, two tracks. First sensor triggered indicates winner
//Processing App detects serial from winning sensor and Checkered flag ensues, also "Winner, lane one!" or whatever
//some way to reset (inByte?)
//start over!
//also need SPEED mode option trigger from Processing App. 
//then make WiFi version for Android

const int ledPin = 2;
const int ledPin2 = 3;
const int ldrPin = A0;
const int ldrPin2 = A1;
int num = 0;
long currentMillis = 0;
long previousMillis = 0;
long previousMillis2 = 0;

int inByte = 0;
boolean ready = true; //need to start ready because processing resets Arduino!

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);

  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, HIGH);
byte outByte = 0;

}

void loop() {
//  Serial.print("0");
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    //todo: check which byte! - doesn't really matter.. maybe toggle speed mode and VS mode!
    ready = true;
  }
  if(ready){
  int ldrStatus = analogRead(ldrPin);
  int ldrStatus2 = analogRead(ldrPin2);
//      Serial.println(ldrStatus); //testing

  if (ldrStatus < 12) {
    if (millis() - previousMillis > 100) {
      Serial.print("0"); // one or two, not both
//      Serial.println(num++);
//      Serial.println(millis() - previousMillis); //time from one lap to next!
      currentMillis = millis();
    }
    previousMillis = millis();
    ready = false; //reset
  }
//Serial.println(ldrStatus2); //testing
  if (ldrStatus2 < 17) {
    if (millis() - previousMillis > 100) {
      Serial.print("1"); //one or two, not both
//      Serial.println(num++);
//      Serial.print("TOTAL TIME: ");
//      Serial.println(millis() - currentMillis);
    }
    previousMillis = millis();
    ready = false; //reset
  }
  }

}
