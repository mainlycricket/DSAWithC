#include <stdio.h>
#include <stdlib.h>
#define NODES 10

const int size = NODES * 2 + 1;
char tree[NODES * 2 + 1];

void setRoot(char);
int insertLeft(int, char);
int insertRight(int, char);

void preOrder(int);
void inOrder(int);
void postOrder(int);

int main() {

  setRoot('M');
  int x_index = insertLeft(0, 'X');
  int y_index = insertRight(0, 'Y');

  int a_index = insertLeft(x_index, 'A');
  int b_index = insertRight(x_index, 'B');

  int c_index = insertLeft(y_index, 'C');
  int d_index = insertRight(y_index, 'D');

  printf("\nPre-order: ");
  preOrder(0);

  printf("\nIn-order: ");
  inOrder(0);

  printf("\nPost-order: ");
  postOrder(0);

  return 0;
}

void setRoot(char data) {
  if (tree[0] != '\0') {
    printf("\nRoot node already exists");
    exit(1);
  }

  tree[0] = data;
}

int insertLeft(int parent, char data) {
  if (parent >= size || tree[parent] == '\0') {
    printf("\nParent not found");
    exit(1);
  }
  int left_index = parent * 2 + 1;

  if (left_index >= size || tree[left_index] != '\0') {
    printf("\nCant't insert left child!");
    exit(1);
  }

  tree[left_index] = data;
  return left_index;
}

int insertRight(int parent, char data) {
  if (parent >= size || tree[parent] == '\0') {
    printf("\nParent not found");
    exit(1);
  }
  int right_index = parent * 2 + 2;

  if (right_index >= size || tree[right_index] != '\0') {
    printf("\nCant't insert right child!");
    exit(1);
  }

  tree[right_index] = data;
  return right_index;
}

void preOrder(int root) {

  if (tree[root] == '\0') {
    printf("\nNo node found!");
    exit(1);
  }

  printf("%c", tree[root]);

  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && tree[left] != '\0') {
    preOrder(left);
  }

  if (right < size && tree[right] != '\0') {
    preOrder(right);
  }
}

void inOrder(int root) {

  if (tree[root] == '\0') {
    printf("\nNo node found!");
    exit(1);
  }

  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && tree[left] != '\0') {
    inOrder(left);
  }

  printf("%c", tree[root]);

  if (right < size && tree[right] != '\0') {
    inOrder(right);
  }
}

void postOrder(int root) {

  if (tree[root] == '\0') {
    printf("\nNo node found!");
    exit(1);
  }

  int left = 2 * root + 1;
  int right = 2 * root + 2;

  if (left < size && tree[left] != '\0') {
    postOrder(left);
  }

  if (right < size && tree[right] != '\0') {
    postOrder(right);
  }

  printf("%c", tree[root]);
}
