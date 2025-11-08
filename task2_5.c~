#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct WordNode {
	char word;
	struct WordNode* next;
} WordNode;

WordNode* create_node(char word) {
	WordNode* new_node = (WordNode*)malloc(sizeof(WordNode));
	new_node->word = word;
	new_node->next = NULL;
	return new_node;
}
void print_list(WordNode* head){
	WordNode* current = head;
	
	while (current != NULL) {
		printf("%c", current->word);
		if (current->next != NULL) {
			printf(" ");
		}
		current = current->next;
	}
	printf("\n");
}
void add_to_list(WordNode** head, char word) {
	WordNode* new_node = create_node(word);
	
	if (*head == NULL) {
		*head = new_node;
	} else {
		WordNode* current = *head;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
	}
}
void remove_from_list(WordNode** head) {
	if (*head == NULL) return;
	
	WordNode* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	char last = current->word;
	WordNode* prev = NULL;
	current = *head;

	while (current != NULL) {
		if (((current->word) == last)  && (current->next != NULL)) {
			if (prev == NULL) {
				*head = current->next;
				free(current);
				current = *head;
			} else {
				prev->next = current->next;
				free(current);
				current = prev->next;
			}
		} else {
			prev = current;
			current = current->next;
		}
	}
}

// abcdledfnasn...
int main() {
	char c;
	WordNode* wordlist = NULL;
	while ( (c = getchar()) != '.') {
		add_to_list(&wordlist,c);
	}
	remove_from_list(&wordlist);
	print_list(wordlist);
	WordNode* current = wordlist;
	while (current != NULL) {
		WordNode* temp = current;
		current = current->next;
		free(temp);
	}
	return 0;
}

