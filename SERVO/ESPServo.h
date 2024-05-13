#include <esp32-hal-ledc.h>

class Servo {
  public:
    int pin;
    int channel;
    int maxDegrees = 180;

  private:
    uint32_t servoMax = 8300;
    uint32_t servoMin = 2100;
    uint32_t servoCenter = (servoMin + servoMax) / 2;

    // channel 1, 50 Hz, 16-bit width
    int frequency = 50;
    int width = 16;


  public:
    Servo(int pin) :Servo(pin,1) {}
    
    Servo(int pin, int channel) {
      Servo::pin = pin;
      Servo::channel = channel;
    }

    void Setup() {
      ledcSetup(channel, frequency, width);
      ledcAttachPin(pin, channel);   // GPIO servoPin on channel X
    }

    void Home() {
      SetDegree(0);
    }

    void Center() {
      SetDegree(maxDegrees / 2);
    }

    void Max() {
      SetDegree(maxDegrees);
    }

    void SetDegree(float servoDegrees) {
      int a = servoMin + ((servoMax - servoMin) * servoDegrees) / maxDegrees;

      ledcWrite(channel, a );
    }
};
