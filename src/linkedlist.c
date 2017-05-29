#include<stdio.h>
#include<LinkedListAPI.h>
#include<string.h>

Node *initializeNode(void *data){
	Node* node1;
	node1 = malloc(sizeof(Node));
	if (node1 == NULL){
		printf("No more memory availible\n");
		exit(0);
	}

	node1->data = data;
	node1->previous = NULL;
	node1->next = NULL;

return node1;
}

List *initializeList(void (*printFunction)(void *toBePrinted),void (*deleteFunction)(void *toBeDeleted),int (*compareFunction)(const void *first,const void *second)){
	List* list1; 
	printf("hello\n");
	list1 = malloc(sizeof(List));
	if(list1 == NULL){
		printf("no memory availible\n");
		exit(0);
	}
	list1->head = NULL;
	list1->tail = NULL;
	return list1;
}

void insertFront(List *list, void *toBeAdded){
	Node *newNode;
	newNode = initializeNode(toBeAdded);
	Node *temp;
	temp = list->head;
	temp->previous = newNode;
	newNode-> next = temp;
	list->head = newNode;
}

void insertBack(List *list, void *toBeAdded){
	Node *newNode;
	newNode = initializeNode(toBeAdded);
	Node *temp;
	temp = list->tail;
	temp->next = newNode;
	newNode-> previous = temp;
	list->tail = newNode;
}

void deleteList(List *list){
	Node *currentNode;
	Node *nextNode;
	Node *lastNode;
	currentNode = list->head;
	lastNode = list->tail;
	int i = 0;
	while(currentNode != lastNode){
		nextNode = currentNode->next;
		free(currentNode);
		currentNode = nextNode;
		i++;
		printf("node#: %d deleted \n", i);
	}
	free(lastNode);
	i++;
	printf("Final Node # %d deleted\n", i);
}

void insertSorted(List *list, void *toBeAdded){
	Node *addNode;
	Node *currentNode;
	int compare;
	compare = 0;
	currentNode = list->head;
	addNode = initializeNode(toBeAdded);
	while (currentNode->next != NULL){
		list->compare(currentNode->data, addNode->data);
		if(compare){
		//add after
			Node *tempNode;
			tempNode=currentNode->next;
			currentNode->next = addNode;
			addNode->next = tempNode;
			addNode->previous = currentNode;
			tempNode->previous = addNode;
			break;
		}
		currentNode = currentNode->next;
	}
}

int deleteDataFromList(List *list, void *toBeDeleted){
       	Node *currentNode;
	Node *previousNode;
	Node *deleteNode;
       	currentNode = list->head;
	if (list->head==NULL){
		return EXIT_FAILURE;

	}
	if(currentNode-> data != toBeDeleted){
		currentNode = currentNode->next;
	}
	else{
		deleteNode = currentNode;
		currentNode = currentNode->next;
		
		list->head = currentNode;
		currentNode->previous = NULL;
		free(deleteNode);
		
		return EXIT_SUCCESS;
	}
       	while (currentNode != NULL){
       		if(currentNode->data == toBeDeleted){
       			deleteNode=currentNode;
			previousNode = currentNode->previous;
			currentNode = currentNode->next;
			free(deleteNode);

       			currentNode->previous = previousNode;
			previousNode->next = currentNode;
       			return EXIT_SUCCESS;
       		}
       		currentNode = currentNode->next;
       	}
	return -1;
}

void *getFromFront(List *list){
	Node *firstNode;
	firstNode = list->head;
	return firstNode->data;
}

void *getFromBack(List *list){
	Node *lastNode;
	lastNode = list->tail;
	return lastNode->data;
}

void printForward(List *list){
	Node *currentNode;
	currentNode = list->head;
	while (currentNode != NULL){
		list->printData(currentNode->data);
		currentNode = currentNode->next;
	}
}

void printBackwards(List *list){
	Node *currentNode;
	currentNode = list->tail;
	while (currentNode != NULL){
		list->printData(currentNode->data);
		currentNode = currentNode->previous;
	}
}
