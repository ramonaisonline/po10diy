
// A big function to draw the strips of UI in the 
// left- and right-most 40px of the onboard display

void drawUI() {
  // UI Background
  display.fillRect(0, 0, 40, 240, BLACK);
  display.fillRect(360, 0, 40, 240, BLACK);

  // Draw toolbar
  display.drawRect(2, 2, 36, 175, WHITE);
  display.fillRect(4, 4, 32, 171, WHITE);
  
  for (int i = 0; i < 8; i++) {
    // show the layers that are active at the current step
    if ((playing && isLayerActive(activeStep, i)) || isLayerPunched(i)) {
      display.fillRect(8, 8 + i * 17, 24, 16, BLACK);
      display.drawBitmap(8, 8 + i * 17, epd_bitmap_allArray[i], 24, 16, WHITE);
      display.drawRect(8, 8 + i * 17, 24, 16, BLACK);
    }
    else {
      // It's not punched or active in the sequencer, so draw it in off mode
      display.drawBitmap(8, 8 + i * 17, epd_bitmap_allArray[i], 24, 16, BLACK);
    }

    // Draw a line to indicate the selected layer
    if (selectedLayer == i) {
      display.drawFastVLine(5, 8 + i * 17, 16, BLACK);
      display.drawFastVLine(6, 8 + i * 17, 16, BLACK);
    }
  }

  // DRAW SWATCHES =========================
  // Draw rear square
  display.drawRect(16, 155, 16, 16, BLACK);

  if (getPunchParam(selectedLayer, 3) == 0) {
    // Draw black in bg
    display.fillRect(18, 157, 12, 12, BLACK);
    // cover up rear square lines
    display.fillRect(9, 148, 14, 14, WHITE);
    // Draw forward square
    display.drawRect(8, 147, 16, 16, BLACK);
  }
  else {
    // cover up rear square lines
    display.fillRect(9, 148, 14, 14, WHITE);
    // Draw black swatch forward
    display.fillRect(10, 149, 12, 12, BLACK);
    // Draw forward square
    display.drawRect(8, 147, 16, 16, BLACK);
  }


  // DRAW BORDERS ============================
  // display.drawFastVLine(39, 0, 240, WHITE);
  // display.drawFastVLine(359, 0, 240, WHITE);

  // DRAW SEQUENCE ===========================
  // BPM indicator
  display.drawBitmap(2, 179, epd_bitmap_allArray[14], 36, 15, WHITE);
  // Frame
  display.drawRect(2, 196, 36, 20, WHITE);
  // Active step indicator
  if (playing) {
    display.drawRect(4 + (8 * (activeStep%4)), 198 + (8 * (activeStep/4)), 8, 8, WHITE);
    display.drawBitmap(5, 221, epd_bitmap_allArray[9], 14, 14, WHITE);
  }
  else {
    display.drawBitmap(5, 221, epd_bitmap_allArray[8], 14, 14, WHITE);
  }

  for (int i = 0; i < 8; i++) {
    if (writing && isLayerActive(i, selectedLayer)) {
      display.fillRect(6 + (8 * (i%4)), 200 + (8 * (i/4)), 4, 4, WHITE);
    }
  }

  display.drawRect(2, 218, 36, 20, WHITE);
  if (writing) {
    display.drawBitmap(21, 221, epd_bitmap_allArray[11], 14, 14, WHITE);
  }
  else {
    display.drawBitmap(21, 221, epd_bitmap_allArray[10], 14, 14, WHITE);
  }


  // DRAW BARS ===============================
  int a = map(potA[selectedLayer], 1023, 0, 0, 228);
  int b = map(potB[selectedLayer], 1023, 0, 0, 228);
  display.drawRect(362, 2, 36, 236, WHITE);
  display.fillRect(364, 4, 32, 232, WHITE);
  display.fillRect(366, 234 - a, 13, a, BLACK);
  display.fillRect(381, 234 - b, 13, b, BLACK);
}