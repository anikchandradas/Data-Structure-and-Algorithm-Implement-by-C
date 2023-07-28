#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

//Inserting element into stack
void push() {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    printf("Enter node data to push in stack: ");
    scanf("%d", &temp->data);
    temp->link = top;
    top = temp;
}

//Deleting element from stack
void pop() {
    struct node *temp;

    if(top == NULL) {
        printf("Stack is empty.\n");
    }
    else {
        temp = top;
        printf("Pop element is: %d\n", temp->data);
        top = top->link;

        temp->link = NULL;
        free(temp);
    }
}

//Traversing the stack
void traverse() {
    struct node *temp;

    if(top == NULL) {
        printf("Stack is empty.\n");
    }
    else {
        temp = top;
        while(temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    printf("Stack Implementation:\n");
    printf("1.Push\n");
    printf("2.Pop\n");
    printf("3.Traverse\n");
    printf("4.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: traverse();
                    break;

            case 4: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}
