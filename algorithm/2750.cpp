#include<cstdio>
#include<algorithm>
int main() {
	int no = 0;
	int ary[10000000] = { 0, };
	int i = 0;
	
	scanf("%d", &no);
	for (i = 0; i < no; i++) {
		scanf("%d", ary + i);
	}
	std::sort(ary, ary + no);
	for (i = 0; i < no; i++) {
		printf("%d\n", ary[i]);
	}
	return 0;
}