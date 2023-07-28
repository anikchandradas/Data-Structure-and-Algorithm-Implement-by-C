//coding by Anik
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *tail = NULL;

//Insertion of node on Singly Circular Linked List
void create_CLL() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter Node Data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

//Traversing Singly Circular Linked List
void display() {
    struct node *temp;
    if(tail == NULL) {
        printf("List is empty.\n");
    }
    else {
        temp = tail->next;
        while(temp->next != tail->next) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d", temp->data);
    }
    printf("\n");
}

//Insert a node at beginning of CLL
void insert_at_begin() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data to insert at begin: ");
    scanf("%d", &newnode->data);
    newnode ->next = NULL;

    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

//Insert a node at the end of the CLL
void insert_at_end() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter Data to insert at the end: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if(tail == NULL) {
        tail = newnode;
        tail->next = newnode;
    }
    else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

//Inserting a node at given position in CLL
void insert_at_position() {
    struct node *newnode, *temp;
    int position, len, i = 1;

    printf("Enter postion to insert: ");
    scanf("%d", &position);

    len = length();

    if(position < 0 || position > len) {
        printf("Invalid Location\n");
    }
    else if(position == 1) {
        insert_at_begin();
    }
    else if(position == len) {
        insert_at_end();
    }
    else {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter node data to add at position %d: ", position);
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        temp = tail->next;
        while(i < (position-1)) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

//Find out the length
int length(){
	struct node *temp = tail;
	int result = 0;
	if (tail != NULL) {
		do {
			temp = temp->next;
			result++;
		} while (temp->next != tail->next);
	}

	return result;
}

//Deleting a node from beginning
void delete_from_begining() {
    struct node *temp;
    temp = tail->next;

    if(tail == NULL) {
        printf("List is empty.\n");
    }
    else if(temp->next == temp) {
        tail == NULL;
        free(temp);
    }
    else {
        tail->next = temp->next;
        free(temp);
    }
}

//Deleting a node from end
void delete_from_end() {
    struct node *current, *previous;
    current = tail->next;

    if(tail == NULL) {
        printf("List is empty.\n");
    }
    else if(current->next == current) {
        tail == NULL;
        free(current);
    }
    else {
        while(current->next != tail->next) {
            previous = current;
            current = current->next;
        }
        previous->next = tail->next;
        tail = previous;
        free(current);
    }
}

//Deleting a node by given position
void delete_from_position() {
    struct node *current, *nextnode;
    int position, len, i = 1;

    current = tail->next;

    printf("Enter position for delete: ");
    scanf("%d", &position);

    if(position < 1 || position > len) {
        printf("Invalid Position.\n");
    }
    else if(position == 1) {
       delete_from_begining();
    }
    else {
        while(i < (position-1)) {
            current = current->next;
            i++;
        }
        nextnode = current->next;
        current->next = nextnode->next;
        free(nextnode);
    }
}
//have a bug in reverse function
/*
void reverse() {
    struct node *current, *previous, *nextnode;
    current = tail->next;
    nextnode = current->next;
    if(tail = NULL) {
        printf("List is empty.\n");
    }
    else {
        //check this while loop condition
        while(current != tail) {
            previous = current;
            current = nextnode;
            nextnode = current->next;
            current->next = previous;
        }
        nextnode->next = tail;
        tail = nextnode;
    }
}
*/

//Search operation in Singly-CLL
void search() {
    struct node *temp;
    if(tail == NULL) {
        printf("List is empty.\n");
    }
    else {
        printf("Enter item for search: ");
        int item;
        scanf("%d", &item);
        temp = tail->next;
        while(temp->next != tail->next) {
            if(item == temp->data) {
                printf("Item founf = %d\n", temp->data);
                //exit(0);
            }
            temp = temp->next;
        }
        if(item == temp->data) {
            printf("Item founf = %d", temp->data);
            //exit(0);
        }
        else {
            printf("Item not found.\n");
        }
    }
}

int main()
{
    int ch, n;
    printf("Singly Circular Linked List Implementation: \n");
    printf("1.create_CLL\n");
    printf("2.display\n");
    printf("3.insert_at_begin\n");
    printf("4.insert_at_end\n");
    printf("5.insert_at_position\n");
    printf("6.length\n");
    printf("7.delete_from_begining\n");
    printf("8.delete_from_end\n");
    printf("9.delete_from_position\n");
   // printf("10.reverse\n");
    printf("10.search\n");
    printf("11.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create_CLL();
                    break;

            case 2: display();
                    break;

            case 3: insert_at_begin();
                    break;

            case 4: insert_at_end();
                    break;

            case 5: insert_at_position();
                    break;

            case 6: n = length();
                    printf("Length : %d\n", n);
                    break;

            case 7: delete_from_begining();
                    break;

            case 8: delete_from_end();
                    break;

            case 9: delete_from_position();
                    break;

            /*
            case 10: reverse();
                    break;
            */

            case 10: search();
                     break;

            case 11: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}
