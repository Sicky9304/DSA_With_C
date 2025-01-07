#include <stdio.h>
int stack[5], choice, n, top, x, i;
void push(void);
void pop(void);
void display(void);
int main()
{
    top = -1;
    printf("\n Enter the size of STACK[MAX=5]:");
    scanf("%d", &n);
    printf("\n STACK OPERATIONS USING ARRAY");
    printf("\n 1.PUSH\n 2.POP\n 3.DISPLAY\n 4.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            printf("\n EXIT POINT \n");
            break;
        }
        default:
        {
            printf("\n Invalid Choice!, Show in Menu..\n");
        }
        }
    } while (choice != 4);
    return 0;
}
void push()
{
    if (top >= n-1)
    {
        printf("\n\tSTACK is over flow");
    }
    else
    {
        printf(" Enter a value to be pushed:");
        scanf("%d", &x);
        top++;
        printf("\n Element %d pushed into stack..\n", x);
        stack[top] = x;
    }
}
void pop()
{
    if (top <= -1)
    {
        printf("\n\t Stack is under flow");
    }
    else
    {
        printf("\n The popped elements is %d\n", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n The elements in STACK \n");
        for (i = top; i >= 0; i--)
            printf(" %d  ", stack[i]);
    }
    else
    {
        printf("\n The STACK is empty\n");
    }
}
