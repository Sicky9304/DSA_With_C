# include<stdio.h>
# include <stdlib.h>
# define MAX 5

int queue[MAX],rear =-1,front = -1;

void enqueue(){
    if(rear == MAX-1){
        printf("Queue is Full.\n");
    }
    else{
        int num;
        printf("Enter the Elements to be Enqueue: ");
        scanf("%d",&num);
        if(front == -1){
            front = 0;
        }
        queue[++rear] = num;
        printf("%d Enqueue In the Queue rear\n",queue[rear]);
    }
}

void Dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is Empty\n");
    }
    else{
        printf("%d Dequeued from Queue front\n",queue[front++]);
    }
}

void display(){
    if (front == -1 || front > rear){
        printf("Queue is Empty\n");
    }
    else{
        int i;
        printf("Queue Elements are :\n");
        for(i = front; i <= rear; i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }  
}

int main(){
    while (1){
        int choice;
        printf("\nMax Queue Size is 5 Perform Operation\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            Dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Exiting..\n");
            return 0;
    
        default:
            printf("Invalid Choice || Please Try Again..\n");
            continue;
        }
    }
    
}