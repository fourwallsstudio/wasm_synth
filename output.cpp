#include <stdlib.h>
#include <cmath>

#define SIZE 256

float sinTable[SIZE] = {0};

void init (void) {
  for (int i = 0; i < SIZE; i++) {
    float step = (float)i / (float)SIZE;
    sinTable[i] = step * 2 * M_PI; 
  }
}

extern "C" {

float processAudio (int idx) {
  return sinTable[idx % SIZE];
}

}

int main (void) {
  init();
  return 0;
}

