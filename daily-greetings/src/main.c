#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char **quotes;
int quote_num = 0;


char *phase[8] = {
  "waxing crescent", "at first quarter", "waxing gibbous", "full", "waning gibbous", "at last quarter", "waning crescent", "new" 
};

int moon_phase(int year, int month, int day) {
  int d,g,e; 
  d = day; 
  if(month == 2) 
    d += 31; 
  else if(month > 2) 
    d += 59+(month-3)*30.6+0.5; 
  g = (year-1900)%19; 
  e = (11*g + 29) % 30; 
  if(e == 25 || e == 24) 
    ++e; 
  return ((((e + d)*6+5)%177)/22 & 7); 
}

int read_quotes_file() {
  quotes =  (char **) malloc(sizeof(char *) * 100);
  const char filename[] = "/workspaces/tiny-c-projects/daily-greetings/src/fortune";
  FILE *fp;
  char *r;
  char buffer[1000];
  char *read_str = NULL;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Unable to open file %s\n", filename);
    return -1;
  }
  while (!feof(fp)) {
    r = fgets(buffer, 1000, fp);
    if (r == NULL) break;
    int buffer_len = strlen(buffer);
    buffer[buffer_len - 1] = '\0';
    read_str = (char *) malloc(sizeof(char *) * (buffer_len - 1));
    strcpy(read_str, buffer);
    quotes[quote_num++] = read_str;
  }
  fclose(fp);
  return 0;
}

int main(int argc, char* argv[]) {
  time_t now;
  struct tm *clock;
  char time_string[64]; 

  time(&now);
  clock = localtime(&now);

  if (argc < 2)
    printf("Hello, you handsome beast\n");
  else 
    printf("Hello, %s\n", argv[1]);
  strftime(time_string,64,"Today is %A, %B %d, %Y%nIt is %r%n",clock);  
  printf("%s", time_string);
  int moon_phase_index = moon_phase(clock -> tm_year + 1900, clock -> tm_mon, clock->tm_mday);
  printf("The moon is %s\n", phase[moon_phase_index]);
  if (read_quotes_file() == 0) {
    srand(time(NULL));
    int sel_quote = (rand() % quote_num + rand()) % quote_num;
    printf("%s\n", quotes[sel_quote]);
  }
  return 0;
}
