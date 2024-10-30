

//***********ไฟวิ่งสองดวงสวนกันตรงกลาง*************/
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
    int leftIndex = 0;      // Starting index for the left LED
    int rightIndex = 7;     // Starting index for the right LED

    while(1)
    {        
        // Turn ON the current left and right LEDs
        leds[leftIndex].ON();
        leds[rightIndex].ON();
        
        // Delay for a while
        vTaskDelay(200 / portTICK_PERIOD_MS);
        
        // Turn OFF the current left and right LEDs
        leds[leftIndex].OFF();
        leds[rightIndex].OFF();
        
        // Move to the next LEDs (left moves to the right, right moves to the left)
        leftIndex = (leftIndex + 1) % 4;  // Move left index towards the center
        rightIndex = (rightIndex - 1 + 8) % 8; // Move right index towards the center
    }
}
