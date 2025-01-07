#include <stdio.h>
#include <stdlib.h>
int count = 0;
struct node{
    int data;
    struct node *next;
};

struct node *head = NULL, *newnode, *temp;

void insert_at_beginning(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data to insert at start: ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
}

void insert_at_end(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data to insert at end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL){
    	temp = temp->next;
	}
	temp->next = newnode;
	
}

void insert_at_position(int pos){
    int i=1;
    if(pos>count || pos < 1){
        printf("Invalid Position..");
        return;
    }
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter the Elements to insert at pos: ");
    scanf("%d",&newnode->data);
    
    else if(pos == 1) {
        newnode->next = head;
        head = newnode;
    }
    else{
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void traverse_list(){
    struct node *temp = head;
    count = 0;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL");
    printf("\nTotal Node Count: %d",count);
}

int main(){
    int choice, pos;
    
    while(1){
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Display List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                insert_at_beginning();
                break;
            case 2:
                insert_at_end();
                break;
            case 3:
                printf("Enter the Position: ");
                scanf("%d", &pos);
                insert_at_position(pos);
                break;
            case 4:
                traverse_list();
                break;
            case 5:
                printf("exiting..");
                return 0;
            default:
                printf("Invalid Choice!\n");
                continue;
        }
    }
}

