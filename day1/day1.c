#include <stdio.h>
#include <stdlib.h>

// *
int main(void) {
  FILE *fp = fopen("./input", "r");
  long calories_sum_max = 0, calories_sum = 0, calories = 0;
  char *line, *end;
  size_t n;
  while (getline(&line, &n, fp) >= 0) {
    line[n - 1] = '\0';
    calories = strtol(line, &end, 10);
    if (line != end) {
      calories_sum += calories;
    } else {
      if (calories_sum > calories_sum_max) {
        calories_sum_max = calories_sum;
      }
      calories_sum = 0;
    }
  }
  fclose(fp);
  printf("%ld\n", calories_sum_max);
  return 0;
}
