#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value);

int main (){
//  double *(*ptr)(char *c, float d, int e );
//  ptr = hace;
//  printf("%f\n",*hace(" ",1.2,2));
//  printf("%f\n",*ptr(" ",1.2,2));
  struct Node nodo;
  nodo.data = 5;
  nodo.next = createNode(9);

  nodo.next->next = createNode(98);

  printf("%d\n",nodo.data);

  printf("%d\n",nodo.next->data);

//  printf("%d\n",sizeof(int));
//  printf("%d\n",sizeof(struct Node*));
//  printf("%d\n",sizeof(nodo));
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}
