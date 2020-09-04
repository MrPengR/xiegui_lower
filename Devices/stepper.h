//
// Created by pry on 2020/8/17.
//

#ifndef TEMPLATE_WITH_UART_STEPPER_H
#define TEMPLATE_WITH_UART_STEPPER_H

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_tim.h"

struct _str_stepper;

typedef struct _str_gpio {
    uint8_t port;
    uint8_t pin;
} str_gpio;

typedef enum {
    CW,
    CCW
} enumStepperDirection;

typedef enum {
    RUNNING,
    STOPPED,
    DISABLED
} enumStepperStatus;

typedef enum {
    MODE_1,
    MODE_2_A,
    MODE_2_B,
    MODE_4,
    MODE_8,
    MODE_16,
    MODE_32
} enumStepperDriverMode;

typedef struct _str_stepper_hardware {
    uint8_t timer_name;
    uint8_t pwm_channel;
    str_gpio pwm;
    str_gpio dir;
    str_gpio ena;
    str_gpio exti_min;
    str_gpio exti_max;
} strStepperHardware;

typedef enum {
    CURRENT_STEPS,
} enumStepperMsgType;

//typedef int8_t (*pFuncStartStepper)(struct _str_stepper *);
//
//typedef int8_t (*pFuncStopStepper)(struct _str_stepper *);
//
//typedef int8_t (*pFuncDisableStepper)(struct _str_stepper *);
//
//typedef int8_t (*pFuncEnableStepper)(struct _str_stepper *);
//
//typedef int8_t (*pFuncModifyCurSteps)(struct _str_stepper *);
//
//typedef int8_t (*pFuncReceiveMsg)(struct _str_stepper *, uint8_t * msg_buf);
//
//typedef int8_t (*pFuncSendMsg)(struct _str_stepper *, uint8_t * msg_buf);

//typedef int8_t (*pFuncReadCurSteps)(struct _str_stepper *);

typedef struct _Stepper {
    //-- variables --//
    enumStepperDirection direction;
    enumStepperStatus status;
    enumStepperDriverMode driver_mode;
    int32_t cur_steps;
//    int32_t cur_angle;
    uint16_t pulse_per_rev;
    strStepperHardware stepper_hardware;
    uint8_t reach_min;
    uint8_t reach_max;
    //-- methods --//

//    pFuncStartStepper stepperStart;
//    pFuncStopStepper stepperStop;
//    pFuncDisableStepper stepperDisable;
//    pFuncEnableStepper enableStepper;
//    pFuncModifyCurSteps stepperModifyCurSteps;
//    pFuncReceiveMsg receiveMsg;
//    pFuncSendMsg sendMsg;
//    pFuncReadCurSteps readCurSteps
} Stepper;

//-- declare functions of stepper --//
int8_t stepperStart(Stepper *stepper);

int8_t initStepper(Stepper *stepper);

int8_t stepperDisable(Stepper *stepper);

int8_t stepperStop(Stepper *stepper);

void stepperTurnAngles(Stepper *stepper, int32_t angles);

void stepperTurnSteps(Stepper *stepper, int32_t steps);

//int8_t calibStepperTransmissionRatio(Stepper *stepper);
void stepperUpdateSteps(Stepper *stepper[], TIM_HandleTypeDef *htim);

Stepper *getOneMotor(void);

#endif //TEMPLATE_WITH_UART_STEPPER_H
