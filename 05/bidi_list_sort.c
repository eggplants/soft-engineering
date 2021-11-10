#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
  struct listnode *next;
  struct listnode *prev;
  int data;
} ListNode;

ListNode listnodes[10];

int data[] = {0, 2, 7, 4, 8, 9, 3, 1, 6, 5};

void show_list(ListNode **node) {
  ListNode *n = &node[0];
  while (n != NULL) {
    // printf("%d:%p:%p:%p\n", n->data, n->prev, n, n->next);
    printf("%d, ", n->data);
    n = n->next;
  }
  puts("x");
}

void swap(ListNode *a, ListNode *b) {
  if (a == b) return;
  if (b->next == a) {
    ListNode tmp = *a;
    *a = *b;
    *b = tmp;
  }
  ListNode *w = a->prev;
  ListNode *x = a->next;
  ListNode *y = b->prev;
  ListNode *z = b->next;
  if ((a->next == b && b->prev == a) || (a->prev == b && b->next == a)) {
    a->prev = x;
    a->next = z;
    b->prev = w;
    b->next = y;
  } else {
    a->prev = y;
    a->next = z;
    b->prev = w;
    b->next = x;
  }
  if (a->prev != NULL) {
    a->prev->next = a;
  }
  if (a->next != NULL) {
    a->next->prev = a;
  }
  if (b->prev != NULL) {
    b->prev->next = b;
  }
  if (b->next != NULL) {
    b->next->prev = b;
  }
}

void sort(ListNode *node, int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if ((&node[i])->data > (&node[j])->data) {
        swap(&node[i], &node[j]);
      }
    }
  }
}

int main() {
  int n = sizeof(listnodes) / sizeof(ListNode);
  for (int i = 0; i < n; i++) {
    listnodes[i].data = data[i];
    if (i == 0) {
      listnodes[i].prev = NULL;
    } else {
      listnodes[i].prev = &listnodes[i - 1];
      listnodes[i - 1].next = &listnodes[i];
    }
    listnodes[i].next = NULL;
  }
  puts("prev:");
  show_list(&listnodes);
  sort(&listnodes, n);
  puts("next:");
  show_list(&listnodes);
}
