class SegmentDisplay
{

public:
  const static int maxDisplayValue = 99;

private:
  int GPIO_DS;
  int GPIO_STCP;
  int GPIO_SHCP;

  int GPIO_GND1;
  int GPIO_GND2;

  int sections[2];

  byte q0 = 1 << 7;
  byte q1 = 1 << 6;
  byte q2 = 1 << 5;
  byte q3 = 1 << 4;
  byte q4 = 1 << 3;
  byte q5 = 1 << 2;
  byte q6 = 1 << 1;
  byte q7 = 1;

  byte dA = q6;
  byte dB = q0;
  byte dC = q1;
  byte dD = q3;
  byte dE = q2;
  byte dF = q7;
  byte dG = q4;
  byte dDp = q5;

  byte digits[11]{
      dA | dB | dC | dD | dE | dF,        // 0
      dB | dC,                            // 1
      dA | dB | dG | dE | dD,             // 2 
      dA | dB | dG | dC | dD,             // 3
      dF | dG | dB | dC,                  // 4
      dA | dF | dG | dC | dD,             // 5
      dA | dF | dG | dC | dD | dE,        // 6
      dA | dB | dC,                       // 7
      dA | dB | dC | dD | dE | dF | dG,   // 8
      dG | dF | dA | dB | dC | dD,        // 9
      0                                   // None
      };      

  byte number[2] = {0, 0};

 

public:
  SegmentDisplay(int dsPin, int stcpPin, int shcpPin, int gnd1Pin, int gnd2Pin)
  {
    GPIO_DS = dsPin;
    GPIO_STCP = stcpPin;
    GPIO_SHCP = shcpPin;

    GPIO_GND1 = gnd1Pin;
    GPIO_GND2 = gnd2Pin;

    sections[0] = GPIO_GND1;
    sections[1] = GPIO_GND2;
  }

  

  void Off(){
    number[0] = 10;
    number[1] = 10;
  }

  void Setup()
  {
    pinMode(GPIO_DS, OUTPUT);
    pinMode(GPIO_STCP, OUTPUT);
    pinMode(GPIO_SHCP, OUTPUT);

    pinMode(GPIO_GND1, OUTPUT);
    pinMode(GPIO_GND2, OUTPUT);

    digitalWrite(GPIO_DS, LOW);
    digitalWrite(GPIO_STCP, LOW);
    digitalWrite(GPIO_SHCP, LOW);

    digitalWrite(GPIO_GND1, LOW);
    digitalWrite(GPIO_GND2, LOW);
  }

void DisplayNumber(byte n)
  {
    if(n<0)
      n = 0;
    if(n>maxDisplayValue)
      n = maxDisplayValue;

    byte d1 = n / 10;
    byte d2 = n % 10;

    number[0] = d1;
    number[1] = d2;
  }


  void SetSection1(int sectionId)
  {
    for (int i = 0; i < sizeof(sections); i++)
    {
      DigitalWrite(sections[i], !(i == sectionId));
    }
  }

  void SetSection(int sectionId)
  {
    for (int i = 0; i < sizeof(sections); i++)
    {
      if (i != sectionId)
      {
        digitalWrite(sections[i], LOW);
      }
    }
    digitalWrite(sections[sectionId], HIGH);
  }

  void DigitalWrite(int pin, bool high)
  {
    if (high)
      digitalWrite(pin, HIGH);
    else
      digitalWrite(pin, LOW);
  }

  void SetPanelPattern(byte digit)
  {
    digitalWrite(GPIO_STCP, LOW);
    shiftOut(GPIO_DS, GPIO_SHCP, LSBFIRST, digit);
    digitalWrite(GPIO_STCP, HIGH);
  }

  void Display()
  {
    Display(number[0], number[1]);
  }

  void Display(byte n1, byte n2)
  {
    SetSection(0);

    SetPanelPattern(digits[n1]);

    delay(5);

    SetPanelPattern(digits[n2]);

    SetSection(1);

    delay(5);
  }
};
