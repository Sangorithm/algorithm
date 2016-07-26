#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct DNode {
	short value;
	DNode * prev;
	DNode * tail;
} deque;
typedef struct info {
	short size;
	DNode * head;
	DNode * tail;
} info;
deque * node;
info * ifo;
void init();
void init() {
	node = (deque *)malloc(sizeof(DNode));
	node->value = -1;
	node->prev = node; // 자기자신을 가르킴
	node->tail = node; // 자기자신을 가르킴

	ifo = (info *)malloc(sizeof(info));
	ifo->size = 0;
	ifo->head = node;
	ifo->tail = node;

}
void push_front();
void push_back();
short pop_front();
short pop_back();
short valueInput();
short size();
short empty();
short front();
short back();
short main() {
	char input[20],
		menu[][20] = { "push_front","push_back","pop_front","pop_back","size","empty","front","back" };
	short arraySize = sizeof(menu) / sizeof(menu[0]),
		i = 0,
		count=0;
	init();
	scanf("%d", &count);
	while (count) {
		fflush(stdin);
		scanf(" %s", input);
		for (i = 0; i < arraySize; i++) {
			if (!strcmp(input, menu[i]))
				break;
		}
		switch (i) {
		case 0: push_front(); break;
		case 1: push_back(); break;
		case 2: prshortf("%d\n",pop_front()); break;
		case 3: prshortf("%d\n",pop_back()); break;
		case 4: prshortf("%d\n",size()); break;
		case 5:prshortf("%d\n",empty()); break;
		case 6:prshortf("%d\n",front()); break;
		case 7:prshortf("%d\n",back()); break;
		default: break;
		}
		count--;
	}
	return 0;
}
short valueInput() {
	short temp;
	scanf("%d", &temp);
	fflush(stdin);
	return temp;
	
}
void push_front() {
	short no = valueInput();
	deque * temp = (deque *)malloc(sizeof(deque));
	temp->value=no;
	temp->tail = ifo->head;
	temp->prev = temp;
	ifo->head = temp;
	ifo->size += 1;
}
void push_back() {
	short no = valueInput();
	deque * temp = (deque *)malloc(sizeof(deque));
	temp->value = no;
	node->tail = temp;
	ifo->tail = temp;
	ifo->size += 1;
}
short pop_front() {
	deque * temp = ifo->head;
	if (ifo->size == 0)
		return -1;
	short returnValue = temp->value;
	ifo->head->tail->prev = ifo->head->tail;
	free(temp);
	ifo->size -= 1;
	return returnValue;

}
short pop_back() {
	deque * temp = ifo->tail;
	if (ifo->size == 0)
		return -1;
	short returnValue = temp->value;
	ifo->tail->tail = ifo->tail->prev;
	free(temp);
	ifo->size -= 1;
	return returnValue;
}
short size() {
	return ifo->size;
}
short empty() {
	if (ifo->size == 0)
		return 1;
	return 0;
}
short front() {
	return ifo->head->value;
}
short back() {
	return ifo->tail->value;
}