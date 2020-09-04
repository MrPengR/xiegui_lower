//
// Created by R. on 2020/9/1.
//

#include "serial_port.h"

volatile uint8_t uart_rx_buffer[UART_RX_BUF_SIZE];
volatile uint8_t uart_recv_end_flag;
volatile uint8_t uart_rx_len;

void vprint(const char *fmt, va_list argp) {
    char string[200];
    if (0 < vsprintf(string, fmt, argp)) // build string
    {
        HAL_UART_Transmit(&huart1, (uint8_t *) string, strlen(string), 0xffff); // send message via UART
//        HAL_UART_Transmit(&huart2, (uint8_t *) string, strlen(string), 0xffff); // send message via UART
    }
}

void uart_printf(const char *fmt, ...) // custom printf() function
{
    va_list argp;
    va_start(argp, fmt);
    vprint(fmt, argp);
    va_end(argp);
}

