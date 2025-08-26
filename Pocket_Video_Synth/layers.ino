
// These are the drawing functions that are activated by buttons 1-8
// Try editing these or writing some of your own!

// IMPORTANT TO KNOW!
// You'll notice that these functions all start with a similar 16-line block
// The l variable is a shorthand for *which button this layer is mapped to*
// which ALSO affects where in the sequence memory the data for this layer is stored
// So...
// IF YOU WANT TO CHANGE WHICH BUTTONS ACTIVATE THESE LAYERS,
// YOU MUST SET l TO THE SAME NUMBER AS THE CASE THAT TRIGGERS THE LAYER IN THE 
// SWITCH STATEMENT IN THE DRAWING FUNCTION OF THE MAIN LOOP

// Sorry for yelling but I messed this up several times in my own work and it was very confusing!

// The rest of that block loads up the parameters that were stored 
// in the sequence or saved from the last punch-in and puts them in
// some convenient variables for you to use in your drawing function!

// a is the value of knob a
// b is the value of knob b
// by default these values are in the range 0-1023
// but most of the time you'll probably be mapping them to some other range of values
// using the stock map() function, or the custom cyclicalMap() function

// type is either 0, 1, or 2
// and can be used to change some mode or something within your layer

// c1 is the dominant color of your layer, either white or black (e.g. the fill color of a circle)
// c2 is whatever the opposite color is (e.g. the stroke color of a circle)

// The drawing functions used here (e.g. "drawCircle()") are defined in helpers.ino
// Basically they just wrap the drawing functions for the internal and external displays
// and duplicate every drawing command to both screens. It works well enough!

// Anyway here's a template for you!

void myCustomLayer() {
  int l = 0;                      // Set this to the number of the button you want to use
  int a, b, type, c1, c2;         // This is the list of inputs you can use to draw with
  if (isLayerPunched(l)) {        // Ignore from here...
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }                               // ...to here

  // Maybe you'll define some variables here?
  int r = simpleMap(a, 10, 50);
  int x = cyclicalMap(b, 3, 0, 0, CW);
  int y = cyclicalMap(b, 7, 0.25, 0, H);

  if (type == 0) {
    // Draw some stuff
    drawCircle(x, y, r, c1);
    fillCircle(x, y, r, c2);
  }
  else if (type == 1) {
    // Draw some slightly different stuff
  }
  else if (type == 2) {
    // Draw some even more different stuff
  }
}

// Stock layer functions:

void randomLines() {
  int l = 0;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  int length = cyclicalMap(a, 2, 0, 4, CW);
  int num = map(b, 1023, 0, 1, 50);

  if (type == 0) {
    for (int i = 0; i < num; i++) {
      // Either horizontal or vertical, plus count + length
      int x0, y0, x1, y1;
      if (a < 512) {
        x0 = random(CW - length);
        y0 = random(H);
        x1 = x0 + length;
        y1 = y0;
      }
      else {
        x0 = random(CW);
        y0 = random(H - length);
        x1 = x0;
        y1 = y0 + length;
      }
      
      drawLine(x0, y0, x1, y1, c1);
    }
  }
  else if (type == 1) {
    for (int i = 0; i < num; i++) {
      int x0 = random(CW);
      int y0 = random(H);
      int dx = random(length) * 2 - length;
      int dy = 0;
      if (x0 % 2 == 0) {
        dy = dx * -1;
      }
      else {
        dy = dx;
      }
      int x1 = x0 + dx;
      int y1 = y0 + dy;
      drawLine(x0, y0, x1, y1, c1);
      // randomLines();
    }
  }
  else if (type == 2) {
    int config = map(a, 1023, 0, 0, 5);
    int x0, y0, x1, y1, l, dx, dy;
    float theta;
    for (int i = 0; i < num; i++) {
      if (config == 0) {
        x0 = HALFCW;
        y0 = HALFH;
        theta = random(360) / 360.0 * TWOPI;
        l = random(200);
      }
      else if (config == 1) {
        if (random(2) > 0) {
          x0 = HALFCW;
          y0 = 0;
          theta = (random(180)) / 360.0 * TWOPI;
        }
        else {
          x0 = HALFCW;
          y0 = H-1;
          theta = (random(180)+180) / 360.0 * TWOPI;
        }
        l = random(288);
      }
      else if (config == 2) {
        if (random(2) > 0) {
          x0 = CW-1;
          y0 = 0;
          theta = (random(90)+90) / 360.0 * TWOPI;
        }
        else {
          x0 = 0;
          y0 = H-1;
          theta = (random(90)+270) / 360.0 * TWOPI;
        }
        l = random(400);
      }
      else if (config == 3) {
        if (random(2) > 0) {
          x0 = CW-1;
          y0 = HALFH;
          theta = (random(180)+90) / 360.0 * TWOPI;
        }
        else {
          x0 = 0;
          y0 = HALFH;
          theta = (random(180)-90) / 360.0 * TWOPI;
        }
        l = random(340);
      }
      else if (config >= 4) {
        if (random(2) > 0) {
          x0 = 0;
          y0 = 0;
          theta = (random(90)) / 360.0 * TWOPI;
        }
        else {
          x0 = CW-1;
          y0 = H-1;
          theta = (random(90)+180) / 360.0 * TWOPI;
        }
        l = random(400);
      }

      l = random(200);
      dx = cos(theta) * l;
      dy = sin(theta) * l;
      x1 = x0 + dx;
      y1 = y0 + dy;

      drawLine(x0, y0, x1, y1, c1);
    }
  }
  
}

