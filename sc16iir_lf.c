#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int16_t i;
    int16_t q;
} complex_s16_t;

typedef struct {
    int32_t i;
    int32_t q;
} complex_s32_t;

#define NCoef 4
int main(int argc, char *argv[]) {
    double calc;

    complex_s16_t input[NCoef+1];
    complex_s32_t output[NCoef+1];

    const int16_t ACoef[NCoef+1] = { 3565, 14263, 21394, 14263, 3565 };
    const int16_t BCoef[NCoef+1] = { 8192, -26055, 31630, -17302, 3590 };

    while(!feof(stdin)) {
        for(int n=NCoef; n>0; n--) {
            input[n]=input[n-1];
            output[n]=output[n-1];
        }

        fread(&input[0], 4, 1, stdin);

        output[0].i = input[0].i * ACoef[0];
        output[0].q = input[0].q * ACoef[0];
        for(int n=1; n <= NCoef; n++) {
            output[0].i += ACoef[n] * input[n].i - BCoef[n] * output[n].i;
            output[0].q += ACoef[n] * input[n].q - BCoef[n] * output[n].q;
        }
        output[0].i >>= 13;
        output[0].q >>= 13;

        complex_s16_t res;
        res.i = output[0].i >> 8;
        res.q = output[0].q >> 8;

        fwrite(&res, 4, 1, stdout);
    }
}

