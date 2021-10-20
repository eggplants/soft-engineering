main() {
  char str1[] = "I am a student!";
  char str2[] = {'I', '',  'a', 'm', '',  'a', '',  's',
                 't', 'u', 'd', 'e', 'n', 't', '!', '¥0'};
  printf("%s\n", str1);
  printf("%s\n", str2);
}
