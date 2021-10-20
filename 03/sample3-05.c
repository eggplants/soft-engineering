int main() {
  int month;
  printf("input month(1-12):");
  scanf("%d", &month);
  if (month <= 2) {
    printf("winter!");
  } else if (month <= 5) {
    printf("spring!");
  } else if (month <= 8) {
    printf("summer!");
  } else if (month <= 11) {
    printf("autumn!");
  } else if (month <= 12) {
    printf("winter!");
  } else {
    printf("something wrong!");
    return 1;
  }
  return 0;
}
