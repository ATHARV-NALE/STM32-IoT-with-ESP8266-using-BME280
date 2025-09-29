/*
 ***************************************************************************************************************
 ***************************************************************************************************************
 ***************************************************************************************************************

  File:		  ESP8266_STM32.h
  Author:     ControllersTech.com
  Updated:    Sep 6, 2025

 ***************************************************************************************************************
  Copyright (C) 2017 ControllersTech.com

  This is a free software under the GNU license, you can redistribute it and/or modify it under the terms
  of the GNU General Public License version 3 as published by the Free Software Foundation.
  This software library is shared with public for educational purposes, without WARRANTY and Author is not liable for any damages caused directly
  or indirectly by this software, read more about this on the GNU General Public License.

 ***************************************************************************************************************
 */


#ifndef ESP8266_STM32_H
#define ESP8266_STM32_H

#include "main.h"   // Change to your STM32 family header
#include <string.h>
#include <stdio.h>

/* ------------ USER CONFIG ------------- */
#define ESP_UART       huart4   // UART connected to ESP8266

// Enable/Disable logs
#define ENABLE_USER_LOG   1
#define ENABLE_DEBUG_LOG  0
/* -------------------------------------- */

extern UART_HandleTypeDef ESP_UART;

/* ------------ LOG MACROS ------------- */
#if ENABLE_USER_LOG
  #define USER_LOG(fmt, ...) printf("[USER] " fmt "\r\n", ##__VA_ARGS__)
#else
  #define USER_LOG(fmt, ...)
#endif

#if ENABLE_DEBUG_LOG
  #define DEBUG_LOG(fmt, ...) printf("[DEBUG] " fmt "\r\n", ##__VA_ARGS__)
#else
  #define DEBUG_LOG(fmt, ...)
#endif
/* ------------------------------------- */

/* ------------ ENUMS & STATES --------- */
typedef enum {
    ESP8266_OK = 0,
    ESP8266_ERROR,
    ESP8266_TIMEOUT,
    ESP8266_NO_RESPONSE,
} ESP8266_Status;

typedef enum {
    ESP8266_DISCONNECTED = 0,
    ESP8266_CONNECTED_NO_IP,
    ESP8266_CONNECTED_IP
} ESP8266_ConnectionState;

extern ESP8266_ConnectionState ESP_ConnState;
/* ------------------------------------- */

/* ------------ API FUNCTIONS ---------- */
ESP8266_Status ESP_Init(void);
ESP8266_Status ESP_ConnectWiFi(const char *ssid, const char *password, char *ip_buffer, uint16_t buffer_len);
ESP8266_ConnectionState ESP_GetConnectionState(void);
ESP8266_Status ESP_SendToThingSpeak(const char *apiKey, float val1, float val2, float val3);
/* ------------------------------------- */


#endif // ESP8266_H
