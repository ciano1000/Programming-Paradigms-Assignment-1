#include <stdio.h>
#include "genericLinkedList.h"

int main(int arg, char* argc[]) {
	listElement* list = createEl("Element 1", 30, printString);
	double value = 20.0;
	listElement* second = insertAfter(list, &value, sizeof(double), printDouble);
	insertAfter(second, "E", sizeof(char), printChar);

	printf("Created List\n");
	traverse(list);
	printf("\n");

	printf("Length Is:%d \n", length(list));

	push(&list, "New 1st element", 30, printString);
	printf("Pushed:");
	list->print(list->data);
	listElement* popped = pop(&list);
	printf("Popped:");
	popped->print(popped->data);

	enqueue(&list, "Enqueued item", 30, printString);
	printf("Enqueued:");
	list->print(list->data);
	listElement* dequeued = dequeue(list);
	printf("Dequeued Item:");
	dequeued->print(dequeued->data);
	return 0;
}
