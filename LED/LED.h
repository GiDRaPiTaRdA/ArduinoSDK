class LED
{
public:
   int ledPin;
   bool blinking;
   const int delayTime = 1000;
   bool logging = false;
   bool inverted = false;

public:
   LED(int pin)
   {
      LED:ledPin = pin;
   }

    LED(int pin, bool inverted)
   {
      LED:ledPin = pin;
      LED::inverted = inverted;
   }

   void Setup()
   {
      pinMode(ledPin, OUTPUT);
   }

   void Light(bool on)
   {
      if (on)
      {
         LightOn();
      }
      else
      {
         LightOff();
      }
   }

   void LightOn()
   {
      if (logging)
         Serial.println("ON");

      if(!inverted)
         digitalWrite(ledPin, HIGH);
      else
         digitalWrite(ledPin, LOW);      
   }

   void LightOff()
   {
      if (logging)
         Serial.println("OFF");
         
        if(!inverted)
         digitalWrite(ledPin, LOW);
      else
         digitalWrite(ledPin, HIGH);      
   }

   void Blink(int times,int delayTime)
   {
      for (int i = 0; i < times; i++)
      {
         if(i==times-1){
            // Final
            Blink(delayTime);
         }
         else{
            // Other
            BlinkDelay(delayTime);
         }
      }
   }

   void BlinkDelay(int delayTime)
   {
      Light(true);
      delay(delayTime);
      Light(false);
      delay(delayTime);
   }

   void Blink(int delayTime)
   {
      Light(true);
      delay(delayTime);
      Light(false);
   }
};
