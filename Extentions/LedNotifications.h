#include <Arduino.h>
#include <LED.h>

class LedNotifications
{
    public:
        static void BootBlink(LED led){
            led.Blink(10, 50);
            led.BlinkDelay(1000);
        }

        static void InstructionAcceptedBlink(LED led){
              led.Blink(100);
        }
};