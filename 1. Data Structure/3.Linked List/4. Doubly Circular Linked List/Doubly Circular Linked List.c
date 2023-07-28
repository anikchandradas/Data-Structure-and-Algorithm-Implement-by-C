#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail;


//Insertion of Doubly Circular Linked List
void create_DLL() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Node Data: ");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        head = newnode;
        tail = newnode;

        head->next = head;
        head->prev = head;
    }
    else {
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
    /*
        //To check doubly circular linked list completed

        //This statement will print the first node data
        printf("%d", tail->next->data);

        //This statement will print the last node data
        printf("%d", head->prev->data);
    */
}

//Traversing Doubly Circular Linked List
void display() {
    struct node *temp;
    temp = head;

    if(head == NULL) {
        printf("List is empty.\n");
    }
    else {
        while(temp != tail) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
        /*to avoid use this printf statement after while loop
            write while loop condition like this-->
            while(temp->next != tail->next)
        */
    }
}

//Insert at begining of DCLL
void insert_at_begin() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data to add at begin: ");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        head = newnode;
        tail = newnode;

        newnode->prev = tail;
        newnode->next = head;
    }
    else {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

//Insert at the end of DCLL
void insert_at_end() {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data to add at the end: ");
    scanf("%d", &newnode->data);

    if(head == NULL) {
        head = newnode;
        tail = newnode;

        newnode->prev = tail;
        newnode->next = head;
    }
    else {
        newnode->prev = tail;
        tail->next = newnode;
        newnode->next = head;
        head->prev = newnode;
        tail = newnode;
    }
}

//Insert at given position in DCLL
void insert_at_position() {
    struct node *newnode, *temp;
    int position, len, i = 1;
    len = length();
    temp = head;
    printf("Isert position to add node: ");
    scanf("%d", &position);

    if(position < 1 || position > len) {
        printf("Invalid position.\n");
    }
    else if(position == 1) {
       insert_at_begin();
    }
    else {
       newnode = (struct node*)malloc(sizeof(struct node));
       printf("Enter node data: ");
       scanf("%d", &newnode->data);

        while(i < position-1) {
            temp = temp->next;
            i++;
       }
       newnode->prev = temp;
       newnode->next = temp->next;
       temp->next->prev = newnode;
       temp->next = newnode;
    }
}

//Deletion from begning in DCLL
void delete_from_beg() {
    struct node *temp;
    temp = head;

    if(head == NULL) {
        printf("List is empty.\n");
    }
    else if(head->next == head) {
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else{
        head = head->next;
        head->prev = tail;
        tail->next = head;
        free(temp);
    }
}

//Deletion from end of a DCLL
void delete_at_end() {
    struct node *temp;
    temp = tail;

    if(head == NULL) {
        printf("List is empty.\n");
    }
    else if(head->next == head) {
        head = NULL;
        tail = NULL;
        free(temp);
    }
    else {
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        free(temp);
    }
}

//Deletion from given position
void delete_from_position() {
    struct node *temp;
    int len, position, i = 1;
    temp = head;
    len = length();

    printf("Enter position to delete: ");
    scanf("%d", &position);

    if(position < 1 || position > len) {
        printf("Invalid Position.\n");
    }
    else if(position == 1) {
        delete_from_beg();
    }
    else {
        while(i < position) {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if(temp->next == head) {
            tail = temp->prev;
        }
        else {
            free(temp);
        }
    }
}

//Find out the length
int length(){
	struct node *temp = head;
	int result = 0;
	if (tail != NULL) {
		do {
			temp = temp->next;
			result++;
		}while(temp != tail);
		result = result + 1;
	}
	return result;
}

//Search operation in Singly-CLL
void search() {
    struct node *temp;
    temp = head;

    int item;
    printf("Enter item for search: ");
    scanf("%d", &item);

    if(head == NULL) {
        printf("List is empty.\n");
    }
    else {

        while(temp != tail) {
            if(temp->data == item) {
                printf("Item found: %d\n", temp->data);
                exit(0);
            }
            temp = temp->next;
        }
        if(temp->data == item) {
            printf("Item found: %d\n", temp->data);
            exit(0);
        }
        else{
            printf("Item not found.\n");
        }
    }
}

int main()
{
    int ch, len;
    printf("Doubly Circular Linked List Implementation: \n");
    printf("1.create_DLL\n");
    printf("2.display\n");
    printf("3.insert_at_begin\n");
    printf("4.insert_at_end\n");
    printf("5.insert_at_position\n");
    printf("6.delete_from_beg\n");
    printf("7.delete_at_end\n");
    printf("8.delete_from_position\n");
    printf("9.length\n");
    printf("10.search\n");
    printf("11.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create_DLL();
                    break;

            case 2: display();
                    break;

            case 3: insert_at_begin();
                    break;

            case 4: insert_at_end();
                    break;

            case 5: insert_at_position();
                    break;

            case 6: delete_from_beg();
                    break;

            case 7: delete_at_end();
                    break;

            case 8: delete_from_position();
                    break;

            case 9: len = length();
                    printf("Length: %d\n", len);
                    break;

            case 10: display();
                    break;

            case 11: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}




