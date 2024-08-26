#include <avr/io.h>
#include <inttypes.h>
#include <util/delay.h>

typedef uint8_t byte;

#define MYPORTB *((volatile byte *)0x25)

int main(void) {
  DDRB = 32;

  while (1) {
    MYPORTB = 32;
    for (long i = 0; i < 3000000; i++) {
      MYPORTB = 32;
    }

    MYPORTB = 0;
    for (long i = 0; i < 1000000; i++) {
      MYPORTB = 0;
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