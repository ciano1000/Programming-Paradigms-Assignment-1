#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"


//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size,Print print){
  listElement* e = malloc(sizeof(listElement));
  if(e == NULL){
    //malloc has had an error
    return NULL; //return NULL to indicate an error.
  }

  void* dataPointer = malloc(size);

  if(dataPointer == NULL){
    //malloc has had an error
    free(e); //release the previously allocated memory
    return NULL; //return NULL to indicate an error.
  }
  memcpy(dataPointer, data, size);
  e->data = dataPointer;
  e->size = size;
  e->next = NULL;
  e->print = print;
  return e;
}

//Prints out each element in the list
void traverse(listElement* start){
  listElement* current = start;
  while(current != NULL){
    current->print(current->data);
    current = current->next;
  }
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size,Print print){
  listElement* newEl = createEl(data, size,print);
  listElement* next = el->next;
  newEl->next = next;
  el->next = newEl;
  return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after){
  listElement* delete = after->next;
  listElement* newNext = delete->next;
  after->next = newNext;
  //need to free the memory because we used malloc
  free(delete->data);
  free(delete);
}

int length(listElement* list){
  listElement* current = list;
  int length = 0;

  while(current != NULL){
    ++length;
    current = current->next;
  }
  return length;
}

void push(listElement** list,void* data,size_t size,Print print){
  listElement* temp = createEl(data,size,print);
  temp->next = *list;
  *list = temp;
}

listElement* pop(listElement** list){
  listElement* returnElement = *list;
  *list = returnElement->next;
  return returnElement;
}

void enqueue(listElement** list, void* data, size_t size,Print print){
  push(list,data,size,print);
}

listElement* dequeue(listElement* list){
  if(length(list) == 0){
    return 0;
  }
  listElement* current = list;
  while (current->next != NULL)
  {
    //obtain reference to previous element
    listElement* previous = current;
    //set current to the next element
    current = current->next;

    //set the next pointer of the element before the element we are removing to NULL
    if(current->next == NULL){
     previous->next = NULL; 
    }
  }
  
  return current;
}

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

void printString(void* data){
    printf("%s\n",(char*)data);
}

void printInt(void* data){
    printf("%d\n",*(int*)data);
}

void printDouble(void* data){
    printf("%f\n",*(double*)data);
}


