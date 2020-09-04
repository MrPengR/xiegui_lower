//
// Created by R. on 2020/9/1.
//

#ifndef LOWER_SERIAL_PORT_H
#define LOWER_SERIAL_PORT_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "stm32f1xx_hal.h"

#define UART_RX_BUF_SIZE 40

extern UART_HandleTypeDef huart1;

//extern UART_HandleTypeDef huart2;
void uart_printf(const char *fmt, ...);

//uint8_t commandParser(const uint8_t *uart_rx_buffer, str_command *command);

//#include "stepper.h"

//void vprint(const char *fmt, va_list argp);

#endif //LOWER_SERIAL_PORT_H
