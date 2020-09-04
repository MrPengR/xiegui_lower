//
// Created by pry on 2020/8/17.
//

#include "stepper.h"

int8_t getTIM_HandleTypeDef(TIM_HandleTypeDef *htim, uint8_t timer_name) {
    switch (timer_name) {
        case 1:
            htim->Instance = TIM1;
            break;
        case 2:
            htim->Instance = TIM2;
            break;
        case 3:
            htim->Instance = TIM3;
            break;
        case 4:
            htim->Instance = TIM4;
            break;
#ifdef HAVE_8_TIMERS
            case 5:
                    htim->Instance = TIM5;
                    break;
                case 6:
                    htim->Instance = TIM6;
                    break;
                case 7:
                    htim->Instance = TIM1;
                    break;
                case 8:
                    htim->Instance = TIM1;
                    break;
#endif
        default:
            return -1;
    }
    return 1;
}

int8_t getGPIO_TypeDef(GPIO_TypeDef *port, uint8_t port_name) {
    switch (port_name) {
        case 'A':
            port = GPIOA;
            break;
        case 'B':
            port = GPIOB;
            break;
        case 'C':
            port = GPIOC;
            break;
        case 'D':
            port = GPIOD;
            break;
        case 'E':
            port = GPIOE;
            break;
        default:
            return -1;
    }
    return 1;
}

int8_t stepperStart(Stepper *stepper) {
    TIM_HandleTypeDef htim;
    switch (stepper->status) {
        case STOPPED:
            getTIM_HandleTypeDef(&htim, stepper->stepper_hardware.timer_name);
            HAL_TIM_OC_Start_IT(&htim, stepper->stepper_hardware.pwm_channel);
            stepper->status = RUNNING;
            break;
        case RUNNING:
        case DISABLED:
            //todo handling while disable
            break;
    }
    return 1;
}

int8_t stepperStop(Stepper *stepper) {
    TIM_HandleTypeDef htim;
    switch (stepper->status) {
        case RUNNING:
            getTIM_HandleTypeDef(&htim, stepper->stepper_hardware.timer_name);
            HAL_TIM_OC_Stop_IT(&htim, stepper->stepper_hardware.pwm_channel);
            stepper->status = STOPPED;
            break;
        case STOPPED:
        case DISABLED:
            //todo handling while disable
            break;
    }
    return 1;
}

int8_t stepperDisable(Stepper *stepper) {
    GPIO_TypeDef port;
    if (stepper->status != DISABLED) {
        // To disable a stepper, stop it first
        stepperStop(stepper);
        getGPIO_TypeDef(&port, stepper->stepper_hardware.ena.port);
        HAL_GPIO_WritePin(&port, stepper->stepper_hardware.ena.pin, GPIO_PIN_RESET);
        stepper->status = DISABLED;
    }
    return 1;
}

int8_t stepperEnable(Stepper *stepper) {
    GPIO_TypeDef port;
    if (stepper->status == DISABLED) {
        // To enable a stepper, stop it after enabled
    	getGPIO_TypeDef(&port, stepper->stepper_hardware.ena.port);
        HAL_GPIO_WritePin(&port, stepper->stepper_hardware.ena.pin, GPIO_PIN_SET);
        stepperStop(stepper);
        stepper->status = STOPPED;
    }
    return 1;
}

int8_t stepperChangeDirection(Stepper *stepper, enumStepperDirection direction) {
    GPIO_TypeDef port;
    getGPIO_TypeDef(&port, stepper->stepper_hardware.dir.port);
    switch (direction) {
        case CW:
            HAL_GPIO_WritePin(&port, stepper->stepper_hardware.dir.pin, GPIO_PIN_SET);
            stepper->direction = CW;
            break;
        case CCW:
            HAL_GPIO_WritePin(&port, stepper->stepper_hardware.dir.pin, GPIO_PIN_RESET);
            stepper->direction = CCW;
            break;
    }
    return 1;
}

void stepperTurnSteps(Stepper *stepper, int32_t steps) {

}


void stepperTurnAngles(Stepper *stepper, int32_t angles) {

}


int8_t stepperChangeSpeedSpr(Stepper *stepper, uint16_t spr) {
    //todo
}

void stepperUpdateSteps(Stepper *stepper[], TIM_HandleTypeDef *htim) {
    TIM_HandleTypeDef tmp_htim;
    for (uint8_t i = 0; i < sizeof(*stepper); i++) {
    	getTIM_HandleTypeDef(&tmp_htim, stepper[i]->stepper_hardware.timer_name);
        if (htim == &tmp_htim) {
            stepper[i]->cur_steps += 1;
            break;
        }
    }
}


//int8_t stepperStartReachLimitIt(Stepper *stepper) {
//
//}
//
//int8_t stepperReachMinLimit(Stepper *stepper) {
//
//    stepper->reach_min = 1;
//    stepperStop(stepper);
//}

//int8_t calibStepperTransmissionRatio(Stepper *stepper) {
//
//
//    stepperChangeSpeedSpr(stepper, 5);         // change to a very low speed
//    stepperChangeDirection(stepper, CW);   // start from run CW
//    stepperStart(stepper);
//    while (1) {
//        if (stepper->reach_min) {
//            stepper->cur_steps = 0;
//            break;
//        } else if (stepper->reach_max) {
//            break;
//        }
//    }
//
//}


int8_t stepperModifyCurSteps(Stepper *stepper) {
    int32_t cur_steps;
//    uint8_t *request_cur_steps;

    stepperDisable(stepper);
//    stepper->sendMsg(stepper, request_cur_steps);
//    stepper->receiveMsg(stepper, (uint8_t *) &cur_steps);
    stepper->cur_steps = cur_steps;

    return 1;
}

//int8_t implReadCurSteps(Stepper *stepper) {
//    int32_t cur_steps;
//    uint8_t *command;
//    stepper->sendMsg(stepper, command);
//    stepper->receiveMsg(stepper, (uint8_t *) &cur_steps);
//    stepper->cur_steps = cur_steps;
//}

int8_t initStepper(Stepper *stepper) {
//    stepper->stepperStart = implStartStepper;
//    stepper->stepperStop = implStopStepper;
    return 1;
}
