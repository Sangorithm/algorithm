#include<cstdio>
#define swap(a,b) int temp=a;a=b;b=temp;
int ary[200001];
void quickSort(int left, int right) {
	if (left == right)
		return;
	int pivot = ary[left],
		i = left + 1,
		j = right;
	while (i < j) {
		for (; ary[i] < pivot && i < j; i++);
		for (; ary[j] > pivot && i < j; j--);
		if (i >= j)
			break;
		swap(ary[i], ary[j]);
	}
	swap(ary[j - 1], ary[left]);
	quickSort(left, i - 1);
	quickSort(i, right);
}
int main() {
	int house=0,
		share=0,
		temp=0,
		i=0;
	scanf("%d%d", &house, &share);
	for (i = 0; i < house; i++) {
		scanf("%d", ary + i);
	}
	quickSort(0, house - 1);
	printf("%d",(ary[0]+ary[house-1])/share);
	return 0;
}
/*
5 9 13 8 2 7 4 6 10 1

1 2 4 8 9
1 2 4 1
1 1 2 4
*/