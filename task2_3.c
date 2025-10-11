#include <stdio.h>

long fibon1(int n) {
	int p1 = 1;
	int p2 = 0;
	int cur;
	if (n == 0) return 0;
	if (n == 1) return 1;
	for (int i = 2; i <= n; i++){
		cur = p2 + p1;
		p2 = p1;
		p1 = cur;
	}
	return cur;
}
long fibon2(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fibon2(n-2) + fibon2(n-1);
}
int main() {
	int i;
	scanf("%d", &i);
	long res1 = fibon1(i);
	printf("%ld\n",res1);
	long res2 = fibon2(i);
	printf("%ld\n",res2);
}
