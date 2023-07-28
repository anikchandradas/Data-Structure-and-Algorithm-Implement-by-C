#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int queue[SIZE];
int front = -1;
int rear = -1;

//Inserting element into circular queue
void enqueue() {
    int item;
    printf("Enqueue item: ");
    scanf("%d", &item);

    if((front == -1) && (rear == -1)) {
        front = 0;
        rear = 0;
        queue[rear] = item;
    }
    else if(((rear + 1)%SIZE) == front) {
        printf("Queue is full.\n");
    }
    else {
        rear = (rear+1)%SIZE;
        queue[rear] = item;
    }
}

//Deleting element from circular queue
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
        printf("Dequed element is: %d\n", queue[front]);
        front = (front+1)%SIZE;
    }
}

//Traversing elements from circular queue
void display() {
    int i = front;
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Queue elements are: \n");
        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i+1)%SIZE;
        }
        printf("%d\n", queue[i]);
    }
}

//Display top element of circular queue
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
    int ch, n;
    printf("Circular Queue Implementation: \n");
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
