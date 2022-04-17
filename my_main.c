#include <stdio.h>
//*-*#include <pthread.h>

/* Kernel includes. */
#include "../../Source/include/FreeRTOS.h"
#include "../../Source/include/task.h"
#include "../../Source/include/timers.h"
#include "../../Source/include/semphr.h"

/* Local includes. */
//*-*#include "console.h"

/* Priorities at which the tasks are created. */
#define mainQUEUE_TASK_A_PRIORITY    ( tskIDLE_PRIORITY + 1 )
#define mainQUEUE_TASK_B_PRIORITY    ( tskIDLE_PRIORITY + 2 )
#define mainQUEUE_TASK_C_PRIORITY    ( tskIDLE_PRIORITY + 3 )

/* The rate at which data is sent to the queue.  The times are converted from
 * milliseconds to ticks using the pdMS_TO_TICKS() macro. */
#define mainTASK_A_FREQUENCY_MS         pdMS_TO_TICKS( 200UL )

/* The number of items the queue can hold at once. */
#define mainQUEUE_LENGTH                   ( 2 )

/* The values sent to the queue receive task from the queue send task and the
 * queue send software timer respectively. */
#define mainVALUE_SENT_FROM_TASK           ( 100UL )

// ----------- define my tasks

static void myOwnTaskA(void * pvParams);
static void myOwnTaskB(void * pvParams);
static void myOwnTaskC(void * pvParams);
static void _idleWork(int i);


void my_main(void){
    ///-
    /*-* console_print */puts("myOwnMainMethod\n");
    xTaskCreate(myOwnTaskA, "Task A", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_TASK_A_PRIORITY, NULL);

    xTaskCreate(myOwnTaskB, "Task B", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_TASK_B_PRIORITY, NULL);

    xTaskCreate(myOwnTaskC, "Task C", configMINIMAL_STACK_SIZE, NULL, mainQUEUE_TASK_C_PRIORITY, NULL);

    vTaskStartScheduler();

    while (1)
    {}
    //-/
}

static void myOwnTaskA(void * pvParams){

    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    (void) pvParams;
    for (;;){
        /*-* console_print */puts("start A\n");
        _idleWork(25);
        /*-* console_print */puts("stop A\n");
        vTaskDelay(1250);
    }
}

static void myOwnTaskB(void * pvParams){

    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    (void) pvParams;
    for (;;){
        /*-* console_print */puts("\tstart B\n");
        _idleWork(15);
        /*-* console_print */puts("\tstop B\n");
        vTaskDelay(500);
    }
}

static void myOwnTaskC(void * pvParams){

    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    (void) pvParams;
    for (;;){
        /*-* console_print */puts("\t\tstart C\n");
        _idleWork(5);
        /*-* console_print */puts("\t\tstop C\n");
        vTaskDelay(500);
    }
}

static void _idleWork(int i){
    for (int j = 0;j<i;j++){
        for (int k = 0; k<1000;k++){
            for (int l = 0; l<3000;l++){
                ;
            }
        }
    }
}

