//
// Created by R. on 2020/8/28.
//

#ifndef TEST_STEPPER_PLATFORM_2DOF_H
#define TEST_STEPPER_PLATFORM_2DOF_H

#include "stm32f1xx_hal.h"
#include "stepper.h"

void *MotorType;

typedef void (*pMotorTurnAngles)(void *motor, int32_t angles);

pMotorTurnAngles motorTurnAngles;

typedef struct _Platform2DOF {
    void *motor_x;
    void *motor_y;
} Platform2DOF;

//void registerMotors(void);

void moveToXY(Platform2DOF *platform_2dof, uint32_t x, uint32_t y);

void initPlatform2DOF(Platform2DOF * platform_2dof);

#endif //TEST_STEPPER_PLATFORM_2DOF_H
