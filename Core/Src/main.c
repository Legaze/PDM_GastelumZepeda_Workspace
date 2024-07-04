/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdio.h>  // entrada/salida como printf
#include <time.h>   // tiempo actual

// Tiempo actual en ticks
static tick_t getCurrentTick() {
    return (tick_t)clock();  // Utiliza clock() para obtener el tiempo actual en ticks
}

void delayInit(delay_t *delay, tick_t duration) {
    delay->duration = duration;
    delay->running = false;
}

bool_t delayRead(delay_t *delay) {
    if (!delay->running) {
        delay->startTime = getCurrentTick();
        delay->running = true;
        return false;
    } else {
        tick_t currentTime = getCurrentTick();
        if ((currentTime - delay->startTime) >= delay->duration) {
            delay->running = false;
            return true;
        } else {
            return false;
        }
    }
}

void delayWrite(delay_t *delay, tick_t duration) {
    delay->duration = duration;
}

int main() {
    delay_t myDelay;
    delayInit(&myDelay, 1000); // Iniciadelay con 1000 ticks

    while (1) {
        if (delayRead(&myDelay)) {
            printf("Delay completed\n");
            delayWrite(&myDelay, 2000); // Cambia delay a 2000 ticks
        }

    }

    return 0;
}


