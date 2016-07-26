//#include <iostream> 
//using namespace std;
//bool sangorithm(short x) {
//	if (x < 2) {
//		return false;
//	}
//	for (short i = 2; i*i <= x; i++) {
//		if (x % i == 0) {
//			return false;
//		}
//	}
//	return true;
//}
//short main() {
//	short n;
//	cin >> n;
//	short hosung = 0;
//
//	for (short i = 0; i < n; i++) {
//		short num;
//		cin >> num;
//		if (sangorithm(num)) {
//			hosung += 1;
//		}
//	}
//	cout << hosung << '\n';
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//void main() {
//	short repreat,
//		i = 0,
//		j = 0,
//		k = 0,
//		index = 0,
//		sum = 1,
//		no = 0,
//		temp = 0;
//	short *ary;
//	scanf(" %d", &repreat);
//	for (i = 0; i < repreat; i ++) {
//		scanf(" %d", &no);
//		for (j = 0; j < no ; j++ ) {
//			scanf(" %d", &temp);
//			for (k = 0; k <=temp; k++ ){
//				if (temp % k != 0)
//					break;
//			}
//		}
//		prshortf(" %d", sum);
//	}
//}
/*
ary = (short *)calloc(no, sizeof(short));
for (j = 0; j < no;j++)
scanf(" %d",ary+j);
for (j = 3, index = 0; index < no; j += 2, index++) {
for (k = 3; k <= j, ary[index] % k != 0; k += 2);
if (k == j)
++sum;
}
++sum;
prshortf("%d", sum);
sum = 1;*/