#include <stdio.h>

int main () {
    for (int i = 0; i < 4; i++)
        printf("Dec Oct Hex C\t");
    printf("\n");
    for (int i = 0; i < 32 ; ++i) {
        printf("%3d %3o %3X - |", i, i, i);
        printf("%3d %3o %3X %c |", 32 + i,32 + i,32 + i,32 + i);
        printf("%3d %3o %3X %c |", 64 + i,64 +  i,64 + i,64 + i);
        printf("%3d %3o %3X %c \n", 96 + i,96 +  i,96 +  i,96 + i);
    }
    return 0;
}