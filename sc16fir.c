#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int16_t i;
    int16_t q;
} complex_s16_t;

int main(int argc, char *argv[]) {
    double calc;
    complex_s16_t input[4];
    complex_s16_t output;
    while(!feof(stdin)) {
        input[3] = input[2];
        input[2] = input[1];
        input[1] = input[0];
        fread(&input[0], 4, 1, stdin);
        output.i = input[0].i + input[1].i*3 + input[2].i*3 + input[3].i;
        output.q = input[0].q + input[1].q*3 + input[2].q*3 + input[3].q;
        fwrite(&output, 4, 1, stdout);
    }
}

