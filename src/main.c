#include<stdio.h>
#include<LinkedListAPI.h>

int main(void){
	int i = 8;
	void *j;
	j = &i;
	List* list1;
	list1 = initializeList(j,j,j);
	Node *node1;
	Node *node2;
	Node *node3;
	node1 = initializeNode(j);
	node2 = initializeNode(j);
	node3 = initializeNode(j);
	list1->head = node1;
	list1->tail = node3;
	node1->next = node2;
	node2->previous = node1;
	node2->next = node3;
	node3->previous = node2;
	//test that is worked
	if(list1->head == node1&& list1->tail == node3){
		printf("initial list is good\n");

	}
	
	//test for addToFrontFunction
	insertFront(list1, j);
	if(list1->head != node1){
		printf("add to front is a success\n");

	}

	insertBack(list1, j);
	if(list1->tail != node3){
		printf("add to back is a success\n");
	}

	deleteList(list1);

return 0;
}


