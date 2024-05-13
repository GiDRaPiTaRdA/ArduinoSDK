#include "Math.h"

class Termistor
{

  private:
    // 3.3 v   0-4095
    const int maxDigitalInput12Bit = 4095; // of 12 bit
    const int maxDigitalInput10Bit = 1023; // of 10 bit
    const double maxV = 3.3f;               // voltage
  public:

    int analogInPin;

    const int maxTemperature = 300;
    const int minTemperature = -55;

    Termistor(int analogInPin)
    {
      Termistor::analogInPin = analogInPin;
    }

    void Setup() {
      pinMode(analogInPin, INPUT);
    }

    int GetRawData() {
      double temperature = analogRead(analogInPin);

      //Serial.println(temperature);

      return temperature;
    }

    float GetTemperature() {
      int count = 10;

      int temperature = 0;

      for (int i = 0; i < count; i++) {
        temperature += GetRawData();
      }

      temperature /= count;


      int bits10Value = (double)temperature * maxDigitalInput10Bit / maxDigitalInput12Bit;
      double voltage = (double)temperature * maxV / maxDigitalInput12Bit;

      double r = temperature * 130000 / (maxDigitalInput12Bit - temperature);

      float t = Termistor::FahrenheitToCelsius(Termistor::Function(r));

      return t;
    }

    static float Function(double temperatureData) {

      double x = ((double)temperatureData);

      double y = 0;

      float temperature = 0;

      double point = 326685.277;

      // Hot
      if (x <= point) {

        //        Serial.println("Hot");
        int a = 79;
        int b = 120;
        int w = -6300;
        int h = 634;

        y = (-a) * log10((x + w) * b) + h;
      }
      // Cold
      else {
        //        Serial.println("Cold");
        float a = 61.8f;
        int b = 71;
        int w = -84000;
        int h = 482;

        y = -a * log10((x + w) * b) + h;
      }

      temperature = y;

      return temperature;
    }

    static float FahrenheitToCelsius(float temperatureFahrenheit) {
      float celsius = ((double)temperatureFahrenheit - 32) * ((double)5 / 9);

      return celsius;
    }
};
