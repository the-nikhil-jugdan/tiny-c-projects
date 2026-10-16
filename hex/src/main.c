#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_hex(int val, char *target) {
    int res = val / 16;
    target[0] = res < 10 ? '0' + res : 'A' + (res % 10);
    res = val % 16;
    target[1] = res < 10 ? '0' + res : 'A' + (res % 10);
}

int normalize(int val) {
    if ('0' <= val && val <= '9') 
        return val - '0';
    return val - 'A' + 10;
}

int de_hex(int val1, int val2) {
    return normalize(val1) * 16 + normalize(val2);
}

int main(int argc, char * argv[]) {
    int decode = 0;
    if (argc >= 2 && strcmp(argv[1], "-d") == 0)
        decode = 1;
    char c, c2;
    char hex_rep[3];
    hex_rep[2] = '\0';
    while((c=getchar()) != EOF) {
        if (decode) {
            c2 = getchar();
            if (c2 == EOF) return -1;
            printf("%c", de_hex(c, c2));
        } else {
            to_hex(c, hex_rep);
            printf("%s", hex_rep);
        }
    }
    return 0;
}