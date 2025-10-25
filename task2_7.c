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
	
