#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  FILE *fp;
  int c;
  if(argc!=2){
    printf("Usage: %s <file>\n", argv[0]);
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) != NULL) {
    while ((c = fgetc(fp)) != EOF) {
      putchar(c);
    }
    fclose(fp);
  } else {
    printf("File open error!\n");
    return 2;
  }  return 0;
}
