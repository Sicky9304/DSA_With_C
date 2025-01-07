#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX], front = -1, rear = -1;

void insert()
{
    if (rear == MAX - 1)
        printf("\nQueue is Full!\n");
    else
    {
        int num;
        printf("\nEnter a number to insert: ");
        scanf("%d", &num);
        if (front == -1) front = 0;
        queue[++rear] = num;
    }
}

void delete()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty!\n");
    else
        printf("\n%d was deleted!\n", queue[front++]);
}

void display()
{
    if (front == -1 || front > rear)
        printf("\nQueue is Empty!\n");
    else
    {
        printf("\nQueue contents: ");
        for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
        printf("\n");
    }
}

int main()
{
    while (1)
    {
        int choice;
        printf("\n1. Insert\n2. Delete\n3. Display\n4. EXIT\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: insert(); break;
        case 2: delete(); break;
        case 3: display(); break;
        case 4: exit(0);
        default: printf("\nInvalid Choice!\n");
        }
    }
    return 0;
}