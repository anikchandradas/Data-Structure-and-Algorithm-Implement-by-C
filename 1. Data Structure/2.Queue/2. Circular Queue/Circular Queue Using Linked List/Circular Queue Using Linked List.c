#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

//Enqueue operation on circular queue
void enqueue() {
    int item;
    printf("Enqueue item: ");
    scanf("%d", &item);

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = item;
    newnode->next = NULL;

    if((front == NULL) && (rear == NULL)) {
        front = newnode;
        rear = newnode;
        rear->next = front;
    }
    else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

//Dequeue operation on Circular Queue
void dequeue() {
    struct node *temp;
    temp = front;

    if((front == NULL) && (rear == NULL)) {
        printf("Queue is empty.\n");
    }
    else if(front == rear) {
        //Deletion of last existing element
        printf("Dequeued element is: %d\n", temp->data);
        front = NULL;
        rear = NULL;
        free(temp);
    }
    else {
        printf("Dequeued element is: %d\n", temp->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

//Front item of circular queue
void peek() {
    if((front == NULL) && (rear == NULL)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Peek: %d\n", front->data);
    }
}

//Traversing the circular queue
void display() {
    struct node *temp;
    temp = front;

    if((front == NULL) && (rear == NULL)) {
        printf("Queue is empty.\n");
    }
    else {
        while(temp->next != front) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main()
{
    int ch;
    printf("Linear Queue Implementation: \n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Peek\n");
    printf("4.Display\n");
    printf("5.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: enqueue();
                    break;

            case 2: dequeue();
                    break;

            case 3: peek();
                    break;

            case 4: display();
                    break;

            case 5: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}