void randomRect() {
  int l = 1;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  if (type == 0) {
    int widthLimit = map(a, 1023, 0, 1, HALFCW);
    int heightLimit = map(b, 1023, 0, 1, H);
    int w = random(1, widthLimit);
    int h = random(1, heightLimit);
    int x = random(HALFCW - w);
    int y = random(H - h);
    
    fillRect(x, y, w, h, c1);
    fillRect(CW - x - w, H - y - h, w, h, c1);
  }
  else if (type == 1) {
    int widthLimit = map(a, 1023, 0, 1, HALFCW);
    int heightLimit = map(b, 1023, 0, 1, H);
    int w = random(1, widthLimit);
    int h = random(1, heightLimit);
    int x = random(HALFCW - w);
    int y = random(H - h);
    
    drawRect(x, y, w, h, c1);
    drawRect(CW - x - w, H - y - h, w, h, c1);
  }
  else if (type == 2) {
    // Rolling wipe
    int thickness = cyclicalMap(a, 3, 0, 1, 80);
    int direction = map(a, 1023, 0, 0, 4);
    int period = map(b, 1023, 0, 100, 5);
    period = period * 100;

    int span, totalDistance, x, y;

    if (direction == 0) {
      span = CW;
      totalDistance = H + (thickness * 4);
      x = 0;
      y = ((millis() % period) / (float)period) * totalDistance - (thickness * 2);
      fillRect(x, y, span, thickness, c1);
      fillRect(x, y-thickness, span, thickness, c2);
    }
    else if (direction == 1) {
      span = CW;
      totalDistance = H + (thickness * 4);
      x = 0;
      y = H-((millis() % period) / (float)period) * totalDistance - (thickness * 2);
      fillRect(x, y, span, thickness, c1);
      fillRect(x, y-thickness, span, thickness, c2);
    }
    else if (direction == 2) {
      span = H;
      totalDistance = CW + (thickness * 4);
      x = ((millis() % period) / (float)period) * totalDistance - (thickness * 2);
      y = 0;
      fillRect(x, y, thickness, span, c1);
      fillRect(x - thickness, y, thickness, span, c2);
    }
    else if (direction == 3) {
      span = H;
      totalDistance = CW + (thickness * 4);
      x = CW-((millis() % period) / (float)period) * totalDistance - (thickness * 2);
      y = 0;
      fillRect(x, y, thickness, span, c1);
      fillRect(x - thickness, y, thickness, span, c2);
    }
    
  }
  
}

void doodles() {
  int l = 3;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  int r = map(potB[l], 1023, 0, 4, 50);
  float orbitOffsetCycleDuration1 = cyclicalMap(a, 3, 0, 1, 5) * 100.0;
  float orbitOffsetCycleDuration2 = cyclicalMap(b, 3, 0, 5, 10) * 100.0;
  int orbitR = floor(sin(millis()/orbitOffsetCycleDuration1) * map(potA[l], 1023, 0, 10, 100)) + 20;

  int xOffset = floor(sin(millis()/orbitOffsetCycleDuration2) * orbitR);
  int yOffset = floor(cos(millis()/orbitOffsetCycleDuration2) * orbitR);

  // int c = sin(millis()/500.0)

  if (type == 0) {
    fillCircle(HALFCW + xOffset, HALFH + yOffset, r, c1);
    drawCircle(HALFCW + xOffset, HALFH + yOffset, r, c2);
  }
  else if (type == 1) {
    fillRect(HALFCW + xOffset - (r/2), HALFH + yOffset - (r/2), r, r, c1);
    drawRect(HALFCW + xOffset - (r/2), HALFH + yOffset - (r/2), r, r, c2);
  }
  else if (type == 2) {
    float rotationOffset = ((millis() % 5000) / 5000.0) * TWOPI;
    int x0 = HALFCW + xOffset + cos(rotationOffset) * r;
    int y0 = HALFH + yOffset + sin(rotationOffset) * r;
    int x1 = HALFCW + xOffset + cos(rotationOffset + (0.33 * TWOPI)) * r;
    int y1 = HALFH + yOffset + sin(rotationOffset + (0.33 * TWOPI)) * r;
    int x2 = HALFCW + xOffset + cos(rotationOffset + (0.66 * TWOPI)) * r;
    int y2 = HALFH + yOffset + sin(rotationOffset + (0.66 * TWOPI)) * r;
    fillTriangle(x0, y0, x1, y1, x2, y2, c1);
    drawTriangle(x0, y0, x1, y1, x2, y2, c2);
  }

  
}

