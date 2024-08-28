#include <stdio.h>
#define MAXSIZE 10  

int queue[MAXSIZE];
int front = -1, rear = -1; 


void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    do {
        printf("\n---- Queue Operations ----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}


void enqueue() {
    if (rear == MAXSIZE - 1) {
        printf("Queue overflow! Cannot enqueue more elements.\n");
    } else {
        int value;
        printf("Enter value to enqueue: ");
        scanf("%d", &value);

        if (front == -1) { 
            front = 0;
        }
        queue[++rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}


void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow! No elements to dequeue.\n");
    } else {
        printf("Dequeued %d from the queue.\n", queue[front++]);

        if (front > rear) {  
            front = rear = -1;
        }
    }
}


void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Current queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
