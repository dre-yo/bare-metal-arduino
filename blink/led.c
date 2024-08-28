#include <inttypes.h>

typedef uint8_t byte;

#define PORTB *((volatile byte *)0x25)
#define DDRB *((volatile byte *)0x24)

int main(void) {
  DDRB |= (1 << 5);

  while (1) {
    PORTB ^= (1 << 5);
    for (long i = 0; i < 3000000; i++) {
      PORTB |= (1 << 5);
    }

    PORTB ^= (1 << 5);
    for (long i = 0; i < 1000000; i++) {
      PORTB &= ~(1 << 5);
    }
  }
}
