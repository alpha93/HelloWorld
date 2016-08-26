#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list {
	int data;
	struct linked_list *next;
	struct linked_list *prev;
} node;

node *head = NULL, *tail = NULL;
int count = 0;

void add(int);
void append(int);
void insert(int, int);
void del_at_beg();
void del_at_end();
void del_at_pos(int);
void display();
void reverse(node *);
void find_mid(node *);
void insertion_sort();

int main() {
	int choice, x, pos;

	do {
		printf("\n 1. Add at begining \n 2. Add at end \n 3. Insert at position \n");
		printf(" 4. Delete at begining \n 5. Delete at end \n 6. Delete at position \n 7. Display the list \n");
		printf(" 8. Show number of elements \n 9. Reverse list \n10. sort the list \n11. Exit\n");
		printf("\nEnter your choice: ");
		scanf("%i", &choice); 

		switch(choice) {
			case 1:
				printf("Enter number to be added: ");
				scanf("%i", &x);
				add(x);
				display();
				break;
			case 2:
				printf("Enter number to be added: ");
				scanf("%i", &x);
				append(x);
				display();
				break;
			case 3:
				printf("Enter the position: ");
				scanf("%i", &pos);
				printf("Enter number to be added: ");
				scanf("%i", &x);
				insert(pos, x);
				display();
				break;
			case 4:
				del_at_beg();
				display();
				break;
			case 5:
				del_at_end();
				display();
				break;
			case 6:
				printf("Enter a position:");
				scanf("%i", &pos);
				del_at_pos(pos);
				display();
				break;
			case 7:
				display();
				break;
			case 8:
				printf("Number of elements: %i\n", count);
				break;
			case 9:
				reverse(head);
				display();
				break;
			case 10:
				insertion_sort();
				display();
				break;
			case 11:
				printf("\nExit successful...\n");
				exit(0);
			default:
				printf("Something's gotta be wrong...  :-(  \n");
				exit(1);
		}
	} while(1);
}

void add(int x) {
	node *n = (node *)malloc(sizeof(node));
	n->data = x;
	n->prev = NULL;
	count++;

	if(head == NULL) {
		n->next = NULL;
		tail = n;
	}
	else {
		n->next = head;
		head->prev = n;
	}

	head = n;
}

void append(int x) {
	if(head == NULL) {
		add(x);
		return;
	}

	node *n = (node *)malloc(sizeof(node));
	n->data = x;
	n->next = NULL;
	n->prev = tail;
	tail->next = n;
	tail = n;
	count++;
}

void insert(int pos, int x) {
	if(pos == 1) {
		add(x);
		return;
	} else if(pos == count+1) {
		append(x);
		return;
	} else if(pos > count+1) {
		printf("\nOperation unsuccessful...invalid position...");
		return;
	}

	node *n = (node *)malloc(sizeof(node));
	n->data = x;
	count++;

	node *tmp = head, *tmp_next;

	while((pos-- -2) != 0) {
		tmp = tmp->next;
	}

	tmp_next = tmp->next;
	tmp->next = n;
	n->prev = tmp;
	n->next = tmp_next;
	tmp_next->prev = n;
}

void del_at_beg() {
	if(head == NULL) {
		printf("\nOperation unsuccessful...list is already empty...");
		return;
	}

	node *h = head->next;
	free(head);
	head = h;
	count--;

	if(head == NULL)
		tail = NULL;
}

void del_at_end() {
	if(head == NULL) {
		printf("\nOperation unsuccessful...list is already empty...");
		return;
	} else if(head->next == NULL) {
		del_at_beg();
		return;
	}

	node *t = tail;
	tail->prev->next = NULL;
	tail = tail->prev;
	free(t);
	count--;
}

void del_at_pos(int pos) {
	if(pos == 1) {
		del_at_beg();
		return;
	} else if(pos == count) {
		del_at_end();
		return;
	} else if(pos > count) {
		printf("\nOperation unsuccessful...invalid position...");
		return;
	}

	node *tmp = head, *tmp_prev, *tmp_next;

	while((pos-- -1) != 0) {
		tmp = tmp->next;
	}

	tmp_prev = tmp->prev;
	tmp_next = tmp->next;
	free(tmp);
	tmp_prev->next = tmp_next;
	tmp_next->prev = tmp_prev;
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
		printf("[%i] <-> ", tmp->data);
		//printf("[%p [%i] %p] <-> ", tmp->prev, tmp->data, tmp->next);
		tmp = tmp->next;
	}
	puts("");
}

void reverse(node *h) {
	while(h != NULL) {
		node *tmp = h->prev;
		h->prev = h->next;
		h->next = tmp;
		h = h->prev;
	}

	node *tmp = head;
	head = tail;
	tail = tmp;
}

/* function to print the middle element without knowing the number of elements 
   in one sweep: FusionCharts interview question */

void find_mid(node *tmp) {
	static int x, counter;

	if(tmp->next == NULL) {
		counter++;
		x = counter;
		printf("count: %i", counter);
		return;
	}

	counter++;

	find_mid(tmp->next);

	x--;
	if(x == counter/2+1)
		printf("\nvalue: %i\n", tmp->data);
}	

void insertion_sort() {
	node *a = head->next, *b;
	int i;

	for(i=1; i<count; i++) {
		b = a;
		
		while(b->prev != NULL  &&  b->data < b->prev->data) {
			b->data = b->data ^ b->prev->data;
			b->prev->data = b->data ^ b->prev->data;
			b->data = b->data ^ b->prev->data;

			b = b->prev; 
		} 

		a = a->next;
	}
}