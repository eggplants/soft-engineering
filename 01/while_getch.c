#include <termios.h>
#include <unistd.h>
// https://stackoverflow.com/a/23035044/12021810
int getch() {
  struct termios oldattr, newattr;
  int ch;
  tcgetattr(STDIN_FILENO, &oldattr);
  newattr = oldattr;
  newattr.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
  ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
  return ch;
}
main() {
  int c;
  while (c != 's') {
    puts("Press `s' to stop:");
    c = getch();
    printf("%c\n", c);
  }
}
