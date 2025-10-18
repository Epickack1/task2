#include <stdio.h>
double check(char str[]) {
	double result = 0.0;
	double fraction = 0.0;
	int sign = 1;
	int exps = 1;
	int exp = 0;
	int i = 0;
	double div = 10.0;
	while (str[i] == ' ' || str[i] == '\t') {
		i++;
	}
	if (str[i] == '-') {
		sign = -1;
		i++;
	} else if (str[i] == '+') {
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.') {
		i++;
		while (str[i] >= '0' && str[i] <= '9') {
			fraction = fraction + (str[i] - '0') / div;
			div *= 10;
			i++;
		}
		result += fraction;
	}
	if (str[i] == 'e' || str[i] == 'E') {
		i++;
		if (str[i] == '-') {
			exps = -1;
			i++;
		} else if (str[i] == '+') {
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9') {
			exp = exp * 10 + (str[i] - '0');
			i++;
		}
	}
	if (exp != 0) {
		double power = 1.0;
		if (exps == 1) {
			for (int j = 0; j < exp; j++) {
				power *= 10;
			}
		} else {
			for (int j = 0; j < exp; j++) {
				power /= 10;
			}
		}
		result *= power;
	}
	return sign * result;
}
int main() {
	char str[100];
	while (scanf("%99s", str) == 1) {
		double number = check(str);
		printf("%.10g\n",number);
	}
	return 0;
}
