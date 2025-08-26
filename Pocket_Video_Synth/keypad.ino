
// Big keypad handler
// Keypad events queue up, and you check them one by one
// And call other handler functions as appropriate
// The chars here are from the keymap we defined in the global vars

void handleKeypad() {
  while(keypad.available()){
    keypadEvent e = keypad.read();
    // Serial.print((char)e.bit.KEY);

    // If the key was just pressed down
    if (e.bit.EVENT == KEY_JUST_PRESSED) {
      // Serial.println(" pressed");
      uint8_t row = e.bit.ROW;
      uint8_t col = e.bit.COL;
      char key = keys[e.bit.ROW][e.bit.COL];
      // Serial.print("Row: "); Serial.print(row);
      // Serial.print(" col: "); Serial.println(col);
      // Serial.print(" -> ");
      uint16_t keynum = row * COLS + col;
      keypressTimes[keynum] = millis();

      if (key == 'P') {
        if (playing == true) {
          playing = false;
          activeStep = 0;
        }
        else if (playing == false) {
          playing = true;
          activeStep = 0;
          nextStepTime = millis() + stepIntervalMS;
        }
      }
      else if (key == 'W') {
        writing = !writing;
      }
      else if (key == 'A' || key == 'B' || key == 'C') {
        // It's a variant key
        // Col happens to be 0, 1, or 2 for these keys
        setPunchParam(selectedLayer, 2, col);
      }
      else if (key == 'D') {
        // It's the color key
        // Swap color from B->W or W->B
        if (getPunchParam(selectedLayer, 3) == 1) {
          setPunchParam(selectedLayer, 3, 0);
        }
        else {
          setPunchParam(selectedLayer, 3, 1);
        }
      }
      else if (key == 'F') {
        // It's the fx key
        fxHeld = true;
      }
      else if ((row == 2 || row == 3) && (col >= 0 && col <= 3)) {
        // FX key supercedes all, so check for that first
        if (fxHeld) {
          selectedFX = ((row - 2) * 4) + col;
          fxActive = true;
          continue;
        }
        // It's a step or layer key depending on whether we're writing or not
        if (writing) {
          int step = ((row - 2) * 4) + col;
          toggleLayerAtStep(step, selectedLayer);
          //also save current params as step param values
          setParam(step, selectedLayer, 0, getPunchParam(selectedLayer, 0));
          setParam(step, selectedLayer, 1, getPunchParam(selectedLayer, 1));
          setParam(step, selectedLayer, 2, getPunchParam(selectedLayer, 2));
          setParam(step, selectedLayer, 3, getPunchParam(selectedLayer, 3));
        }
        else {
          // Otherwise we're punching something in
          int layer = ((row - 2) * 4) + col;
          selectedLayer = layer;
          toggleLayerPunch(layer);
        }
      }
    }
    else if (e.bit.EVENT == KEY_JUST_RELEASED) {
      // Serial.println(" pressed");
      uint8_t row = e.bit.ROW;
      uint8_t col = e.bit.COL;
      char key = keys[e.bit.ROW][e.bit.COL];
      // Serial.print("Row: "); Serial.print(row);
      // Serial.print(" col: "); Serial.println(col);
      // Serial.print(" -> ");
      uint16_t keynum = row * COLS + col;
      keypressTimes[keynum] = millis();

      if (key == 'F') {
        // It's the fx key
        fxHeld = false;
        fxActive = false;
        cleanUpFX();
      }
      else if ((row == 2 || row == 3) && (col >= 0 && col <= 3)) {
        // It's a step or layer key depending on whether we're writing or not
        if (fxHeld) {
          // If we're in FX mode
          if (selectedFX == ((row - 2) * 4) + col) {
            // If we just released the most recently pressed FX punch in key
            fxActive = false;
          }
          continue;
        }
        if (writing) {
          // Do nothing
        }
        else {
          // punching in
          int layer = ((row - 2) * 4) + col;
          clearLayerPunch(layer);
        }
      }
    }
  }
}