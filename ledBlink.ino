// A PROGRAM TO SIMULATE A FIVE SIDED DIE

// define 5 leds and a button
int BTN = 13;
byte ledPins[6] = { 4, 5, 6, 7, 8 };

void setup() {
  Serial.begin(9600);

  // set leds to output
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(BTN, INPUT_PULLUP);
  randomSeed(analogRead(0));

}

void loop() { 
  int time = 1;
  int randMult = random(1, 20);
  int randTime = random(200, 400);

  if (digitalRead(BTN) == false) {
    Serial.print("Time limit: ");
    Serial.println(randTime);
    int i = 0;
    while (time < randTime) {
      digitalWrite(ledPins[i], HIGH);
      delay(time);
      digitalWrite(ledPins[i], LOW);
      Serial.println(time);

      if (i == 4) {
        i = 0;
      } else {
        i += 1;
      }

      time += randMult;
    }
    digitalWrite(ledPins[i], HIGH);
  }
    
}
