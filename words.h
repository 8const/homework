#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;

/*
 * returns lenght of the longest word in string;
 * overcounts by one if last word is longest;
 */
u8 longest(char *str);

/*
 * counts words in string;
 * overcounts if ends with a space; 
 */
u8 words(char *str);

/* fills a with pointers to words in str; */
void tokenize(char **a, char *str, u8 WORDS);

/*
 * fills sentence with words from w; 
 * order of args is as in intel assembly or string.h: destination sourse; 
 */
void fill(char *sentence, char **w, u8 WORDS);

/* reverses string by assigment but it also returns the string:wq; */
char *strrev(char *str);

