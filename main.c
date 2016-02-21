#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include "unif01.h"
#include "bbattery.h"

#define DEFAULT_TEST 's'
#define DEFAULT_SEED 12345678

char *test_name(void);
void test_srand(uint32_t seed);
uint32_t test_rand(void);

void print_usage_and_quit(char **argv) {
  fprintf(stderr, "Usage: %s [TEST=%c] [SEED=%d]\n", argv[0], DEFAULT_TEST, DEFAULT_SEED);
  fprintf(stderr, "  TEST: 's' (small), 'm' (medium), or 'b' (big)\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  if (argc > 3) {
    print_usage_and_quit(argv);
  }
  char test = argc >= 2 ? argv[1][0] : DEFAULT_TEST;
  uint32_t seed = argc >= 3 ? strtoul(argv[2], NULL, 10) : DEFAULT_SEED;

  /* Debug print */
  test_srand(seed);
  for (int i = 0; i < 16; ++i) {
    printf("%u\n", test_rand() >> 1);
  }

  /* Actual test */
  test_srand(seed);
  unif01_Gen *gen = unif01_CreateExternGenBits(test_name(), test_rand);
  switch (test) {
    case 's':
      bbattery_SmallCrush(gen);
      break;
    case 'm':
      bbattery_Crush(gen);
      break;
    case 'b':
      bbattery_BigCrush(gen);
      break;
    default:
      print_usage_and_quit(argv);
      break;
  }
  unif01_DeleteExternGenBits(gen);

  exit(EXIT_SUCCESS);
}
