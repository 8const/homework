#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
typedef uint8_t u8;

/* allocates arrays */
void init(u8 **a, u8 n, u8 M)
{
        for (u8 i = 0; i < M; i++) 
                a[i] = malloc(n * M * sizeof(u8 *));
}

/* inputs integers into arrays */
void input(u8 **a, u8 n, u8 M)
{
        puts("Inputting matrix elements:");
        for (u8 i = 0; i < M; i++) {
                for (int8_t j = 0; j < n; j++) {
                        printf("\ta[%d][%d] = ", i, j);
                        scanf("%hhd", a[i] + j);
                } 
       }
} 
/* prints integers from in arrays in a rather fancy manner */
void output(u8 **a, u8 n, u8 M)
{
        for (u8 i = 0; i < M; i++) {
                puts("\n");
                for (int8_t j = 0; j < n; j++) {
                        printf("%d  ", *(a[i] + j));
                }
        }
        puts("\n");
}

/* frees arrays */
void fade(u8 **a, u8 n, u8 M) 
{
        for (u8 i = 0; i < M; i++) 
                free(a[i]);
}

int main(u8 argc, char *argv[])
{
        if (argc < 3) {
                puts("ERROR: programm expects 2 arguments;\n"
                       "run it as ./prog m n [ENTER]\n"
                       "where m and n are natural numbers less than 256;\n");
                return 0;
        } else {
                const u8 M = atoi(argv[1]);
                const u8 N = atoi(argv[2]);
                u8 **a = malloc(M * sizeof(u8 *));

                init(a, N, M);
                input(a, N, M);
                output(a, N, M);
                fade(a, N, M);
                free(a);
                return 0;
        }
}

