

//***********ไฟวิ่งไปกลับ*************/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "LED.h"

LED led1(16); 
LED led2(17); 
LED led3(5); 
LED led4(18); 
LED led5(19); 
LED led6(21); 
LED led7(22); 
LED led8(23); 

LED leds[] = {led1, led2, led3, led4, led5, led6, led7, led8};

extern "C" void app_main(void)
{
    int i = 0;         // Start index for the LED
    int direction = 1; // Direction: 1 for right, -1 for left

    while(1)
    {        
        // Turn ON the current LED
        leds[i].ON();
        
        // Delay for a while
        vTaskDelay(200 / portTICK_PERIOD_MS);
        
        // Turn OFF the current LED
        leds[i].OFF();
        
        // Update the index based on direction
        i += direction;

        // Change direction if at the ends
        if (i >= 8 || i < 0) {
            direction = -direction; // Reverse direction
            i += direction; // Adjust index after reversing direction
        }
    }
}
