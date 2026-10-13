#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
    int ch;
    int line_len = 0;
    while ((ch = getchar()) != EOF) {

        printf("%02X ", ch);
        line_len += 3;


        if (line_len + 3 >= 20 || ch == '\n') {
            printf("\n");
            line_len = 0;
        }

    }
    return 0;
}
