#include <stdio.h>
#include <stdlib.h>

// 0 lose, 1 tie, 2 win
int outcome(char opp, char me) {
  switch (me) {
  case 'X':
    switch (opp) {
    case 'A':
      return 1;
    case 'B':
      return 0;
    case 'C':
      return 2;
    default:
      printf("invalid option\n");
      return 1000;
    }
    break;
  case 'Y':
    switch (opp) {
    case 'A':
      return 2;
    case 'B':
      return 1;
    case 'C':
      return 0;
    default:
      printf("invalid option\n");
      return 1000;
    }
    break;
  case 'Z':
    switch (opp) {
    case 'A':
      return 0;
    case 'B':
      return 2;
    case 'C':
      return 1;
    default:
      printf("invalid option\n");
      return 1000;
    }
    break;
  default:
    printf("invalid option\n");
    return 1000;
  }
}

// *
int main(void) {
  FILE *fp = fopen("input", "r");
  char *line;
  size_t n;
  int score = 0;
  while (getline(&line, &n, fp) >= 0) {
    char opp = line[0];
    char me = line[2];
    switch (me) {
    case 'X':
      score += 1;
      break;
    case 'Y':
      score += 2;
      break;
    case 'Z':
      score += 3;
      break;
    default:
      printf("invalid option\n");
      break;
    }
    score += outcome(opp, me) * 3;
  }
  fclose(fp);
  printf("%d\n", score);
  return 0;
}
