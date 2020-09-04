//
// Created by R. on 2020/9/3.
//

#ifndef LOWER_CMD_HANDLER_H
#define LOWER_CMD_HANDLER_H

#include "stm32f1xx_hal.h"

typedef enum _Cmd_Target {
    kAll = 0x00,
    kPlatform2Dof = 0x10,
} Cmd_Target;

typedef enum _Cmd_Job {
    kStart = 0x00,

    kMoveToXY = 0x10,
    // todo: kCalibrate ...

    kStop = 0xff
} Cmd_Job;

typedef struct _Command {
    Cmd_Target target;
    Cmd_Job job;
    uint32_t value;
} Command;

void commandParser(uint8_t *rx_buffer, Command * command);

#endif //LOWER_CMD_HANDLER_H
