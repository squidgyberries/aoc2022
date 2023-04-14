#include <stdio.h>
#include <stdlib.h>

// 0 lose, 1 tie, 2 win
int outcome(char opp, char me) {
  int diff = 23 - (me - opp);
  diff = (diff + 3) % 3;
  diff = (diff == 0 || diff == 1) ? 1 - diff : diff;
  return diff;
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
    score1 += me - 'W'; // X 1, Y 2, Z 3
    score1 += outcome(opp, me) * 3;

    // second problem
    score2 += (me - 'X') * 3; // X 0, Y 3, Z 6
    score2 += choice(opp, me);
  }
  fclose(fp);
  printf("%d\n", score1);
  printf("%d\n", score2);
  return 0;
}
