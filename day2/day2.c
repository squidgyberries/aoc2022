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

// 1 rock, 2 paper, 3 scissors
int choice(char opp, char me) {
  switch (opp) {
  case 'A':
    switch (me) {
    case 'X':
      return 3;
      break;
    case 'Y':
      return 1;
      break;
    case 'Z':
      return 2;
      break;
    default:
      printf("invalid option\n");
      return 1000;
    }
    break;
  case 'B':
    switch (me) {
    case 'X':
      return 1;
      break;
    case 'Y':
      return 2;
      break;
    case 'Z':
      return 3;
      break;
    default:
      printf("invalid option\n");
      return 1000;
    }
    break;
  case 'C':
    switch (me) {
    case 'X':
      return 2;
      break;
    case 'Y':
      return 3;
      break;
    case 'Z':
      return 1;
      break;
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

// **
int main(void) {
  FILE *fp = fopen("input", "r");
  char *line;
  size_t n;
  int score1 = 0;
  int score2 = 0;
  while (getline(&line, &n, fp) >= 0) {
    char opp = line[0];
    char me = line[2];

    // first problem
    switch (me) {
    case 'X':
      score1 += 1;
      break;
    case 'Y':
      score1 += 2;
      break;
    case 'Z':
      score1 += 3;
      break;
    default:
      printf("invalid option\n");
      break;
    }
    score1 += outcome(opp, me) * 3;

    // second problem
    switch (me) {
    case 'X':
      score2 += 0;
      break;
    case 'Y':
      score2 += 3;
      break;
    case 'Z':
      score2 += 6;
      break;
    default:
      printf("invalid option\n");
      break;
    }
    score2 += choice(opp, me);
  }
  fclose(fp);
  printf("%d\n", score1);
  printf("%d\n", score2);
  return 0;
}
