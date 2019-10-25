#include <stdio.h>
#include "linkedList.h"
#include "tests.h"

int main(int arg, char* argc[]){
  listElement* list = createEl("Element 1",30);
  listElement* second = insertAfter(list,"Element 2",30);
  insertAfter(second,"Element 3",30);

  printf("Created List\n");
  traverse(list);
  printf("\n");

  printf("Length Is:%d \n",length(list));

  push(&list,"New 1st element",30);
  printf("Pushed:%s\n",list->data);
  listElement* popped = pop(&list);
  printf("Popped: %s \n",popped->data);

  enqueue(&list,"Enqueued item",30);
  printf("Enqueued:%s\n",list->data);
  listElement* dequeued = dequeue(list);
  printf("Dequeued Item:%s \n",dequeued->data);

  return 0;
}
