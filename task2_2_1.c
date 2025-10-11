#include <stdio.h>
int main() {
	double x;
	double res = 0;
	double c;
	scanf("%lf",&x);
	while (scanf("%lf", &c) == 1) {
		res = res * x + c;
	}
	printf("%.10g\n",res);
}
