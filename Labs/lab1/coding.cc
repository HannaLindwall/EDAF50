#include "coding.h"

unsigned char encode(char& c) {

  return c+3;
}
unsigned char decode(char& c) {
  return c-3;
}
