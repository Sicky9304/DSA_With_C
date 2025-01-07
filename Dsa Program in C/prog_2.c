#include <stdio.h>
int stack[5], top = -1, n = 5;

void push()
{
    int x;
    if (top >= n - 1)
    {
        printf("\nStack is OverFlow.\n");
    }
    else
    {
        printf("\nEnter a value to be pushed: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("\nElements %d pushed into the Stack\n", x);
    }
}

void pop()
{
    if (top <= -1)
    {
        printf("Stack is Underflow.\n");
    }
    else
    {
        printf("\nPopped elements is %d:\n", stack[top]);
        top--;
    }
}

void display()
{
    int i;
    if (top >= 0)
    {
        printf("Stack Elements Are: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
    else
    {
        printf("\nStack is Empty\n");
    }
}

int main()
{
    int choice;
    printf("Max Stack Size is 5\n");

    printf("Perform Stack Operation Using Array: \n");
    printf("1. PUSH\n2. POP\n3. DISPLAY\n4. EXIT\n");

    while (1)
    {
        /* code */
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid Choice...||Please Try Again. \n");
            continue;
        }
    }
}