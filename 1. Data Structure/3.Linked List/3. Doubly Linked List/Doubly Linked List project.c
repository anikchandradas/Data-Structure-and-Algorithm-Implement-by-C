//Implementation of Doubly Linked List
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root;

//inserting nodes in doubly righted list
void append() {
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int value;
    printf("Enter node data: ");
    scanf("%d", &value);

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL) {
        //inserting first node
        root = temp;
    }
    else{
        //inserting remaining nodes
        struct node* p;
        p = root;
        while(p->right != NULL) {
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
}

//Insert node at the begining of doubly righted list
void add_at_begin() {
    struct node* temp;
    int value;
    printf("Enter node data: ");
    scanf("%d", &value);

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL) {
        root = temp;
    }
    else {
        temp->right = root;
        root->left = temp;
        root = temp;
    }
}

//Insert a node after a specified node location
void add_at_after() {
    struct node* temp, *p;
    int loc, len, value, i = 0;
    printf("Enter location to add after: ");
    scanf("%d", &loc);
    len = length();

    if(loc >= len) {
        printf("Invalid Location.\n");
        printf("Last index of this list is %d.\n", len-1);
    }
    //creating new node
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data: ");
    scanf("%d", &value);

    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    //if the location point to the last node to add after
    if(loc == (len-1)) {
        //itteration of p to point the last node
        p = root;
        while(p->right != NULL) {
            p = p->right;
        }
        //conections for last node insertion
        p->right = temp;
        temp->left = p;

    }
    //if the location point to the remaining nodes to add after
    else {
        //itteration of p to point the given location node
        p = root;
        while(i < loc) {
            p = p->right;
            i++;
        }
        //connections for the remaining nodes
        temp->right = p->right;
        p->right->left=temp;
        temp->left = p;
        p->right = temp;

    }
}

//Traversing doubly righted list
void display() {
    struct node* temp = root;

    if(temp == NULL) {
        printf("List is empty.\n");
    }
    else {
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->right;
        }
    }
    printf("\n");
}

//Find out the length of a doubly righted list
int length() {
    int count = 0;
    struct node* temp = root;
    while(temp != NULL) {
        count++;
        temp = temp->right;
    }
    return count;
}

//Search an item by given value
struct node* searchItem(int item) {

    struct node* temp;
    temp = root;
    while(temp != NULL) {
        if(temp->data == item) {
            return temp;
        }

        temp = temp->right;
    }
    return 0;
}

//Search an item in a doubly righted list by given position
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
        temp=temp->right;
        count++;
    }
    return temp->data;
}

//Delete a node in a doubly righted list by given location
void delete_node() {
    struct node* temp, *p, *q, *r;
    int loc, len, i = 0;;
    len = length();
    p = root;

    printf("Enter location to delete: ");
    scanf("%d", &loc);

    if(loc >= len) {
        printf("Invalid location.\n");
    }
    else if(loc == 0) {
        //deleting first node
        temp = root;
        root = temp->right;
        temp->right->left = NULL;

        temp->right = NULL;
        free(temp);
    }
    else if(loc == len-1) {
        //deleting last node
        while(i < loc-1) {
        p = p->right;
        i++;
        }
        q = p->right;
        p->right = NULL;
        q->left = NULL;

        free(q);


    }
    else {
        //deleting remaining nodes
        while(i < loc-1) {
            p = p->right;
            i++;
        }

        q = p->right;
        r = q->right;

        //connections
        p->right = r;
        r->left = p;

        q->left = NULL;
        q->right = NULL;
        free(q);
    }
}

// Function to delete the entire linked list
void deleteList() {
    struct node* current_node = root;
    struct node* next_node;

    while (current_node != NULL) {
        next_node = current_node->right;
        free(current_node);
        current_node = next_node;
    }
    root = NULL;
    printf("Linked list deleted.\n");
}

//Reverse a doubly linked list
void reverse(){
    struct node* temp = NULL;
    struct node* current = root;

    /* swap right and left for all nodes of
    doubly righted list */
    while (current !=  NULL) {
        temp = current->left;
        current->left = current->right;
        current->right = temp;
        current = current->left;
     }

     /* Before changing head, check for the cases like empty
        list and list with only one node */
     if(temp != NULL ) {
        root = temp->left;
     }
}

int main()
{
    int ch, n, len, val;
    printf("Doubly Linked List Implementation: \n");
    printf("1.append\n");
    printf("2.add_at_begin\n");
    printf("3.add_at_after\n");
    printf("4.display\n");
    printf("5.length\n");
    printf("6.searchItem\n");
    printf("7.GetItem\n");
    printf("8.delete_node\n");
    printf("9.deleteList\n");
    printf("10.reverse\n");
    printf("11.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: append();
                    break;

            case 2: add_at_begin();
                    break;

            case 3: add_at_after();
                    break;

            case 4: display();
                    break;

            case 5: len = length();
                    printf("Length = %d\n", len);
                    break;

            case 6: printf("Enter value for search: ");
                    scanf("%d", &n);
                    struct node* s;
                    s = searchItem(n);
                    if(s != NULL) {
                        printf("Found = %d\n", s->data);
                    }
                    else {
                        printf("Not Found\n");
                    }
                    break;

            case 7: val = GetItem();
                    printf("Get item = %d\n", val);
                    break;

            case 8: delete_node();
                    break;

            case 9: deleteList();
                    break;

            case 10: reverse();
                    break;

            case 11: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}


