//multiplication tables example 1

#include<stdio.h>

#include<stdlib.h>

int main(int argc, char * argv[]) {
  int i = 0;
  int x = 0;
  int a = 0, b = 0;
  if (argc > 2) { //param > 2
    a = atoi(argv[1]);
    b = atoi(argv[2]);
    for (i = 1; i <= a; i++) { //cols
      for (x = 1; x <= b; x++) { //rows
        printf("%d\t", i * x);
      }
      printf("\n");
    }
  }
  return 0;
}
