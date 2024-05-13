class MotorDC {
  private:
    int STBY = 5;

    int PWM;
    int IN1;
    int IN2;
    int channel;

   
    int width = 8;

  public:
    int frequency = 5000;

    MotorDC(int in1, int in2, int pwm, int stby): MotorDC(in1, in2, pwm, stby, 1) {}

    MotorDC(int in1, int in2, int pwm, int stby, int channel) {
      MotorDC::IN1 = in1;
      MotorDC::IN2 = in2;
      MotorDC::PWM = pwm;
      MotorDC::STBY = stby;
      MotorDC::channel = channel;
    }

    void Setup() {
      pinMode(STBY, OUTPUT);
      pinMode(IN1, OUTPUT);
      pinMode(IN2, OUTPUT);

      // PWM
      ledcSetup(channel, frequency, width);
      ledcAttachPin(PWM, channel);

      //Enable
      StandBy(true);
    }
    
    void StandBy(bool stby) {
      digitalWrite(STBY, stby);
    }

    void Drive(int motorSpeed) {

      if (motorSpeed >= 0) {
        if (motorSpeed > 255) {
          motorSpeed = 255;
        }

        Forward(motorSpeed);
      }
      else {
        if (motorSpeed < 255) {
          motorSpeed = -255;
        }

        Backward(motorSpeed);
      }
    }

    void Forward(byte motorSpeed) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      ledcWrite(channel, motorSpeed);
    }
    
    void Backward(byte motorSpeed) {
      digitalWrite(IN2, HIGH);
      digitalWrite(IN1, LOW);
      ledcWrite(channel, motorSpeed);
    }

    void Stop() {
      Forward(0);
    }

    void Disable() {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      ledcWrite(channel, 0);
    }
};
