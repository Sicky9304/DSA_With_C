#include<stdio.h>

void bubbleSort(int a[],int n, int *iterations){
	int i,j,temp;
	for(i=n;i>0;i--){
		for(j=0;j<i-1;j++){
			(*iterations)++;
			if(a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}


// Function prototypes
void insertionSort(int a[],int n,int *iterations){
	int i,j,key;
for (i=1;i<n;i++){
	key = a[i];
	j = i-1;
	(*iterations)++;
	while(j>=0 && a[j] > key){
		(*iterations)++;
		a[j+1] = a[j];
		j = j-1;
	}
	a[j+1] = key;
}
}

void display(int a[], int n, int iterations){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	printf("Total Iterations = %d", iterations);
}

int main(){
	int i,n,choice;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int a[n];
	int iterations = 0;
	printf("Enter %d elements in the array:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	while(1){
		printf("\n1. Bubble Sort\n2. Insertion Sort\n3. Exit\nEnter the Choice: ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			bubbleSort(a,n,&iterations);
			printf("Sorted Array:\n");
			display(a,n,iterations);
			break;
		case 2:
			insertionSort(a,n,&iterations);
			printf("Sorted Array:\n");
			display(a,n,iterations);
			break;
		case 3:
			printf("Exiting..");
			return 0;
		default:
			printf("\nInvalid choice. || Please Try again..");
			continue;
		}
	}
}