void grid() {
  int l = 5;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  if (type == 0) {
    int cols = cyclicalMap(a, 2, 0, 1, 20);
    int rows = cyclicalMap(a, 3, 0, 1, 20);

    int xStart =  cyclicalMap(b, 7, 0, 0, 8);
    int xSpan =   cyclicalMap(b, 5, 0, 1, 8 - xStart);
    int yStart =  cyclicalMap(b, 9, 0, 0, 8);
    int ySpan =   cyclicalMap(b, 2, 0, 1, 8 - yStart);

    xStart  *= (CW/8);
    xSpan   *= (CW/8);
    yStart  *= (CW/8);
    ySpan   *= (CW/8);

    int colSpacing = xSpan/cols;
    int rowSpacing = ySpan/rows;

    for (int i = 0; i < cols + 1; i++) {
      drawFastVLine(i * colSpacing + xStart, yStart, ySpan, c1);
    }
    for (int i = 0; i < rows + 1; i++) {
      drawFastHLine(xStart, i * rowSpacing + yStart, xSpan, c1);
    }
  }
  else if (type == 1) {
    int cols = threePointMap(a, 1, 10, 1);
    int rows = threePointMap(a, 10, 1, 10);
    int size = map(b, 0, 1023, 1, 20);
    int offset = size / 2;

    int dy = HALFH / rows;
    int dx = HALFCW / cols;
    int totalRows = rows * 2 + 1;
    int totalCols = cols * 2 + 1;
    int startX = HALFCW - (cols * dx);
    int startY = HALFH - (rows * dy);

    for (int i = 0; i < totalRows; i++) {
      for (int j = 0; j < totalCols; j++) {
        int x = startX + (j * dx) - offset;
        int y = startY + (i * dy) - offset;
        drawRect(x, y, size, size, c1);
      }
    }
  }
  else if (type == 2) {
    int cols = cyclicalMap(a, 3, 0, 1, 16);
    int rows = cyclicalMap(a, 4, 0, 1, 16);
    int skipEvery = cyclicalMap(b, 0, 7, 2, 10);

    int dy = HALFH / rows;
    int dx = HALFCW / cols;
    int totalRows = rows * 2 + 1;
    int totalCols = cols * 2 + 1;
    int startX = HALFCW - (cols * dx);
    int startY = HALFH - (rows * dy);

    for (int i = 0; i < totalRows; i++) {
      for (int j = 0; j < totalCols; j++) {
        int x = startX + (j * dx) - (dx/2) + 1;
        int y = startY + (i * dy) - (dy/2) + 1;
        // display.clearDisplay();
        if ((i * rows + j) % skipEvery != 0) {
          fillRect(x, y, dx - 2, dy - 2, c1);
        }
      }
    }
  }

  
}

void grid2() {
  int l = 5;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  int cols = threePointMap(a, 1, 10, 1);
  int rows = threePointMap(a, 10, 1, 10);
  int size = map(b, 0, 1023, 1, 20);
  int offset = size / 2;

  int dy = HALFH / rows;
  int dx = HALFCW / cols;
  int totalRows = rows * 2 + 1;
  int totalCols = cols * 2 + 1;
  int startX = HALFCW - (cols * dx);
  int startY = HALFH - (rows * dy);

  for (int i = 0; i < totalRows; i++) {
    for (int j = 0; j < totalCols; j++) {
      int x = startX + (j * dx) - offset;
      int y = startY + (i * dy) - offset;
      drawRect(x, y, size, size, c1);
    }
  }
}

