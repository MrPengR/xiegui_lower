//
// Created by R. on 2020/9/3.
//

#include "cmd_handler.h"


void commandParser(uint8_t *rx_buffer, Command * command) {
    union uni_value {
        struct {
            uint8_t byte_1: 8;
            uint8_t byte_2: 8;
            uint8_t byte_3: 8;
            uint8_t byte_4: 8;
        } four_bytes;
        uint32_t whole_value;
    };
    union uni_value value;

    command->device = *(rx_buffer + 0);
    command->task = *(rx_buffer + 1);

    value.four_bytes.byte_4 = *(rx_buffer + 2);
    value.four_bytes.byte_3 = *(rx_buffer + 3);
    value.four_bytes.byte_2 = *(rx_buffer + 4);
    value.four_bytes.byte_1 = *(rx_buffer + 5);
    command->value = value.whole_value;
}

