#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int8_t i;
    int8_t q;
} complex_t;
typedef complex_t complex_s8_t;

static void my_translate_fs_over_4(complex_s8_t* const src_and_dst, const size_t sample_count) {
    // multiplies samples by 1, i, -1, -i
    int8_t *v = (int8_t*) src_and_dst;
    for(int n=sample_count; n>0; n-=4) {
        v+=2;

        int8_t q = -(*v);
        *v = v[1];
        v++;
        *v = q;
        v++;

        *v = - *v;
        v++;
        *v = - *v;
        v++;

        q = *v;
        *v = -v[1];
        v++;
        *v = q;
        v++;
    }
}

int main() {
    complex_t buf[4];
    while(!feof(stdin)) {
        fread(buf, 8, 1, stdin);
        my_translate_fs_over_4(buf, 4);
        fwrite(buf, 8, 1, stdout);
    }
}

