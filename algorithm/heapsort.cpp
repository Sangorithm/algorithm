#include<iostream>
short ary[100001];
void swap(short a, short b) {
	short temp = ary[a];
	ary[a] = ary[b];
	ary[b] = temp;
}
void heapSort(short index, short max) {
	if (index >= max)
		return;
	if (ary[index] > ary[(2 * index) + 1] && (2 * index) + 1 <= max)
		swap(index, (2 * index) + 1);
	else if (ary[index] > ary[(2 * index) + 2] && (2 * index) + 2 <= max)
		swap(index, (2 * index) + 2);
}
void heapSort(short index) {
	if (index == 0)
		return;
	if (ary[index] < ary[(index - 1) / 2]) {
		swap(index, (index - 1) / 2);
		heapSort((index - 1) / 2);
	}
}
short main() {
	short i = 0,
		j=0,
		index=0,
		temp=0;
	scanf(" %d", &i);
	while (i--) {
		scanf(" %d", &temp);
		if (!temp)
			if (!index)
				prshortf("0\n");
			else {
				prshortf("%d\n", ary[0]);
				ary[0] = ary[--index];
				heapSort(0, index);
			}
		else {
			ary[index] = temp;
			heapSort(index++);
		}
	}
	return 0;
}