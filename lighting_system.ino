int irPin1 = 2;
int irPin2 = 3;
int count = 0;
boolean state1 = true;
boolean state2 = true;
int i = 1;

// Define LED pins
int ledPins[] = {4, 5, 6, 7, 8, 9};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

// LDR
const int ldrPin = A0;
const int sequenceTime = 1000;

void setup() {
  Serial.begin(9600);

  // Setup IR sensor pins
  pinMode(irPin1, INPUT);
  pinMode(irPin2, INPUT);

  // Setup LED pins
  for (int j = 0; j < numLeds; j++) {
    pinMode(ledPins[j], OUTPUT);
    digitalWrite(ledPins[j], LOW); // Start with LEDs off
  }

  pinMode(ldrPin, INPUT);
}

void loop() {
  if (!digitalRead(irPin1) && i == 1 && state1) {
    delay(100);
    i++;
    state1 = false;
  }
  else if (!digitalRead(irPin2) && i == 2 && state2) {
    Serial.println("Entering inside the room");
    delay(100);
    i = 1;
    count++;
    Serial.print("No. of people inside room: ");
    Serial.println(count);
    state2 = false;
  }
  else if (!digitalRead(irPin2) && i == 1 && state2) {
    delay(100);
    i = 2;
    state2 = false;
  }
  else if (!digitalRead(irPin1) && i == 2 && state1) {
    Serial.println("Exiting from room");
    delay(100);
    count--;
    if (count < 0) count = 0;
    Serial.print("No. of people inside room: ");
    Serial.println(count);
    i = 1;
    state1 = false;
  }

  // Reset states
  if (digitalRead(irPin1)) {
    state1 = true;
  }
  if (digitalRead(irPin2)) {
    state2 = true;
  }

  // LDR-controlled lighting
  if (count > 0) {
    int ldrValue = analogRead(ldrPin);
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

    if (ldrValue < sequenceTime) {
      // Low light → Turn on only 2 LEDs
      controlLeds(2);
    } else {
      // Bright light → Turn on all LEDs
      controlLeds(numLeds);
    }
  } else {
    // No one in room → Turn off all LEDs
    controlLeds(0);
  }

  delay(100); // Small delay to stabilize reading
}

void controlLeds(int numOn) {
  for (int j = 0; j < numLeds; j++) {
    if (j < numOn) {
      digitalWrite(ledPins[j], HIGH);
    } else {
      digitalWrite(ledPins[j], LOW);
    }
  }
}
