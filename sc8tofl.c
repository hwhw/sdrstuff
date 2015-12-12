#include <stdio.h>
#include <stdint.h>

int main() {
    while(!feof(stdin)) {
        int8_t i;
        if(fread(&i, 1, 1, stdin)) {
            float o = i;
            o = o / 128;
            fwrite(&o, 4, 1, stdout);
        }
    }
}
