#include <stdio.h>
#include <stdlib.h>
#define ALLOCATE (node *)malloc(sizeof(node))

typedef struct linked_list {
	int d;
	struct linked_list *next;
} node;

node *head = NULL;
node *tail = NULL; /* for the append() function, to get to the last element we have to traverse
					  the entire list which is very inefficient. So to gain access to the last element instantly, 
					  the tail pointer keeps track of the last element */
				   /* the delete_at_end() and delete_at_pos() functions counld also have been made efficient
				      by keeping a pointer to the 2nd last element */
int count = 0;

void add(int);
void append(int);
void insert(int, int);
void del_at_beg();
void del_at_end();
void del_at_pos(int);
void display();
void reverse(node *);
void find_mid(node *);	// FusionCharts interview question
void bubble_sort();

int main() {	
	int choice, x, pos;

	do {
		printf("\n 1. Add at begining \n 2. Add at end \n 3. Insert at position \n");
		printf(" 4. Delete at begining \n 5. Delete at end \n 6. Delete at position \n 7. Display the list \n");
		printf(" 8. Show number of elements \n 9. Reverse list \n10. Sort the list \n11. Exit \n");
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
				bubble_sort();
				display();
				break;
			case 11:
				printf("\nExit successful...");
				exit(0);
			default:
				printf("\nSomething's gotta be wrong...  :-(");
				exit(1);
		}
	} while(1);
}

void add(int x) {
	node *n = ALLOCATE;
	n->d = x;
	count++;

	if(head == NULL) {
		n->next = NULL;
		tail = n;
	}
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
	tail->next = n;
	tail = n;
	count++;

	/*node *tmp = head;	
	while(tmp->next != NULL) {
		tmp = tmp->next;		//we had use this costly traversal if the tail pointer wasn't used
	}
	tmp->next = n;*/
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
		printf("\nOperation unsuccessful...List is already empty...");
		return;
	}

	node *h = head;
	head = head->next;
	free(h);
	count--;

	if(head == NULL)
		tail = NULL;
}

void del_at_end() {
	if(head == NULL) {
		printf("\nOperation unsuccessful...List is already empty...");
		return;
	} else if(head->next == NULL) {
		del_at_beg();
		return;
	}	

	node *tmp = head, *tmp1;
	
	while(tmp->next != NULL) {
		tmp1 = tmp;
		tmp = tmp->next;
	}
	
	free(tmp);
	tail = tmp1;
	tmp1->next = NULL;
	count--;
}

void del_at_pos(int pos) {
	if(pos == 1) {
		del_at_beg();
		return;
	} else if(pos == count) {
		del_at_end();
		return;
	}else if(pos > count) {
		printf("\nOperation unsuccessful...invalid position...");
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
		printf("[%i] -> ", tmp->d);
		tmp = tmp->next;
	}
	puts("");
}

void reverse(node *h) {		// it works by reversing the links, the data remains where they are
	if(h->next->next == NULL) {
		tail = head;
		head = h->next;
		h->next->next = h;
		return;
	}

	reverse(h->next);

	h->next->next = h;
	h->next = NULL;
}

/* function to print the middle element(can be used find elements at position) without knowing the number of elements 
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
		printf("\nvalue: %i\n", tmp->d);
}

void bubble_sort() {
	node *a, *b;;
	int i, j;

	for(i=0; i<count-1; i++) {
		int flag = 0;
		a = head;
		b = head->next;

		for(j=0; j<count-i-1; j++) {
			if(a->d > b->d) {
				a->d = a->d ^ b->d;
				b->d = a->d ^ b->d;
				a->d = a->d ^ b->d;
				flag = 1;
			}

			a = a->next;
			b = b->next;
		}

		if(!flag)
			break;
	}
}