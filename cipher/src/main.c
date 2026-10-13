#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char rotate(char inp, int shift) {
    char A = 'a';
    if (isalpha(inp)) {
        if ('A' <= inp && inp <= 'Z')
            A = 'A';    
        return A + (inp + shift - A) % 26;
    }
    return inp;
}


int main(int argc, char* argv []) {
    if (argc < 2) {
        printf("Please specify the rotation chararcter \n");
        exit(-1);
    }
    if (strlen(argv[1]) < 2) {
        printf("Please specify the start and end of the shift \n");
        exit(-1);
    }
    char start = argv[1][0];
    char end = argv[1][1];
    char inp;
    while ((inp = getchar()) != EOF) {
        putchar(rotate(inp, end - start));
    }
    return 0;
}
