#include <stdio.h>
#include <stdlib.h>
#define ALLOCATE (node *)malloc(sizeof(node))

typedef struct linked_list {
	int d;
	struct linked_list *next;
} node;

node *head = NULL;
int count = 0;

void add(int);
void append(int);
void insert(int, int);
void del_at_beg();
void del_at_end();
void del_at_pos(int);
void display();

int main() {	
	int choice, x, pos;

	while(1) {
		printf("\n1. Add at begining \n2. Add at end \n3. Insert at position \n");
		printf("4. Delete at begining \n5. Delete at end \n6. Delete at position \n7. Display the list \n");
		printf("8. Show number of elements\n");
		printf("\nEnter your choice: ");
		scanf("%i", &choice); 

		switch(choice) {
			case 1:
				printf("Enter number to be added: ");
				scanf("%i", &x);
				add(x);
				break;
			case 2:
				printf("Enter number to be added: ");
				scanf("%i", &x);
				append(x);
				break;
			case 3:
				printf("Enter number to be added: ");
				scanf("%i", &x);
				printf("Enter the position: ");
				scanf("%i", &pos);
				insert(pos, x);
				break;
			case 4:
				del_at_beg();
				break;
			case 5:
				del_at_end();
				break;
			case 6:
				printf("Enter a position:");
				scanf("%i", &pos);
				del_at_pos(pos);
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Number of nodes: %i\n", count);
				break;
			default:
				printf("Something's gotta be wrong...  :-(");
				exit(1);
		}
	}
}

void add(int x) {
	node *n = ALLOCATE;
	n->d = x;
	count++;

	if(head == NULL)
		n->next = NULL;
    else
		n->next = head;

	head = n;
}

void append(int x) {
	if(head == NULL) {
		add(x);
		return;
	}

	node *n = ALLOCATE;
	n->d = x;
	n->next = NULL;
	count++;

	node *tmp = head;
	
	while(tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = n;
}

void insert(int pos, int x) {
	if(pos == count+1) {
		append(x);
		return;
	} else if(pos > count+1) {
		printf("Operation unsuccessful...invalid position...\n");
		return;
	}

	node *n = ALLOCATE;
	n->d = x;
	count++;

	node *tmp = head;

	while((pos-- -2) != 0) {
		tmp = tmp->next;
	}

	node *tmp1 = tmp->next;
	tmp->next = n;
	n->next = tmp1;

}

void del_at_beg() {
	if(head == NULL) {
		printf("Operation unsuccessful...List is already empty...\n");
		return;
	}

	node *h = head;
	head = head->next;
	free(h);
	count--;
}

void del_at_end() {
	if(head == NULL) {
		printf("Operation unsuccessful...List is already empty...\n");
		return;
	} else if(head->next == NULL) {
		free(head);
		head = NULL;
		count--;
		return;
	}

	node *tmp = head, *tmp1;

	while(tmp->next != NULL) {
		tmp1 = tmp;
		tmp = tmp->next;
	}

	free(tmp);
	tmp1->next = NULL;
	count--;
}

void del_at_pos(int pos) {
	if(pos == 1) {
		del_at_beg();
		return;
	} else if(pos > count) {
		printf("Operation unsuccessful...invalid position...\n");
		return;
	} //printf("\npos: %i, nodes: %i", pos, count_nodes());

	node *tmp = head, *tmp1, *tmp2;

	while((pos-- -1) != 0) {
		tmp1 = tmp;
		tmp = tmp->next;
	}

	tmp2 = tmp->next;

	free(tmp);
	tmp1->next = tmp2;
	count--;
}

void display() {
	if(head == NULL) {
		printf("\nList is empty...\n");
		return;
	}

	node *tmp = head;

	puts("");
	while(tmp != NULL) {
		printf("|%i| -> ", tmp->d);
		tmp = tmp->next;
	}
	puts("");
}