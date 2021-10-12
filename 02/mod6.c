main() {
  int id;
  printf("Input your ID number: ");
  scanf("%d", &id);
  id %= 6;
  printf("mod 6: %d\n", id);
}
