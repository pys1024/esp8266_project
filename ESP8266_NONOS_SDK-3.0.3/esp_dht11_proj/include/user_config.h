#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#define USE_OPTIMIZE_PRINTF

#define SAMPLE_INTERVAL 2000 /* milliseconds */

#define STATE_ON  "ON"
#define STATE_OFF  "OFF"
#define AVAILABLE "online"
#define NOT_AVAILABLE "offline"
/*
 *  Pin number:
 *  -----------
 *  Pin 0 = GPIO16
 *  Pin 1 = GPIO5
 *  Pin 2 = GPIO4
 *  Pin 3 = GPIO0
 *  Pin 4 = GPIO2
 *  Pin 5 = GPIO14
 *  Pin 6 = GPIO12
 *  Pin 7 = GPIO13
 *  Pin 8 = GPIO15
 *  Pin 9 = GPIO3
 *  Pin 10 = GPIO1
 *  Pin 11 = GPIO9
 *  Pin 12 = GPIO10
 */
#define SENSOR_PIN 4
#define SENSOR_TYPE DHT11

#define CTRL_GOPIO 2
#define GPIO_ON 0
#define GPIO_OFF 1
#define MSG_ON "\xbb\x01\xff"
#define MSG_OFF "\xbb\x02\xff"

#define DEFAULT_STATE "0"

#define TEMP_TOPIC "/mqtt/sensor/state/temperature1"
#define HUMI_TOPIC "/mqtt/sensor/state/humidity1"

#define STATE_TOPIC "/mqtt/switch/state/airconditioner"
#define COMMAND_TOPIC "/mqtt/switch/command/airconditioner"
#define AVAILABLE_TOPIC "/mqtt/sensor/available/temp_and_humi1"

#define mqtt_publish(topic, payload) MQTT_Publish(client, topic, \
                                                  payload, os_strlen(payload),\
                                                  0, 1);
#endif

