#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int16_t i;
    int16_t q;
} complex_s16_t;

int main(int argc, char *argv[]) {
    if(argc < 2) return -1;
    int nth = atoi(argv[1]);
    int c = 0;
    complex_s16_t input;
    while(!feof(stdin)) {
        fread(&input, 4, 1, stdin);
        if(0 == (c % nth)) {
            fwrite(&input, 4, 1, stdout);
            c = 0;
        }
        c++;
    }
}

