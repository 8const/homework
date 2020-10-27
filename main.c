#include "words.h"
// u8 stands for unsigned 8 bit integer from stdint.h; it's renamed uint8_t; 

u8 main(void)
{
        // LEN is number of bytes in input string;
        const u8 LEN = 255; 

        // str is the input string;
        char str[LEN];
        puts("Enter the sentence:");
        fgets(str, LEN / 2, stdin);
        puts(" "); 
        // number of words in inputa;
        const u8 WORDS = words(str); 

        // the longest word in input;
        const u8 L = longest(str);
        

        // allocation for the array of pointers to words;
        char **w= (char **) malloc(sizeof(char **) * WORDS);
        for (u8 i = 0; i < WORDS; i++) {
                w[i] =(char *) malloc(sizeof(char *) * L + 4);
        }
        
        // tokenisation of str; words are stored in a;
        char **a = (char **) malloc(WORDS * sizeof(char *) + 4);
        const char s[2] = " ";
        *a = strtok(str, s);
        u8 i = 1;
        while (i < WORDS) {
                a[i]= strtok(NULL, s);
                i++;
        }
        
        // copying words to an array of words for like no reason;
        for (i = 0; i < WORDS; i++) 
                strcpy(w[i], a[i]);
        free(a);

        puts("Printing one by one:");
        for (i = 0; i < WORDS; i++) 
                        puts(*(w + i));

        // a new char array; 
        char *sentence = (char *) malloc(2* WORDS * L * sizeof(char));
        sentence[0] = 0;
        // putting words back in the same sentence in order
        // to highlight the existantial nature of our existance;
        for (i = 0; i < WORDS; i++) {
                strcat(sentence, w[i]);
                strcat(sentence, s);
        }

        for (u8 i = 0; i < WORDS; i++) 
                free(w[i]); 
        free(w);
        puts("Printing together:");
        puts(sentence);
        free(sentence); 
        return 0;
}
