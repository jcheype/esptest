/******************************************************************************
 * Copyright 2013-2014 Espressif Systems (Wuxi)
 *
 * FileName: user_main.c
 *
 * Description: entry file of user application
 *
 * Modification history:
 *     2014/12/1, v1.0 create this file.
*******************************************************************************/
#include "esp_common.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "uart.h"
#include "gpio.h"


void task2(void *pvParameters)
{
	int i=0;
    while (1) {
		i=(i+1)%2;
	    printf("LOOP %d\r\n", i);
		GPIO_OUTPUT_SET(GPIO_Pin_2, i);
        vTaskDelay(4000 / portTICK_RATE_MS);
    }
}

/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void ICACHE_FLASH_ATTR
user_init(void)
{
	uart_init_new();
	//UART_SetBaudrate(UART0,115200);
    printf("HELLO\r\n");


    xTaskCreate(task2, "tsk2", 256, NULL, 2, NULL);
}

