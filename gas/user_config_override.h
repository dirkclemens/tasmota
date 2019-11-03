/*
  user_config_override.h - user configuration overrides my_user_config.h for Sonoff-Tasmota

  Copyright (C) 2019  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// force the compiler to show a warning to confirm that this file is included
#warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *   (3) for platformio:
 *         define USE_CONFIG_OVERRIDE as a build flags.
 *         ie1 : export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE'
 *         ie2 : enable in file platformio.ini "build_flags = -Wl,-Tesp8266.flash.1m0.ld -DUSE_CONFIG_OVERRIDE"
 *       for Arduino IDE:
 *         enable define USE_CONFIG_OVERRIDE in my_user_config.h
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

#define USE_ADC_VCC // Display Vcc in Power status. Disable for use as Analog input on selected devices

//#define MODULE                 SONOFF_BASIC      // [Module] Select default model from sonoff_template.h

#define GAS_COUNTER_MODE 5000
#define GAS_POLL_MODE

#undef  USE_SML_M
#define USE_SML_M   // SML DiC !!!!!!!!!!!!
#undef  USE_SML
#define USE_SML 9600 

// select this meter
#undef  METER
#define METER GASONLY_DIC //EHZ363_2

#undef  MY_LANGUAGE
#define MY_LANGUAGE            de-DE           // German in Germany

#undef  FRIENDLY_NAME
#define FRIENDLY_NAME          "tasmota"       // [FriendlyName] Friendlyname up to 32 characters used by webpages and Alexa


// -- OTA -----------------------------------------
//#define USE_ARDUINO_OTA                          // Add optional support for Arduino OTA (+13k code)

// -- Setup your own Wifi settings  ---------------
// -- Wifi ----------------------------------------
#undef  WIFI_IP_ADDRESS
#define WIFI_IP_ADDRESS        "0.0.0.0"         // [IpAddress1] Set to 0.0.0.0 for using DHCP or enter a static IP address

#undef  WIFI_GATEWAY
#define WIFI_GATEWAY           "192.168.2.1"     // [IpAddress2] If not using DHCP set Gateway IP address

#undef  WIFI_SUBNETMASK
#define WIFI_SUBNETMASK        "255.255.255.0"   // [IpAddress3] If not using DHCP set Network mask

#undef  WIFI_DNS
#define WIFI_DNS               "192.168.2.1"     // [IpAddress4] If not using DHCP set DNS IP address (might be equal to WIFI_GATEWAY)

#undef  STA_SSID1
#define STA_SSID1         "*****"             // [Ssid1] Wifi SSID

#undef  STA_PASS1
#define STA_PASS1         "*****"     // [Password1] Wifi password

// -- Setup your own MQTT settings  ---------------
#undef  MQTT_HOST
#define MQTT_HOST         "192.168.2.36" // [MqttHost]

#undef  MQTT_PORT
#define MQTT_PORT         1883                   // [MqttPort] MQTT port (10123 on CloudMQTT)

#undef  MQTT_USER
#define MQTT_USER         "*****"         // [MqttUser] Optional user

#undef  MQTT_PASS
#define MQTT_PASS         "*****"         // [MqttPassword] Optional password

#undef MQTT_FULLTOPIC 
#define MQTT_FULLTOPIC    "smarthome/%prefix%/%topic%/" // [FullTopic] Subscribe and Publish full topic name - Legacy topic


// -- Time - Up to three NTP servers in your region
#undef  NTP_SERVER1
#define NTP_SERVER1            "de.pool.ntp.org"        // [NtpServer1] Select first NTP server by name or IP address (129.250.35.250)
#undef  NTP_SERVER2
#define NTP_SERVER2            "0.de.pool.ntp.org"      // [NtpServer2] Select second NTP server by name or IP address (5.39.184.5)
#undef  NTP_SERVER3
#define NTP_SERVER3            "pool.ntp.org"           // [NtpServer3] Select third NTP server by name or IP address (93.94.224.67)

// -- Location ------------------------------------
#undef LATITUDE
#define LATITUDE               xxxxx         // [Latitude] Your location to be used with sunrise and sunset

#undef LONGITUDE
#define LONGITUDE              xxxxx         // [Longitude] Your location to be used with sunrise and sunset

#undef APP_TIMEZONE     
#define APP_TIMEZONE           +2

// You might even pass some parameters from the command line ----------------------------
// Ie:  export PLATFORMIO_BUILD_FLAGS='-DUSE_CONFIG_OVERRIDE -DMY_IP="192.168.1.99" -DMY_GW="192.168.1.1" -DMY_DNS="192.168.1.1"'


#endif  // _USER_CONFIG_OVERRIDE_H_
