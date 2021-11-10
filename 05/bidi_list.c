#include <stdio.h>

typedef struct listnode {
  struct listnode *next;
  struct listnode *prev;
  int data1;
  int data2;
} ListNode;

ListNode listnodes[200];

int data1[] = {38, 25, 90, 22, 52, 74, 96, 30, 96, 76, 51, 7,  70, 41, 28,
               45, 54, 40, 55, 90, 11, 82, 45, 37, 54, 47, 2,  37, 13, 47,
               4,  83, 44, 78, 73, 58, 37, 34, 89, 52, 56, 14, 32, 80, 38,
               26, 61, 3,  4,  77, 25, 24, 51, 60, 27, 84, 56, 72, 80, 98,
               95, 60, 1,  93, 54, 98, 90, 85, 99, 37, 4,  0,  12, 19, 17,
               34, 84, 31, 25, 50, 73, 18, 54, 76, 0,  20, 85, 70, 6,  81,
               2,  5,  51, 92, 5,  80, 53, 31, 70, 47};

void show_list(const ListNode *start) {
  ListNode node = *start;
  while (node.data1 != -1) {
    printf("%d\n", node.data1);
    node = *(node.next);
  }
}

int main() {
  ListNode first_p, end_p;
  first_p.data1 = -1;
  end_p.data1 = -1;

  // `p = -1' indicates null_p
  ListNode *last_node_addr = &first_p;

  for (int i = 0; i < 100; i++) {
    listnodes[i].prev = last_node_addr;
    listnodes[i].data1 = data1[i];
    listnodes[i].data2 = 0;
    (*last_node_addr).next = &listnodes[i];
    last_node_addr = &listnodes[i];
  }
  (*last_node_addr).next = &end_p;
  end_p.prev = last_node_addr;

  show_list(first_p.next);
}
