#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int8_t i;
    int8_t q;
} complex_t;
typedef complex_t complex_s8_t;
typedef struct {
    int16_t i;
    int16_t q;
} complex_s16_t;

int main() {
    complex_t input;
    complex_s16_t output;
    while(!feof(stdin)) {
        fread(&input, 2, 1, stdin);
        output.i = input.i;
        output.q = input.q;
        fwrite(&output, 4, 1, stdout);
    }
}

