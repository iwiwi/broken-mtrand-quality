#include <stdint.h>
#include <stdlib.h>

char *test_name() {
  return "rand (stdlib)";
}

void test_srand(uint32_t seed) {
  srand(seed);
}

uint32_t test_rand() {
  return rand();
}
