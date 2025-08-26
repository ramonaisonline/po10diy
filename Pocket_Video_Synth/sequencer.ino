
// These functions are just convenient accessors for 
// storing and retrieving values from the sequence array
// Remember that param 0 = Knob A, 1 = Knob B, 2 = Variant, 3 = Color

// Get the value of a param for a layer at a given step
uint16_t getParam(int step, int layer, int param) {
  return sequenceParams[(step * PARAMS * STEPS) + (layer * PARAMS) + param];
}

// Get the value of a param for a layer at the active step in the sequence
uint16_t getActiveParam(int layer, int param) {
  return sequenceParams[(activeStep * LAYERS * PARAMS) + (layer * PARAMS) + param];
}

// Get the last value of a param for a layer that was punched in
uint16_t getPunchParam(int layer, int param) {
  return punchParams[(layer * PARAMS) + param];
}

// Get the value of a param for a layer at the active step, scaled to a desired range
// int getScaledActiveParam(int layer, int param, int min, int max) {
//   return map(getActiveParam(layer, param), 0, 65535, min, max);
// }

// Store a value for a param for a layer at a step
void setParam(int step, int layer, int param, uint16_t value) {
  sequenceParams[(step * LAYERS * PARAMS) + (layer * PARAMS) + param] = value;
}

// Store a value for a param for a layer at the active step
void setActiveParam(int layer, int param, uint16_t value) {
  sequenceParams[(activeStep * LAYERS * PARAMS) + (layer * PARAMS) + param] = value;
}

// Save the current value of a param for a layer that's punched in
void setPunchParam(int layer, int param, uint16_t value) {
  // By convention: param 0 = A, 1 = B, 2 = type, 3 = color
  punchParams[(layer * PARAMS) + param] = value;
}

// // Randomize the value of all of the params for a given layer at the active step 
// void randomizeActiveParam(int layer, int param) {
//   sequenceParams[(activeStep * LAYERS * PARAMS) + (layer * PARAMS) + param] = (uint16_t)random(0, 65536);
// }

// // Randomize all parameters for all layers at the active step in the sequence
// void randomizeAllActiveParams(int layer) {
//   for (int i = 0; i < 4; i++) {
//     randomizeActiveParam(layer, i);
//   }
// }

// // Randomize all parameters for all layers at every step in the sequence
// void randomizeAllParams() {
//   for (int i = 0; i < 8; i++) {
//     for (int j = 0; j < 4; j++) {
//       randomizeParams(i, j);
//     }
//   }
// }

// void randomizeParams(int step, int layer) {
//   for (int i = 0; i < 4; i++) {
//     setParam(step, layer, i, (uint16_t)random(0, 65535));
//   }
// }



// A bunch of functions to track which layers are active at which steps
// Or which layers are being punched in

bool isLayerActive(int step, int layer) {
  return activeLayersPerStep[step] & (1 << layer);
}

void toggleLayerAtStep(int step, int layer) {
  activeLayersPerStep[step] ^= (1 << layer);
}

void toggleLayerPunch(int layer) {
  punchedInLayers ^= (1 << layer);
}

void clearLayerPunch(int layer) {
  punchedInLayers &= ~(1 << layer);
}

bool isLayerPunched(int layer) {
  return punchedInLayers & (1 << layer);
}

// Layers that depend on persistent state outside their drawing functions
// have an initialization function that can be run when the layer gets used
// for the first time.
bool layerNotInitialized(int layer) {
  return layerInitStatus & (1 << layer);
}

void initializeLayer(int layer) {
  layerInitStatus &= ~(1 << layer);
}

void shouldInitializeLayer(int layer) {
  layerInitStatus |= (1 << layer);
}

void shouldInitializeAllLayers() {
  layerInitStatus = ~(uint16_t)0;
}