#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int16_t i;
    int16_t q;
} complex_s16_t;

int main(int argc, char *argv[]) {
    if(argc < 2) return -1;
    double fact = atof(argv[1]);
    double calc;
    complex_s16_t input;
    complex_s16_t output;
    while(!feof(stdin)) {
        fread(&input, 4, 1, stdin);
        calc = fact * input.i;
        output.i = calc;
        calc = fact * input.q;
        output.q = calc;
        fwrite(&output, 4, 1, stdout);
    }
}

