#include<stdio.h>
short gcd(short firstNo, short secondNo) {
	if (firstNo > secondNo)
		firstNo -= secondNo;
	else if (firstNo < secondNo)
		secondNo -= firstNo;
	else
		return firstNo;
	gcd(firstNo, secondNo);
}
short main() {
	short result[100];
	short n = 0,
		no=0,
		sum=0,
		i=0,
		j=0;
	scanf(" %d", &n);
	
	short ary[100] = { 0, };
	for (short z = 0; z < n; z++) {
		scanf("%d", &no);
		for (short k = 0; k < no; k++) {
			scanf("%d", ary + k);
		}
		for (i = 0; i < no-1; i++) {
			for (j = i + 1; j < no; j++) {
				sum += gcd(ary[i], ary[j]);
			}
		}
		result[z] = sum;
		sum = 0;
	}
	for (short i = 0; i < no; i++) {
		prshortf("%d\n", result[i]);
	}
	
	return 0;
}
