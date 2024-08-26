#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

typedef uint8_t byte;

int main(void) {
  DDRB = 32;

  while (1) {
    *((volatile byte *)0x25) = 32;
    for (long i = 0; i < 2000000; i++) {
      *((volatile byte *)0x25) = 32;
    }

    *((volatile byte *)0x25) = 0;
    for (long i = 0; i < 1000000; i++) {
      *((volatile byte *)0x25) = 0;
    }
  }
}

// old code
// int main(void) {
//   DDRB = DDRB | (1 << DDB5);

//   while (1) {
//     PORTB = PORTB | (1 << PORTB5);

//     _delay_ms(1000);

//     PORTB = PORTB & ~(1 << PORTB5);

//     _delay_ms(1000);
//   }
// }