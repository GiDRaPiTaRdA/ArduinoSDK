class LEDPWM
{
public:
  int ledPin;
  const int freq = 5000;
  int ledChannel = 0;
  const int resolution = 8;
  bool logging = false;

private:
  

public:
  LEDPWM(int pin)
  {
    ledPin = pin;
  }

  LEDPWM(int pin, int ledChannel)
  {
    ledPin = pin;
    LEDPWM::ledChannel = ledChannel;
  }

  void Setup()
  {
    ledcSetup(ledChannel, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(ledPin, ledChannel);
  }

  void Light(bool on, int time)
  {
    if (on)
    {
      LightOn(time);
    }
    else
    {
      LightOff(time);
    }
  }

  void Light(bool on)
  {
    Light(on, 0);
  }

  void SetLight(byte value)
  {
    if (logging)
      Serial.println("SET " + (String)value);

    ledcWrite(ledChannel, value);
  }

  void LightOn(int time)
  {
    if (logging)
      Serial.println("ON");
    // increase the LED brightness
    for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++)
    {
      // changing the LED brightness with PWM
      SetLight(dutyCycle);
      delay((int)(time / 255));
    }
  }

  void LightOff(int time)
  {
    if (logging)
      Serial.println("OFF");
    for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--)
    {
      // changing the LED brightness with PWM
      SetLight(dutyCycle);
      delay((int)(time / 255));
    }
  }

  void LightOn()
  {
    LightOn(0);
  }

  void LightOff()
  {
    LightOff(0);
  }

  void Blink(int time)
  {
    LightOn(time / 2);
    LightOff(time / 2);
  }
};
