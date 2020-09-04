//
// Created by R. on 2020/9/3.
//

#ifndef LOWER_MAIN_APP_H
#define LOWER_MAIN_APP_H

#include "FreeRTOS.h"
#include "task.h"
//#include "main.h"
#include "cmsis_os.h"
#include "cmd_handler.h"
#include "stm32f1xx_hal.h"
#include "../../Devices/serial_port.h"

// user functions:
#include "../../Modules/platform_2_dof.h"

__NO_RETURN void main_app_loop(void);



void PlatformMoving();

/**
 * heater threads
 */
 // todo

// ......

#endif //LOWER_MAIN_APP_H
