#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

extern char FRAME_01[][72];
extern char FRAME_02[][72];

int COLOR[] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
int COLOR_NUM = sizeof(COLOR) / sizeof(int);

int PREV_COLOR = 0;

void print_help(char prog[]) {
  printf(
      "\
usage: %s [-f] [-t MS] [-h] [-v]\n\
\n\
*pop* *pop* *pop*\n\
\n\
optional arguments:\n\
  -f, --flip            flip cat\n\
  -t, --time <ms(>=0)>  interval of frames\n\
                        defaults to 200(ms)\n\
  -h, --help            display this help and exit\n\
  -v, --version         output version information and exit\n",
      prog);
  exit(0);
}

void print_version(void) {
  puts("popcat 0.0.1");
  exit(0);
}

void msleep(int sec) { usleep(sec * 1000); }

void clear_screen() { printf("\033[2J\033[3J\033[H"); }

int sample_color(void) {
  srand(time(NULL));
  return COLOR[rand() % COLOR_NUM];
}

void print_char_array(char char_arr[][72], int reverse) {
  int color = sample_color();
  if (reverse == 0) {
    for (int c = 0; c < 35; c++) {
      fflush(stdout);
      printf("\x1b[%dm%s\n", color, char_arr[c]);
    }
  } else {
    for (int c = 34; c >= 0; c--) {
      fflush(stdout);
      printf("\x1b[%dm%s\n", color, char_arr[c]);
    }
  }
}

int is_natural(char *s) {
  if (s[0] == '\0' || (s[0] == '0' && s[1] != '\0')) return 0;
  int i;
  while (s[i] != '\0')
    if ('0' > s[i] || '9' < s[i++]) return 0;
  return 1;
}

void print_frame(int sec, int reverse) {
  fflush(stdout);
  print_char_array(FRAME_01, reverse);
  msleep(sec);
  clear_screen();
  fflush(stdout);
  print_char_array(FRAME_02, reverse);
  msleep(sec);
  clear_screen();
}

int main(int argc, char *argv[]) {
  struct option longopts[] = {
      {"flip", no_argument, NULL, 'f'},
      {"help", no_argument, NULL, 'h'},
      {"version", no_argument, NULL, 'v'},
      {"time", required_argument, NULL, 't'},
      {0, 0, 0, 0},
  };
  int opt;
  int longindex;
  int flip = 0;
  int sleep_ms = 200;
  while ((opt = getopt_long(argc, argv, "fhvt:", longopts, &longindex)) != -1) {
    switch (opt) {
      case 'v':
        print_version();
        break;
      case 'h':
        print_help(argv[0]);
        break;
      case 'f':
        flip = 1;
        break;
      case 't':
        if (is_natural(optarg)) {
          sleep_ms = atoi(optarg);
        } else {
          fprintf(stderr, "%s: '%s' is not natural int. (0>=)\n", argv[0],
                  optarg);
          return 1;
        }
        break;
      case '?':
        return 1;
      default:
        fprintf(stderr, "%s: invalid option -- '%c'\n", argv[0], opt);
        return 1;
    }
  }
  clear_screen();
  while (1) {
    print_frame(sleep_ms, flip);
  }
}
