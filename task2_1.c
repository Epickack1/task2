#include <stdio.h>

double absolute(double val){
	if (val < 0) return -val;
	return val;

}

int main(){
	double eps;
	double x;
	double cur = 1.0;
	double next;
	scanf("%lf", &eps);
	scanf("%lf", &x);
  	if (x == 0.0) {
		printf("%.10g\n",0.0);
  	}
	do {
 		next = 0.5 *(cur + x/cur);
		if (absolute(next-cur) < eps) {
			break;
		}
	cur = next;
	} while(1);
	printf("%.10g\n",next);
}
