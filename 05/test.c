// https://stackoverflow.com/questions/20095529/swapping-nodes-in-double-linked-list/20095828

#include <stdio.h>
#include <stdlib.h>

typedef struct node_v {
  int id;
  struct node_v* prev;
  struct node_v* next;
} Node_v;

typedef Node_v* Node;

void print(Node node) {
  while (node->prev != NULL) node = node->prev;

  printf("   [%d]", node->id);

  while (node->next != NULL) {
    node = node->next;
    printf("-[%d]", node->id);
  }

  printf("\n");
}

void connect(Node first, Node second) {
  first->next = second;
  second->prev = first;
}

Node createNode(int id) {
  Node node = (Node)malloc(sizeof(Node_v));
  node->id = id;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

int areTheyNeighbours(Node A, Node B) {
  return (A->next == B && B->prev == A) || (A->prev == B && B->next == A);
}

void refreshOuterPointers(Node A) {
  if (A->prev != NULL) A->prev->next = A;

  if (A->next != NULL) A->next->prev = A;
}

void swap(Node A, Node B) {
  Node swapperVector[4];
  Node temp;

  if (A == B) return;

  if (B->next == A) {
    temp = A;
    A = B;
    B = temp;
  }

  swapperVector[0] = A->prev;
  swapperVector[1] = B->prev;
  swapperVector[2] = A->next;
  swapperVector[3] = B->next;

  if (areTheyNeighbours(A, B)) {
    A->prev = swapperVector[2];
    B->prev = swapperVector[0];
    A->next = swapperVector[3];
    B->next = swapperVector[1];
  } else {
    A->prev = swapperVector[1];
    B->prev = swapperVector[0];
    A->next = swapperVector[3];
    B->next = swapperVector[2];
  }

  refreshOuterPointers(A);
  refreshOuterPointers(B);
}

int main() {
  Node n1 = createNode(1);
  Node n2 = createNode(2);
  Node n3 = createNode(3);
  Node n4 = createNode(4);

  connect(n1, n2);
  connect(n2, n3);
  connect(n3, n4);
  print(n1);
  swap(n1, n4);
  print(n1);
  return 0;
}