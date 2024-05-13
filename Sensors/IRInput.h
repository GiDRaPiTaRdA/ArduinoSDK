#include <Arduino.h>
#include "IRremote.h"

class IRInput
{
    int irPin;

public:
// Codes
#pragma region Buttin codes
    // Button codes
    static const int but0 = 0x000019;
    static const int but1 = 0x000045;
    static const int but2 = 0x000046;
    static const int but3 = 0x000047;
    static const int but4 = 0x000044;
    static const int but5 = 0x000040;
    static const int but6 = 0x000043;
    static const int but7 = 0x000007;
    static const int but8 = 0x000015;
    static const int but9 = 0x000009;

    static const int butOk = 0x00001C;

    static const int butStar = 0x000016;
    static const int butHash = 0x00000D;

    static const int butUp = 0x000018;
    static const int butDown = 0x000052;

    static const int butLeft = 0x000008;
    static const int butRight = 0x00005A;
#pragma endregion

    IRrecv irrecv;

    IRInput(int irPin)
    {
        IRInput::irPin = irPin;
    }

    void Setup()
    {
        irrecv = IRrecv(irPin);
        irrecv.enableIRIn();
    }

    uint16_t GetCommand()
    {
        return irrecv.decodedIRData.command;
    }

    bool Decode()
    {
        return irrecv.decode();
    }

    void Resume()
    {
        irrecv.resume();
    }

    static int SwitchButton(uint16_t cmd)
    {
        switch (cmd)
        {
        case IRInput::but0:
            return 0;
        case IRInput::but1:
            return 1;
        case IRInput::but2:
            return 2;
        case IRInput::but3:
            return 3;
        case IRInput::but4:
            return 4;
        case IRInput::but5:
            return 5;
        case IRInput::but6:
            return 6;
        case IRInput::but7:
            return 7;
        case IRInput::but8:
            return 8;
        case IRInput::but9:
            return 9;
        default:
            return -1;
        }
    }
};
