#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

//Inserting element into linear queue
void enqueue() {
    int item;
    printf("Enqueue element: ");
    scanf("%d", &item);

    if(rear == SIZE-1) {
        printf("Queue is full.\n");
    }
    else if((front == -1) && (rear == -1)) {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else {
        rear++;
        queue[rear] = item;
    }
}

//Deleting elements from linear queue
void dequeue() {
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else if(front == rear) {
        printf("Dequed element is: %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else {
        printf("Dequed element: %d\n", queue[front]);
        front++;
    }
}

//Traversing linear queue
void display(){
    int i;
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else {
        for(i = front; i < rear+1; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

//Display top element of linear queue
void peek() {
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Peek element is: %d\n", queue[front]);
    }
}

int main()
{
    int ch;
    printf("Queue Implementation: \n");
    printf("1.Enqueue\n");
    printf("2.Dequeue\n");
    printf("3.Display\n");
    printf("4.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: enqueue();
                    break;

            case 2: dequeue();
                    break;

            case 3: display();
                    break;

            case 4: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}
