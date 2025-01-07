#include <stdio.h>
void display(int a[], int n)
{
	int i;
	printf("Array Elements are:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
int main()
{
	int i, j, n, temp;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	int a[n];
	printf("\nEnter the elements in the array: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	for (i = n; i > 0; i--)
	{
		for (j = 0; j < i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	display(a, n);
	return 0;
}
