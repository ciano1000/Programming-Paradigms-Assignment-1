#ifndef CT331_ASSIGNMENT_LINKED_LIST
#define CT331_ASSIGNMENT_LINKED_LIST

typedef struct listElementStruct listElement;
typedef void (*Print)(void* data);

typedef struct listElementStruct {
	void* data;
	size_t size;
	struct listElementStruct* next;
	Print print;
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size, Print print);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size, Print print);

//Delete the element after the given el
void deleteAfter(listElement* after);

int length(listElement* list);

void push(listElement** list, void* data, size_t size, Print print);

listElement* pop(listElement** list);

void enqueue(listElement** list, void* data, size_t size, Print print);

listElement* dequeue(listElement* list);

void printChar(void* data);
void printString(void* data);
void printInt(void* data);
void printDouble(void* data);

#endif
