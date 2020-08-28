//
// Created by R. on 2020/8/28.
//

#include "platform_2_dof.h"

//void registerMotors(void) {
//    Stepper * motor_x = getOneMotor();
//}

void moveToXY(Platform2DOF *platform_2dof, uint32_t x, uint32_t y) {
    motorTurnAngles(platform_2dof->motor_x, 123);
    motorTurnAngles(platform_2dof->motor_y, 123);
}

void initPlatform2DOF(Platform2DOF * platform_2dof) {
    motorTurnAngles = stepperTurnAngles;
}



void test(void) {
    Platform2DOF platform_2dof;
    platform_2dof.motor_x = getOneMotor();
    platform_2dof.motor_y = getOneMotor();
    moveToXY(&platform_2dof, 123, 123);
}

