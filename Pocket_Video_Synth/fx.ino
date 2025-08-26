void fillBlack() {
  display.fillRect(40, 0, CW, H, BLACK); // don't want to fillScreen bc of the UI!
  dvidisplay.fillScreen(BLACK);
}

void fillWhite() {
  display.fillRect(40, 0, CW, H, WHITE); // don't want to fillScreen bc of the UI!
  dvidisplay.fillScreen(WHITE);
}

void invert() {
  dvidisplay.setColor(0, 0xFFFF);
  dvidisplay.setColor(1, 0x0000);
  dvidisplay.setColor(255, 0x0000);
  dvidisplay.swap(true, true);
  dvidisplay.swap(false, false);
}

void fgColor() {
  // dvidisplay.setColor(0, 255, 0, 0);
  dvidisplay.setColor(1, 255, 0, 0);
  dvidisplay.swap(true, true);
  dvidisplay.swap(false, false);
}

void bgColor() {
  // dvidisplay.setColor(0, 255, 0, 0);
  dvidisplay.setColor(0, 255, 0, 0);
  dvidisplay.setColor(1, 0, 0, 0);
  dvidisplay.swap(true, true);
  dvidisplay.swap(false, false);
}

void reflectHorizontally() {
  for (int i = 0; i < HALFCW; i++) {
    for (int j = 0; j < H; j++) {
      drawPixel(HALFCW + i, j, dvidisplay.getPixel(HALFCW - i, j));
    }
  } 
}

void reflectVertically() {
  for (int i = 0; i < CW; i++) {
    for (int j = 0; j < HALFH; j++) {
      drawPixel(i, HALFH + j, dvidisplay.getPixel(i, HALFH - j));
    }
  } 
}

void reflectBoth() {
  for (int i = 0; i < HALFCW; i++) {
    for (int j = 0; j < HALFH; j++) {
      int pSharp = display.getPixel(HALFCW - i + 40, HALFH - j);
      int pDVI = dvidisplay.getPixel(HALFCW - i, HALFH - j);

      drawPixel(HALFCW + i, HALFH + j, pDVI);
      drawPixel(HALFCW + i, HALFH - j, pDVI);
      drawPixel(HALFCW - i, HALFH + j, pDVI);
    }
  } 
}

void cleanUpFX() {
  dvidisplay.setColor(0, 0x0000);
  dvidisplay.setColor(1, 0xFFFF);
  dvidisplay.setColor(255, 0xFFFF);
  dvidisplay.swap(true, true);
  dvidisplay.swap(false, false);
}