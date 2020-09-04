//
// Created by R. on 2020/9/3.
//

#include "main_app.h"

extern volatile uint8_t uart_rx_buffer[UART_RX_BUF_SIZE];
extern volatile uint8_t uart_recv_end_flag;
extern volatile uint8_t uart_rx_len;

/**
 * This function is called inside the main_app() in freertos.c
 * @return  None
 */
__NO_RETURN void main_app_loop(void) {
    uint8_t state[10] = "stopped";
    Command command;
    while (1) {
        if (uart_recv_end_flag) {
            commandParser(uart_rx_buffer, &command);
            switch (command.target) {
                case kAll:
                    break;
                case kPlatform2Dof:
                    if (command.job == kMoveToXY) {
                        // todo: must register platform at first
//                        platformMoveToXY()
                    }
                    // todo:
                    // platfrom2DofCmd(command);
                    break;
            }

            uart_recv_end_flag = 0;
            memset(uart_rx_buffer, 0, sizeof(uart_rx_buffer));
        }
        osDelay(1);
    }

}

/**
 * todo: need to specify parameters
 */
void platformMoving () {

}
