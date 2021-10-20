#include <stdbool.h>

bool is_uruu(int year) {
  if (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) {
    return true;
  } else {
    return false;
  }
}

main(i) {
  for (i = 1990; i < 2030; i++) {
    if (is_uruu(i)) {
      printf("%d is leap year\n", i);
    } else {
      printf("%d is not leap year\n", i);
    }
  }
}
