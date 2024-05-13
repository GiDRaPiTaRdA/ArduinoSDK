#include <Arduino.h>
#include <vector>

class StringExtension
{
public:
    static u_int16_t CountChar(String string, char ch)
    {
        u_int16_t counter = 0;
        for (int i = 0; i < string.length(); i++)
        {
            char chi = string.charAt(i);
            if (chi == ch)
                counter++;
        }

        return counter;
    }

    static u_int16_t *FindChars(String string, char splitChar, u_int16_t *countIndexes)
    {

        u_int16_t countChars = CountChar(string, splitChar);

        u_int16_t *charIndexes = new u_int16_t[countChars];
        u_int16_t index = 0;

        uint16_t size = string.length();
        for (uint16_t i = 0; i < size; i++)
        {
            char ch = string.charAt(i);
            if (ch == splitChar)
            {
                charIndexes[index] = i;
                index++;
            }
        }

        *countIndexes = index;

        return charIndexes;
    }

    static String *SplitString(String string, char splitChar, u_int8_t *substringsCount)
    {
        u_int16_t countIndexes = 0;
        u_int16_t *charIndexes = FindChars(string, splitChar, &countIndexes);

        u_int8_t count = countIndexes - 1;

        bool hasStart = charIndexes[0] > 0;
        bool hasFinish = charIndexes[countIndexes - 1] < string.length();

        // if(countIndexes>0){
        //     if(hasStart)
        //         count++;
        //     if(hasFinish)
        //         count++;
        // }

        count += 2;

        *substringsCount = count;

        String *substrings = new String[count];

        for (u_int8_t i = 0; i < count; i++)
        {
            u_int16_t start = 0;

            if (i == 0)
            {
                start = 0;
            }
            else
            {
                start = charIndexes[i - 1] + 1;
            }

            u_int16_t finish = charIndexes[i];

            String substring = string.substring(start, finish);
            substrings[i] = substring;
        }

        delete[] charIndexes;

        return substrings;
    }
};