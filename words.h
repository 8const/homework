#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;

// returns lenght of the longest word in string;
u8 longest(char *str)
{
        u8 max(u8 a, u8 b)
        {
                if (a > b) 
                        return a;
                else 
                        return b;
        }

        u8 m = 0;
        u8 longest = 0;
        for (u8 i = 0; str[i]; i++) {
                if (!(str[i] - 32)) 
                        m++;
                else 
                longest = max(longest, m);
                }
        return longest;
}

// counts words in string;
u8 words(char *str)
{
        u8 w = 1;
        if (*str == 32)
                w--;
        for (u8 i = 0; str[i]; i++) {
                if (!(str[i] - 32) && str[i + 1] - 32) {
                        w++;
                }
        }
        return w;
}

