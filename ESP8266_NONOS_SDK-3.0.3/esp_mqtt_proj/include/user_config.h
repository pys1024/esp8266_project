#ifndef __USER_CONFIG_H__
#define __USER_CONFIG_H__

#define USE_OPTIMIZE_PRINTF

#define STATE_ON  "ON"
#define STATE_OFF  "OFF"
#define AVAILABLE "online"
#define NOT_AVAILABLE "offline"

#define CTRL_GOPIO 2
#define GPIO_ON 0
#define GPIO_OFF 1
#define MSG_ON "\xbb\x01\xff"
#define MSG_OFF "\xbb\x02\xff"

#define DEFAULT_STATE STATE_ON

#define STATE_TOPIC "/mqtt/switch/state/pysbedroom"
#define COMMAND_TOPIC "/mqtt/switch/command/pysbedroom"
#define AVAILABLE_TOPIC "/mqtt/switch/available/pysbedroom"

#define mqtt_publish(topic, payload) MQTT_Publish(client, topic, \
                                                  payload, os_strlen(payload),\
                                                  0, 1);
#endif

