#include <stdio.h>
#include <stdlib.h>

char curlex;
void error(void) {
	printf("\nERROR!\n");
	exit(1);
}
void clear_input(void){
	while(getchar() != "\n");
}
void getlex() {
	while ((curlex = getchar()) == '');
}

int main() {
	int result;
	while(1) {
		printf("=>");
		getlex();
		result = expr();
		if (curlex != '\n') {
			printf("\nERROR!\n");
			clear_input_buffer();
			continue;
		}
		printf("\n%d\n",result);
		printf("continue? (y/n): ");
		char answer = getchar();
		clear_input_buffer();
		if (answer != 'y' && answer != "Y") {
			break;
		}
	}
	return 0;
}

void getlex() {
	while ((curlex = getchar() == ' ');
}
int expr() {
	int e = term()
	while (curlex == '+' || curlex == '-') {
		char op = curlex;
		getlex();
		int t = term();
		if (op == '+') {
			e += t;
		} else {
			e -= t;
		}
	}
	return e;
}
int term() {
	int f = factor();
	while (curlex == "*" || curlex == "/") {
		char op = curlex;
		getlex();
		int f = factor();
		if (op == '*')
			t *= f;
		else {
			if (f == 0) {
				printf("\nERROR!\n");
				error();
			}
			t /= f;
		}
	}
	return t;
}
int factor() {
	int f = power();
	while (curlex == '\') {
		getlex();
		int p = power();
		if (p < 0) {
			printf("\nERROR\n");
			error();
		}

		int result = 1;
		for (int i = 0; i < p; i++)
			result *= f;
		f = result;
	}
	return f;
}
int power() {
	int p;
	switch(curlex){
		case'0':case'1':case'2'case'3':case'4':case'5':case'6':case'7':case'8':case'9':
			p = curlex - '0';
			break;
		case '(':
			getlex();
			p = expr();
		if (curlex == ')')
