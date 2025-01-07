# include<stdio.h>
# include<stdlib.h>
# define N 5

int cQueue[N], rear = -1, front = -1;

void cenQueue(int x){
    if(front == -1 && rear == -1){
        front = rear = 0;
        cQueue[rear] = x;
        printf("%d Enqueued into the Queue\n",cQueue[rear]);
    }
    else if((rear+1)%N == front){
        printf("Queue is Full\n");
    }
    else{
        rear = (rear+1)%N;
        cQueue[rear] = x;
        printf("%d Enqueued into the Queue\n",cQueue[rear]);
    }
}

void cdelQueue(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else if(front == rear){
        printf("%d Dequeued from the Queue\n",cQueue[front]);
        front = rear = -1;
    }
    else{
        printf("%d Dequeued from the Queue\n",cQueue[front]);
        front = (front+1)%N;
    }
}
void display(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty\n");
    }
    else{
        int i = front;
        printf("Queue Elements are:\n");
        while(i != rear){
            printf("%d ",cQueue[i]);
            i = (i+1)%N;
        }
        printf("%d ",cQueue[rear]);
    }
}

int main(){
    int choice,x;
    while(1){
        printf("\n1. cenQueue\n2. cdelQueue\n3. Display\n4. Exit\nEnter the Choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1:
            printf("Enter the Elements to be Enqueued: ");
            scanf("%d",&x);
            cenQueue(x);
            break;
        
        case 2:
            cdelQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting the Program..\n");
            return 0;
            break;
        default:
            printf("Invalid Choice. || Please try Again..\n");
            continue;
        }
    }
}