#include<stdio.h>
long long no[1500000];
short main() 
{
	long long	i = 2,
		n = 0;
	no[1] = 1;
	for (i = 2; i <= 1500000; i++) {
		no[i] = (no[i - 1] + no[i - 2]) % 1000000;
	}
	scanf("%d", &n);
	prshortf("%lld", no[n]);
	return 0;
}