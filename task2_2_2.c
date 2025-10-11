#include <stdio.h>

int main() {
	double x;
	double res = 0;
	double d = 0;
	double c = 0;
	scanf("%lf",&x);
	while (scanf("%lf",&c)== 1) {
		d = d * x + res;
		res = res * x + c;
	}
	printf("%10g\n",res);
	printf("%10g\n",d);
}
