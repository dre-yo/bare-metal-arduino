#include <inttypes.h>

typedef uint8_t byte;

#define PORTB *((volatile byte *)0x25)
#define DDRB *((volatile byte *)0x24)

int main(void) {
  DDRB = 32;

  while (1) {
    PORTB = 32;
    for (long i = 0; i < 3000000; i++) {
      PORTB = 32;
    }

    PORTB = 0;
    for (long i = 0; i < 1000000; i++) {
      PORTB = 0;
    }
  }
}
