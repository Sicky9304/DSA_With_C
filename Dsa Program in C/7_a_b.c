#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


#define MAX 5


void push(struct Node** top, int value, int* stackCount) {
    if (*stackCount >= MAX) {
        printf("Stack is full. Cannot push more elements.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    (*stackCount)++;
    printf("%d added to Stack.\n", value);
}


void pop(struct Node** top, int* stackCount) {
    if (*top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = *top;
    printf("%d removed from Stack.\n", temp->data);
    *top = (*top)->next;
    free(temp);
    (*stackCount)--;
}


void displayStack(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}


void enqueue(struct Node** front, struct Node** rear, int value, int* queueCount) {
    if (*queueCount >= MAX) {
        printf("Queue is full. Cannot add more elements.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
    }
    (*queueCount)++;
    printf("%d added to Queue.\n", value);
}


void dequeue(struct Node** front, struct Node** rear, int* queueCount) {
    if (*front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = *front;
    printf("%d removed from Queue.\n", temp->data);
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    (*queueCount)--;
}


void displayQueue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    while (front) {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

int main() {
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;

    int stackCount = 0;
    int queueCount = 0;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 7) {
            printf("Goodbye!\n");
            break;
        }

        switch (choice) {
        case 1:
            printf("Enter value to push to Stack: ");
            scanf("%d", &value);
            push(&stack, value, &stackCount);
            break;
        case 2:
            pop(&stack, &stackCount);
            break;
        case 3:
            displayStack(stack);
            break;
        case 4:
            printf("Enter value to add to Queue: ");
            scanf("%d", &value);
            enqueue(&queueFront, &queueRear, value, &queueCount);
            break;
        case 5:
            dequeue(&queueFront, &queueRear, &queueCount);
            break;
        case 6:
            displayQueue(queueFront);
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}