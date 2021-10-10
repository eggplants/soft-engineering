#include <stdio.h>
int main() {
  char firstname[20];
  char lastname[20];
  int id;
  puts("What's your name?");
  printf("first> ");
  scanf("%s", firstname);
  printf("last> ");
  scanf("%s", lastname);
  puts("What's your student ID?");
  printf("ID> ");
  scanf("%d", &id);
  printf("Welcome, %s! <studentID: %d>\n", firstname, id);
}
