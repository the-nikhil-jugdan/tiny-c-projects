#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

const int BUFFER_SIZE = 10000;


const char* nato_phrases[] = {
    "Alfa", "Bravo", "Charlie", "Delta", "Echo", "Foxtrot", "Golf", "Hotel", 
    "India", "Juliett", "Kilo", "Lima", "Mike", "November", "Oscar", "Papa", 
    "Quebec", "Romeo", "Sierra", "Tango", "Uniform", "Victor", "Whiskey", 
    "Xray", "Yankee", "Zulu"
};


void make_natoed(char * input, char *output) {
    char ch;
    int input_seek = 0;
    int output_seek = 0;
    while(input[input_seek]) {
        ch = toupper(input[input_seek]);
        if (isalpha(ch)){
            sprintf(output + output_seek, "%s ", nato_phrases[ch-'A']);
            output_seek += strlen(nato_phrases[ch-'A']) + 1;
        }
        input_seek++;
    }
}

bool is_nato_term(char* term) {
    char* nato_term;
    int curr;
    for (int i = 0; i < 26; i++) {
            nato_term = nato_phrases[i];
            curr = 0;
            while (*(nato_term + curr) != '\0' || *(term + curr) != '\0') {
                if ((*(nato_term + curr) | 0x20) != (*(term + curr) | 0x20))
                    break;
                curr++;
            }
            if (*(nato_term + curr) == '\0' && *(term + curr) == '\0')
                return true;
        }
    return false;
}

void make_english(FILE* fp, char *output) {
    char buffer[BUFFER_SIZE];

    int output_seek = 0;
    int nex_char;

    while (fscanf(fp, "%s", buffer) == 1) {
        if (is_nato_term(buffer)) {
            printf("%c", buffer[0]);
            next_char = fgetc(fp);
            if (next_char == '\n') {
                printf("\n");
            } else {
                ungetc(next_char, fp);
            }
        }
    }
    printf("\n");
}

void natofy(char* target_str, FILE* fp) {
    char buffer[BUFFER_SIZE];

    while(fgets(buffer, BUFFER_SIZE, fp)) {
        make_natoed(buffer, target_str);
        printf("%s\n",target_str);
    }
}

int main(int argc, char * argv[]) {
    bool file_input = false;
    bool decode_mode = false;
    int file_arg = -1;
    FILE* fp;
    char natoed_output[BUFFER_SIZE];

    if (argc >= 2 && strcmp(argv[1], "-d") == 0)
        decode_mode = true;

    if (decode_mode && argc > 2) {
        file_arg = 2;
    }
    if (!decode_mode && argc >= 2) {
        file_arg = 1;
    }

    if (file_arg != -1) {
        if (fp = fopen(argv[file_arg], "r"))
            file_input = true;           
    } else {
        fp = stdin;
        file_input = false;
    }
    if (decode_mode) {
        make_english(fp, natoed_output);
    }else {
        natofy(natoed_output, fp);
    }
    
    if (file_input)
        fclose(fp);
    return 0;
}