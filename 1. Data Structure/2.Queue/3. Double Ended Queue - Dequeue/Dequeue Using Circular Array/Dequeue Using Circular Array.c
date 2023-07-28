#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
int dequeue[SIZE];
int front = -1;
int rear = -1;

//Enqueue-Front Operation on Double Ended Queue
void enqueue_front() {
    int item;
    printf("Enqueue Front Item: ");
    scanf("%d", &item);

    if(((front == 0)&&(rear == SIZE-1))||(front == rear+1)){
        printf("Queue is full.\n");
    }
    else if((front == -1) && (rear == -1)) {
        front = 0;
        rear = 0;
        dequeue[front] = item;
    }
    else if(front == 0) {
        front = SIZE-1;
        dequeue[front] = item;
    }
    else {
        front--;
        dequeue[front] = item;
    }
}

//Enqueue-Rear Operation on Double Ended Queue
void enqueue_rear() {
    int item;
    printf("Enqueue Rear Item: ");
    scanf("%d", &item);

    if(((front == 0)&&(rear == SIZE-1))||(front == rear+1)) {
        printf("Queue is full.\n");
    }
    else if((front == -1)&&(rear == -1)) {
        front = 0;
        rear = 0;
        dequeue[rear] = item;
    }
    else if(rear == SIZE-1) {
        rear = 0;
        dequeue[rear] = item;
    }
    else {
        rear++;
        dequeue[rear] = item;
    }
}

//Traversing The Double Ended Queue
void display() {
    int i = front;
    if((front == -1) && (rear == -1)) {
        printf("Queue is Empty.\n");
    }
    else {
        while(i != rear) {
            printf("%d ", dequeue[i]);
            i = (i+1)%SIZE;
        }
        printf("%d\n", dequeue[rear]);
    }
}

//void Get Front Element of Double Ended Queue
void getFront() {
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Front Element: %d\n", dequeue[front]);
    }
}

//void Get Rear Element of Double Ended Queue
void getRear() {
    if((front == -1)&&(rear == -1)) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Rear Element: %d\n", dequeue[rear]);
    }
}

//Dequeue-Front Operation on Double Ended Queue
void dequeue_front() {
    if((front == -1)&&(rear == -1)) {
        printf("Queue is empty.\n");
    }
    else if(front == rear) {
        printf("Dequed Front: %d\n", dequeue[front]);
        front = -1;
        rear = -1;
    }
    else if(front == SIZE-1) {
        printf("Dequed Front: %d\n", dequeue[front]);
        front = 0;
    }
    else {
        printf("Dequed Front: %d\n", dequeue[front]);
        front++;
    }
}

//Dequeue-Rear Operation on Double Ended Queue
void dequeue_rear() {
    if((front == -1) && (rear == -1)) {
        printf("Queue is empty.\n");
    }
    else if(front == rear) {
        printf("Dequed Rear: %d\n", dequeue[rear]);
        front = -1;
        rear = -1;
    }
    else if(rear == 0) {
        printf("Dequed Rear: %d\n", dequeue[rear]);
        rear = SIZE-1;
    }
    else {
        printf("Dequed Rear: %d\n", dequeue[rear]);
        rear--;
    }
}

int main()
{
    int ch;
    printf("Dequeue Using Circular Array: \n");
    printf("1.Enqueue Front\n");
    printf("2.Enqueue Rear\n");
    printf("3.Dequeue Front\n");
    printf("4.Dequeue Rear\n");
    printf("5.Get Front\n");
    printf("6.Get Rear\n");
    printf("7.Display\n");
    printf("8.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: enqueue_front();
                    break;

            case 2: enqueue_rear();
                    break;

            case 3: dequeue_front();
                    break;

            case 4: dequeue_rear();
                    break;

            case 5: getFront();
                    break;

            case 6: getRear();
                    break;

            case 7: display();
                    break;

            case 8: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}


