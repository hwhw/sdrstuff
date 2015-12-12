#include <stdio.h>
#include <stdint.h>

int main() {
    while(!feof(stdin)) {
        int16_t i;
        if(fread(&i, 2, 1, stdin)) {
            float o = i;
            o = o / 32768;
            fwrite(&o, 4, 1, stdout);
        }
    }
}
