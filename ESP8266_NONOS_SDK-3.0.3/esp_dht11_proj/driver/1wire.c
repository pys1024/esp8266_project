#include "driver/1wire.h"
#include "gpio.h"

uint8_t wire_init() {
  uint16_t cnt = 0;

  GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 0); /* send reset sig */
  delay_us(700);

  GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 1); /* high sig */

  /* wait for low sig */
  while (GPIO_INPUT_GET(GPIO_ID_PIN(WIRE_IO)) == 1) {
    delay_us(1);
    cnt++;
    if (cnt >= 200) {return 1;}
  }

  /* failed if duration of low sig is too long  */
  cnt = 0;
  while (GPIO_INPUT_GET(GPIO_ID_PIN(WIRE_IO)) == 0) {
    delay_us(1);
    cnt++;
    if (cnt >= 480) {return 1;}
  }

  return 0;                     /* success */
}


void wire_write(uint8_t data) {
  uint8_t i = 0;
  for (i = 0; i < 8; i++) {
    GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 0);
    delay_us(1);

    GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), data & 0x01);
    delay_us(80);

    GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 1);
    data >>= 1;
  }
}

uint8_t wire_read() {
  uint8_t data = 0, temp = 0, i = 0;
  for (i = 0; i < 8; i++) {
    GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 0);
    delay_us(1);
    GPIO_OUTPUT_SET(GPIO_ID_PIN(WIRE_IO), 1);
    delay_us(6);                /* delay 6us */

    temp = GPIO_INPUT_GET(GPIO_ID_PIN(WIRE_IO)); /* get data */

    data = (data >> 1) | (temp << 7);
    delay_us(48);
  }
  return data;
}
