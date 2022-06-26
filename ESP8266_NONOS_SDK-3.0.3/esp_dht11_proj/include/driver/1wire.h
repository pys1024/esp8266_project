#ifndef __1WIRE_H__
#define __1WIRE_H__

#define WIRE_IO 2

#define delay_us(x) os_delay_us(x)
#define delay_ms(x) delay_us(x*1000)

#endif
