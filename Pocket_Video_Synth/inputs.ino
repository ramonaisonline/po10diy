///
// TODO make this so that it only updates when the knob is moved
// Have to track the natural position of the knob and only save it if it's different from the last position by some margin
// Need to check against actual PO behavior...
void updatePots() { 
  int sum = 0;
  int samples = 3;
  int newValue = 0;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(POT_A_PIN) / 8 * 8;
  }

  newValue = sum/samples;
  if (newValue != actualPotA) {
    // the knob was moved... count that as a write
    potA[selectedLayer] = newValue;
    setPunchParam(selectedLayer, 0, newValue);
  }
  actualPotA = newValue;
  
  sum = 0;
  for (int i = 0; i < samples; i++) {
    sum += analogRead(POT_B_PIN) / 8 * 8;
  }

  newValue = sum/samples;
  if (newValue != actualPotB) {
    // the knob was moved... count that as a write
    potB[selectedLayer] = newValue;
    setPunchParam(selectedLayer, 1, newValue);
  }
  actualPotB = newValue;
  // Serial.print("A: ");
  // Serial.print(potA);
  // Serial.print(" , B: ");
  // Serial.println(potB);
}

long threePointMap(int pot, int targetMin, int targetMid, int targetMax) {
  if (pot < 512) {
    return map(pot, 0, 512, targetMin, targetMid);
  }
  else {
    return map(pot, 512, 1023, targetMid, targetMax);
  }
}

// This function maps the value of a knob to between min and max
long simpleMap(int pot, int min, int max) {
  return map(pot, 0, 1023, min, max);
}

// cyclicalMap also maps the value of a knob to a range
// but you can have it cycle through the range multiple times
// to create interesting "macro" effects
long cyclicalMap(int pot, float multiple, float phase, int min, int max) {
  int diff = max - min;
  float cycle = sin((pot / 1023.0) * multiple * TWOPI + (phase * TWOPI)) / 2.0 + 0.5; //0-1
  return(min + (diff * cycle));
}