// Maybe this is silly
// Since the onboard and DVI displays don't share a framebuffer
// I just made a bunch of wrapper functions that draw the same thing twice
// Once to the DVI display
// And once to the onboard display with a 40px offset to center it in the canvas area
// It seems to work ok

int offset = 40;

void drawPixel(int16_t x, int16_t y, uint16_t color) {
  dvidisplay.drawPixel(x, y, color);
  display.drawPixel(x + offset, y, color);
}

void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color) {
  dvidisplay.drawFastVLine(x, y, h, color);
  display.drawFastVLine(x + offset, y, h, color);
}

void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color) {
  dvidisplay.drawFastHLine(x, y, w, color);
  display.drawFastHLine(x + offset, y, w, color);
}

void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  dvidisplay.fillRect(x, y, w, h, color);
  display.fillRect(x + offset, y, w, h, color);
}

void fillScreen(uint16_t color) {
  dvidisplay.fillScreen(color);
  display.fillScreen(color);
}

void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
  dvidisplay.drawLine(x0, y0, x1, y1, color);
  display.drawLine(x0 + offset, y0, x1 + offset, y1, color);
}

void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
  dvidisplay.drawRect(x, y, w, h, color);
  display.drawRect(x + offset, y, w, h, color);
}

void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
  dvidisplay.drawCircle(x0, y0, r, color);
  display.drawCircle(x0 + offset, y0, r, color);
}

void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
  dvidisplay.fillCircle(x0, y0, r, color);
  display.fillCircle(x0 + offset, y0, r, color);
}

void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
  dvidisplay.drawTriangle(x0, y0, x1, y1, x2, y2, color);
  display.drawTriangle(x0 + offset, y0, x1 + offset, y1, x2 + offset, y2, color);
}

void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color) {
  dvidisplay.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  display.fillTriangle(x0 + offset, y0, x1 + offset, y1, x2 + offset, y2, color);
}

void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
  dvidisplay.drawRoundRect(x0, y0, w, h, radius, color);
  display.drawRoundRect(x0 + offset, y0, w, h, radius, color);
}

void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color) {
  dvidisplay.fillRoundRect(x0, y0, w, h, radius, color);
  display.fillRoundRect(x0 + offset, y0, w, h, radius, color);
}

void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color) {
  dvidisplay.drawBitmap(x, y, bitmap, w, h, color);
  display.drawBitmap(x + offset, y, bitmap, w, h, color);
}

void drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint16_t color, uint16_t bg) {
  dvidisplay.drawBitmap(x, y, bitmap, w, h, color, bg);
  display.drawBitmap(x + offset, y, bitmap, w, h, color, bg);
}

void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color) {
  dvidisplay.drawBitmap(x, y, bitmap, w, h, color);
  display.drawBitmap(x + offset, y, bitmap, w, h, color);
}

void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg) {
  dvidisplay.drawBitmap(x, y, bitmap, w, h, color, bg);
  display.drawBitmap(x + offset, y, bitmap, w, h, color, bg);
}

void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size) {
  dvidisplay.drawChar(x, y, c, color, bg, size);
  display.drawChar(x + offset, y, c, color, bg, size);
}

void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size_x, uint8_t size_y) {
  dvidisplay.drawChar(x, y, c, color, bg, size_x, size_y);
  display.drawChar(x + offset, y, c, color, bg, size_x, size_y);
}

void setTextSize(uint8_t s) {
  dvidisplay.setTextSize(s);
  display.setTextSize(s);
}

void setTextSize(uint8_t sx, uint8_t sy) {
  dvidisplay.setTextSize(sx, sy);
  display.setTextSize(sx, sy);
}

void setFont(const GFXfont *f = NULL) {
  dvidisplay.setFont(f);
  display.setFont(f);
}


