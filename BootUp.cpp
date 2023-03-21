#include "BootUp.h"
#include <Arduino.h>


void boot_up() {
  byte check = B00000001;
  int boot_loop = 0;
  while (boot_loop < 6) {
    check = boot_loop;
    delay(100);
    check = check << 2;
    PORTB = 0;
    PORTB |= check;

    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);

    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);

    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);

    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW);

    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);

    boot_loop = boot_loop + 1;
    check = boot_loop;
    check = check << 2;
    PORTB = 0;
    PORTB |= check;

    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);

    digitalWrite(3, HIGH);
    delay(100);
    digitalWrite(3, LOW);

    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);

    digitalWrite(5, HIGH);
    delay(100);
    digitalWrite(5, LOW);

    digitalWrite(6, HIGH);
    delay(100);
    digitalWrite(6, LOW);

    digitalWrite(7, HIGH);
    delay(100);
    digitalWrite(7, LOW);

    boot_loop = boot_loop + 1;
    check = boot_loop;
  }
  for (int i = 0; i < 6; i++) {
    check = i;
    delay(100);
    check = check << 2;
    PORTB = 0;
    PORTB |= check;
    digitalWrite(A2, HIGH);
  }
  delay(50);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(A2, LOW);
  PORTB = 0;
}
