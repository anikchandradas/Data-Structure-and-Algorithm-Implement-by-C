//Singly Linked List Implementation
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* root = NULL;

//Inserting nodes in a singly linked list
void append() {

    int data;
    printf("Append Item: ");
    scanf("%d", &data);

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    if(root == NULL) {
        root = temp;
    }
    else {
        struct node* p;
        p = root;
        while(p->link != NULL) {
            p = p->link;
        }
        p->link = temp;
    }
}

//Traversing a singly linked list
void display() {
    struct node* temp;
    temp = root;
    if(temp == NULL) {
        printf("No nodes have in the linked list.\n");
    }
    else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

//Find out the length of a singly linked list
int length() {
    int count = 0;
    struct node* temp;
    temp = root;
    while(temp != NULL) {
        count++;
        temp = temp->link;
    }
    return count;
}

//Add a node at the beginig of the linked list
void add_at_begin() {

    int data;
    printf("Add At Begin: ");
    scanf("%d", &data);

    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = data;
    temp->link = NULL;

    if(root == NULL) {
        root = temp;
    }
    else {
        temp->link = root; //right side connection
        root = temp;       //left side connection
    }
}

//Search an item by given value
struct node* searchItem() {

    int item;
    printf("Enter Search Item: ");
    scanf("%d", &item);

    struct node* temp;
    temp = root;
    while(temp != NULL) {
        if(temp->data == item) {
            printf("Item found: %d\n", temp->data);
            //return temp;
        }

        temp = temp->link;
    }
    //return 0;
}

//Search an item by given position
int GetItem() {
    int len, position;
    printf("Enter position for getting item: ");
    scanf("%d", &position);
    len = length();
    if(position<0 || position>=len) {
        printf("Invalid position\n");
        return -1;
    }
    struct node* temp;
    int count=0;
    temp = root;
    while(count < position)
    {
        temp=temp->link;
        count++;
    }
    return temp->data;
}

//Delete a specified node by given location
void delete() {
    struct node* temp;
    int loc, len;
    printf("Enter location to delete: ");
    scanf("%d", &loc);
    len = length();

    if(loc > len) {
        printf("Inavalid location.\n");
    }
    else if(loc == 0) { //deleting first item
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else {
        struct node* p, *q;
        p = root;
        int i = 1;
        while(i < loc) {
            p = p->link;
            i++;
        }
        q = p->link;
        p->link = q->link;
        q->link = NULL;
        free(q);
    }
}

//Add a node after a specified node by given location
void add_after() {
    struct node* temp, *p;
    int loc, value, len, i = 0; // index starts from 0
    len = length();

    printf("Enter location for add after: ");
    scanf("%d", &loc);

    if(loc >= len) {
        printf("Invalid Location.\n");
        printf("Last position of this list is =  %d.\n", len-1);
    }
    else {
        printf("Enter value for Add After: ");
        scanf("%d", &value);

        p = root;
        while(i < loc) {
            p = p->link;
            i++;
        }
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = value;
        temp->link = p->link;
        p->link = temp;
    }
}

//Swap nodes in a singly linked list with swapping data
void swap() {
    struct node* p, *q, *r;
    p = root;
    int loc, i = 0;
    printf("Enter location for swap: ");
    scanf("%d", &loc);
    while(i < loc-1) {
        p = p->link;
        i++;
    }
    q = p->link;
    r = q->link;
    q->link = r->link;
    r->link = q;
    p->link = r;
}

//Reverse data in a Singly Linked List without swapping nodes
void reverse_list() {

    struct node* p;
    struct node* q;
    int i, j, k, len, temp;
    len = length();
    i = 0;
    j = len-1;
    p = root;
    q = root;

    while(i < j) {
        k = 0;
        while(k < j) {
            q = q->link;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->link;
        q = root;
    }
}

//Reverse singly linked list nodes along with data
void reverse() {
    printf("Reverse done.\n");
    struct node *prev_node, *curr_node, *next_node;
    prev_node = NULL;
    curr_node = root;
    next_node = root;

    while(next_node != NULL) {
        next_node = next_node->link;
        curr_node->link = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    root = prev_node;
}

// Function to delete the entire linked list
void deleteList(){
    struct node* current = root;
    struct node* next;

    while (current != NULL){
        next = current->link;
        free(current);
        current = next;
    }
    root = NULL;

    printf("Link list deleted.\n");
}

int main()
{
    int ch, m, n;
    printf("Singly Linked List: \n");
    printf("1.append\n");
    printf("2.display\n");
    printf("3.length\n");
    printf("4.add_at_begin\n");
    printf("5.searchItem\n");
    printf("6.GetItem\n");
    printf("7.delete\n");
    printf("8.add_after\n");
    printf("9.swap\n");
    printf("10.reverse_list\n");
    printf("11.reverse\n");
    printf("12.deleteList\n");
    printf("13.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: append();
                    break;

            case 2: display();
                    break;

            case 3: m = length();
                    printf("Length : %d\n", m);
                    break;

            case 4: add_at_begin();
                    break;

            case 5: searchItem();
                    break;

            case 6: n = GetItem();
                    printf("Item: %d\n", n);
                    break;

            case 7: delete();
                    break;

            case 8: add_after();
                    break;

            case 9: swap();
                    break;

            case 10: reverse_list();
                     break;

            case 11: reverse();
                     break;

            case 12: deleteList();
                     break;

            case 13: exit(0);
                     break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}
