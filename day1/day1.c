#include <stdio.h>
#include <stdlib.h>

// **
int main(void) {
  FILE *fp = fopen("./input", "r");
  long calories_sum_1 = 0;
  long calories_sum_2 = 0;
  long calories_sum_3 = 0;
  long calories_sum = 0;
  long calories = 0;
  char *line, *end;
  size_t n;
  while (getline(&line, &n, fp) >= 0) {
    line[n - 1] = '\0';
    calories = strtol(line, &end, 10);
    if (line != end) {
      calories_sum += calories;
    } else {
      if (calories_sum > calories_sum_1) {
        calories_sum_3 = calories_sum_2;
        calories_sum_2 = calories_sum_1;
        calories_sum_1 = calories_sum;
      } else if (calories_sum > calories_sum_2) {
        calories_sum_3 = calories_sum_2;
        calories_sum_2 = calories_sum;
      } else if (calories_sum > calories_sum_3) {
        calories_sum_3 = calories_sum;
      }
      calories_sum = 0;
    }
  }
  fclose(fp);
  printf("%ld\n", calories_sum_1 + calories_sum_2 + calories_sum_3);
  return 0;
}
