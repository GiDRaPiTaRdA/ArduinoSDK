class FAN: public  PWM
{
  public:
    FAN(int pin) : PWM{ pin }
    {
    }

    FAN(int pin, int pwmChannel): PWM{ pin, pwmChannel}
    {
    }
};
