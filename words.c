#include "words.h"

/*
 * returns lenght of the longest word in string;
 * overcounts by one if last word is longest;
 */
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
                if (str[i] - 32) {
                        m++;
                } else {
                        longest = max(longest, m);
                        m = 0;
                }
        }
                
        return max(longest, m);
}

/*
 * counts words in string;
 * overcounts if ends with a space; 
 */
u8 words(char *str)
{
        /*
         * all of the 32 arithmetic is a weird way to compare char to space;
         * 32 is the ascii number of a space char;
         * i use it for like no reason;
         * it just feels good;
         */
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

/* fills a with pointers to words in str; */
void tokenize(char **a, char *str, u8 WORDS)
{
        const char s[2] = " ";
        *a = strtok(str, s);
        u8 i = 1;
        while (i < WORDS) {
                a[i] = strtok(NULL, s);
                i++;
        }
}

/*
 * fills sentence with words from w; 
 * order of args is as in intel assembly or string.h: destination sourse; 
 */
void fill(char *sentence, char **w, u8 WORDS)
{
        const char s[2] = " ";
        for (u8 i = 0; i < WORDS; i++) {
                strcat(sentence, w[i]);
                strcat(sentence, s);
        } 
}

/* reverses string by assigment but it also returns the string:wq; */
char *strrev(char *str)
{
        u8 n = strlen(str);

        void swap(char *a, char* b)
        {
                char temp = *a;
                *a = *b;
                *b = temp;
        }

        for (u8 i = 0; i < n / 2 ; i++) {
                swap(str + i, str + n - 1 - i);
        }
        return str;
}
