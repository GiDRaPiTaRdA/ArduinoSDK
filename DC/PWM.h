class PWM
{
public:
  int pin;
  const int freq = 5000;
  int pwmChannel = 0;
  const int resolution = 8;
  bool logging = false;


public:
  PWM(int pin)
  {
    PWM::pin = pin;
  }

  PWM(int pin, int pwmChannel)
  {
    PWM::pin = pin;
    PWM::pwmChannel = pwmChannel;
  }


  void Setup()
  {
    ledcSetup(pwmChannel, freq, resolution);

    // attach the channel to the GPIO to be controlled
    ledcAttachPin(pin, pwmChannel);
  }

 
  void SetValue(byte value)
  {
    if (logging)
      Serial.println("SET " + (String)value);

    ledcWrite(pwmChannel, value);
  }

};
