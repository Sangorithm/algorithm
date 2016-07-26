#include<cstdio>
#include<algorithm>
long long ary[1000000];
int cnt[10000];
long long noo[10000];
int main() {
	long long no = 0,
		i = 0,
		j = 0,
		result = 0;
	int current = 0,
		max = 0;
	scanf("%lld", &no);
	for (i = 0; i < no; i++)
		scanf("%lld", ary + i );
	std::sort(ary, ary + i);
	for (i = 0; i < no; i++) {
		if (ary[i] == ary[i + 1]) {
			cnt[current]++;
			continue;
		}
		cnt[current]++;
		noo[current++] = ary[i];
	}
	max = cnt[0];
	for (i = 0; i <= current; i++)
		if (cnt[i] < cnt[i + 1])
			result = i + 1;
	printf("%lld\n",noo[result]);
	return 0;
}