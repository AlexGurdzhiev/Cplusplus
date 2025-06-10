#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int compare(const void *a, const void *b) {
  const char *str_a = *(const char**)a;
  const char *str_b = *(const char**)b;
  return strcmp(str_a, str_b);
}

int main() {
  int n;
  puts("Введите количество студентов:");
  scanf("%d", &n);
  getchar();

  char **data = calloc(sizeof(char *), n);
  for (int i = 0; i < n; ++i) {
    char buff[100];
    fgets(buff, 100, stdin);
    buff[strlen(buff) - 1] = '\0';
    data[i] = calloc(sizeof(char), strlen(buff));
    strcpy(data[i], buff);
  }
  
  qsort(data, n, sizeof(char **), compare);
  
  for (int i = 0; i < n; ++i) {
    puts(data[i]);
  }
}
