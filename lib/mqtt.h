#ifndef HEADER_CURL_MQTT_H
#define HEADER_CURL_MQTT_H

// Copyright (C) 2019 - 2020, Björn Stenberg, <bjorn@haxx.se>
// SPDX-FileCopyrightText: 1998-2020 Daniel Stenberg, <daniel@haxx.se>, et al.
//
// SPDX-License-Identifier: curl

#ifndef CURL_DISABLE_MQTT
extern const struct Curl_handler Curl_handler_mqtt;
#endif

enum mqttstate {
  MQTT_FIRST,             /* 0 */
  MQTT_REMAINING_LENGTH,  /* 1 */
  MQTT_CONNACK,           /* 2 */
  MQTT_SUBACK,            /* 3 */
  MQTT_SUBACK_COMING,     /* 4 - the SUBACK remainder */
  MQTT_PUBWAIT,    /* 5 - wait for publish */
  MQTT_PUB_REMAIN,  /* 6 - wait for the remainder of the publish */

  MQTT_NOSTATE /* 7 - never used an actual state */
};

struct mqtt_conn {
  enum mqttstate state;
  enum mqttstate nextstate; /* switch to this after remaining length is
                               done */
  unsigned int packetid;
};

/* protocol-specific transfer-related data */
struct MQTT {
  char *sendleftovers;
  size_t nsend; /* size of sendleftovers */

  /* when receiving */
  size_t npacket; /* byte counter */
  unsigned char firstbyte;
  size_t remaining_length;
};

#endif /* HEADER_CURL_MQTT_H */
