#include <stdio.h>

void _swap(int *arr, int a, int b) {
  int tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int _part(int *arr, int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      _swap(arr, ++i, j);
    }
  }
  _swap(arr, i + 1, high);
  return i + 1;
}

void _sort(int *arr, int low, int high) {
  if (low < high) {
    int pi = _part(arr, low, high);
    _sort(arr, low, pi - 1);
    _sort(arr, pi + 1, high);
  }
}

void sort(int *arr) {
  int n = sizeof(arr);
  _sort(arr, 0, n);
}

void print_int_array(int *arr) {
  int n = sizeof(arr);
  for (int i = 0; n >= i;) printf("%d%s", arr[i++], n > i ? ", " : "\n");
}

void main() {
  int arr[] = {2, 9, 4, 1, 100, 2, 4, 9, 5};
  print_int_array(arr);
  sort(arr);
  print_int_array(arr);
}