void triangles() {
  int l = 4;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  if (type == 0) {
    int xScale = cyclicalMap(a, 2.5, 0, 40, CW);
    int yScale = cyclicalMap(b, 2.5, 0.5, 40, H);

    int xMin = (CW - xScale) / 2;
    int xMax = xMin + xScale;
    int yMin = (H - yScale) / 2;
    int yMax = yMin + yScale;

    int x0 = cyclicalMap(a, 3, 0, xMin, xMax);
    int y0 = cyclicalMap(b, 4, 0, yMin, yMax);
    int x1 = cyclicalMap(a, 3, 0.25, xMin, xMax);
    int y1 = cyclicalMap(b, 4, 0.25, yMin, yMax);
    int x2 = cyclicalMap(a, 3, 0.5, xMin, xMax);
    int y2 = cyclicalMap(b, 4, 0.5, yMin, yMax);

    int x3 = cyclicalMap(a, 3, 0, xMin, xMax);
    int y3 = cyclicalMap(b, 4, 0, yMin, yMax);
    int x4 = cyclicalMap(a, 3, 0, xMin, xMax);
    int y4 = cyclicalMap(b, 4, 0, yMin, yMax);
    int x5 = cyclicalMap(a, 3, 0, xMin, xMax);
    int y5 = cyclicalMap(b, 4, 0, yMin, yMax);

    drawTriangle(x0, y0, x1, y1, x2, y2, c1);
    drawTriangle(CW-x0, H-y0, CW-x1, H-y1, CW-x2, H-y2, c1);

    // display.drawTriangle(x3, y3, x4, y4, x5, y5, c1);
    // display.drawTriangle(W-x3, H-y3, W-x4, H-y4, W-x5, H-y5, c1);
  }
  else if (type >= 1) {
    int r = cyclicalMap(a, 1, 0, 20, 200);
    int period = cyclicalMap(b, 1, 0, 80, 8);

    period = period * 100;

    int x0 = HALFCW + sin((millis() % period) / (float)period * TWOPI) * r;
    int y0 = HALFH  + cos((millis() % period) / (float)period * TWOPI) * r;
    int x1 = HALFCW + sin((millis() % period) / (float)period * TWOPI + (0.33 * TWOPI)) * r;
    int y1 = HALFH  + cos((millis() % period) / (float)period * TWOPI + (0.33 * TWOPI)) * r;
    int x2 = HALFCW + sin((millis() % period) / (float)period * TWOPI + (0.66 * TWOPI)) * r;
    int y2 = HALFH  + cos((millis() % period) / (float)period * TWOPI + (0.66 * TWOPI)) * r;

    drawTriangle(x0, y0, x1, y1, x2, y2, c1);
  }
}

// at size 1, a glyph is 5x8
// size is integer multiple scaling
// so placing on a 5x8 grid could work?
void glyphs() {
  int l = 2;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  // int min = 179;
  // int max = 218;

  int size = map(a, 1023, 0, 1, 12);
  int num = map(b, 1023, 0, 1, 50);
  int glyph;

  if (type == 0) {
    glyph = random(179, 219);
  }
  else if (type == 1) {
    glyph = random(1, 44);
  }
  else if (type == 2) {
    glyph = random(97, 169);
  }
  

  for (int i = 0; i < num; i++) {
    int x = random(CW) / (5 * size) * (5 * size);
    int y = random(H) / (8 * size) * (8 * size);
    drawChar(x, y, glyph, c1, c2, size);
  }
}

void dust() {
  int l = 7;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }

  if (type >= 0) {
    int gridX = cyclicalMap(a, 3, 0, 1, 32);
    int gridY = cyclicalMap(a, 4, 0.5, 1, 24);
    int num = map(b, 1023, 0, 16, 128);

    for (int i = 0; i < num; i++) {
      int x = random(CW) / gridX * gridX;
      int y = random(H) / gridY * gridY;
      drawPixel(x, y, c1);
    }
  }
}

void circles() {
  int l = 6;
  int a, b, type, c1, c2;
  if (isLayerPunched(l)) {
    a = getPunchParam(l, 0);
    b = getPunchParam(l, 1);
    type = getPunchParam(l, 2);
    c1 = !getPunchParam(l, 3);
    c2 = !c1;
  }
  else {
    a = getActiveParam(l, 0);
    b = getActiveParam(l, 1);
    type = getActiveParam(l, 2);
    c1 = !getActiveParam(l, 3);
    c2 = !c1;
  }
  

  if (type >= 0) {
    int xOffset = cyclicalMap(b, 2, 0.25, 0, HALFCW);
    int yOffset = cyclicalMap(b, 3, 0.25, 0, HALFH);
    int rMaxRange = cyclicalMap(a, 1, 0, 10, HALFH - 10);
    float cycleDuration = (float)cyclicalMap(a, 3, 0.25, 3000, 500);

    int r1 = ((sin(millis() / cycleDuration)) / 2 + 0.5) * rMaxRange + 10;
    int r2 = ((cos(millis() / cycleDuration)) / 2 + 0.5) * rMaxRange + 10;

    drawCircle(HALFCW + xOffset, HALFH + yOffset, r1, c1);
    drawCircle(HALFCW - xOffset, HALFH - yOffset, r1, c1);
    drawCircle(HALFCW + xOffset, HALFH - yOffset, r2, c1);
    drawCircle(HALFCW - xOffset, HALFH + yOffset, r2, c1);
  }
}