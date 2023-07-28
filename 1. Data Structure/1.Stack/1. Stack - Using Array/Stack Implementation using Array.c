#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 5

int stack[CAPACITY];
int top = -1;

//To check Stack is full or not
int isFull() {
    if(top == (CAPACITY-1)) {
        return 1;
    }
    else {
        return 0;
    }
}

//To check stack is empty or not
int isEmpty() {
    if(top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

//Inserting element into stack
void push(int ele) {
    if(isFull()) {
        printf("Stack is overflow.\n");
    }
    else {
        top++;
        stack[top] = ele;
        printf("Pushed item = %d\n", ele);
    }
}

//Deleting element from stack
int pop() {
    int ele;

    if(isEmpty()) {
        printf("Stack is underflow.\n");
        return 0;
    }
    else {
        ele = stack[top];
        top--;
    }
    return top;
}

//Get the top element of stack
int peek() {
    if(isEmpty()) {
        return 0;
    }
    else {
        return stack[top];
    }
}

//Traversing the stack
void traverse() {
    int i;

    if(isEmpty()) {
        printf("No element in the stack.\n");
    }
    else {
        printf("Stack elements are: \n");
        for(i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main()
{
    int ch, n;

    printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Traverse\n");
        printf("5.Quit\n");

    while(1) {
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch) {
            case 1: printf("Enter element to push: ");
                    int ele;
                    scanf("%d", &ele);
                    push(ele);
                    break;

            case 2: pop();
                    break;

            case 3: n = peek();
                    if(n == 0) {
                        printf("Stack is empty.\n");
                    }
                    else {
                        printf("Top item of the stack is: %d\n", n);
                    }
                    break;

            case 4: traverse();
                    break;

            case 5: exit(0);
                    break;

            default: printf("Invalid Input.\n");
        }
    }
    return 0;
}
