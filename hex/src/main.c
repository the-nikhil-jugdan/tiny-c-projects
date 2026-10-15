#include <stdio.h>
#include <stdlib.h>

void to_hex(int val, char *target) {
    int res = val / 16;
    target[0] = res < 10 ? '0' + res : 'A' + (res % 10);
    res = val % 16;
    target[1] = res < 10 ? '0' + res : 'A' + (res % 10);
}

int main() {
    char c;
    char hex_rep[3];
    hex_rep[2] = '\0';
    while((c=getchar()) != EOF) {
        to_hex(c, hex_rep);
        printf("%s", hex_rep);
    }
    return 0;
}