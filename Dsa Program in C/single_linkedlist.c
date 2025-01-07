#include <stdio.h>
#include <stdlib.h>
void main(){
	int pos,i=1;
    struct node{
        int data;
        struct node *next;
    };
    
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;
    int count = 0;

    while(choice){
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;

        if(head == NULL){
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to create a new node? (0/1): ");
        scanf("%d",&choice);
    }
    temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
	
	// insert New Node At Begineening	
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter data you want to insert: ");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
	
	// Traverse the linked list
	temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
//        count++;
    }
//    Insert a New Node At End
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter Data to insert at end: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    temp = head;
    while(temp->next != NULL){
    	temp = temp->next;
	}
	temp->next = newnode;
	
	// Traverse the linked list
	temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
    //    Insert a New Node At Given Position
    printf("\nEnter the Position: ");
    scanf("%d",&pos);
    if(pos>count){
    	printf("Invalid Position..");
	}
	else{
		temp = head;
		while(i<pos){
			temp = temp->next;
			i++;
		}
  		newnode = (struct node*)malloc(sizeof(struct node));
  		printf("Enter the Elements to insert at pos: ");
  		scanf("%d",&newnode->data);
  		newnode->next = temp->next;
  		temp->next = newnode;
	}
		// Traverse the linked list
	temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
        count++;
    }
 	printf("\nTotal Node: %d",count);
}

