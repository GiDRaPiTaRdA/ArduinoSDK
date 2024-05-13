class CapasitiveMoistureSensor {

  private:
    int GPIO_ANALOG_INPUT;

    int sensorMax = 3500;
    int sensorMin = 1600;

    int sensorRange =sensorMax-sensorMin;

  public:
    CapasitiveMoistureSensor(int analogInputPin) {
      GPIO_ANALOG_INPUT = analogInputPin;
    }

    void Setup() {
      pinMode(GPIO_ANALOG_INPUT, INPUT);
    }

    int ReadMoisture() {
      int value = analogRead(GPIO_ANALOG_INPUT);

      value  = sensorMax - value;

      if(value<0)
        value =0;
      
      // if(value>sensorRange)
      //   value =sensorRange;
      
      return value;
    }


    int ReadMoisture(int maxPercentage) {

      int quality = 10;

      int moisture = 0;

       for (int i = 0; i < quality; i++) {
        moisture += ReadMoisture();
      }

      moisture/=quality;

      int arrange = moisture*maxPercentage/sensorRange;

      return arrange;
    }

    int ReadMoistureByte() {
       return ReadMoisture(255);
    }

     int ReadMoisturePercentage() {
       return ReadMoisture(100);
    }

};
