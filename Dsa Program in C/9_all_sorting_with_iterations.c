#include <stdio.h>

void bubbleSort(int a[], int n, int *iterations) {
    int i, j, temp;
    for (i = n; i > 0; i--) {
        for (j = 0; j < i - 1; j++) {
            (*iterations)++;
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int a[], int n, int *iterations) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;
        (*iterations)++;
        while (j >= 0 && a[j] > key) {
            (*iterations)++;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void selectionSort(int a[], int n, int *iterations) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        (*iterations)++;
        for (j = i + 1; j < n; j++) {
            (*iterations)++;
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
}

// Merges two subarrays into the main array
void merge(int a[], int leftArray[], int ls, int rightArray[], int rs, int *iterations) {
    int i = 0, j = 0, k = 0;
    while (i < ls && j < rs) {
        (*iterations)++;
        if (leftArray[i] <= rightArray[j]) {
            a[k++] = leftArray[i++];
        } else {
            a[k++] = rightArray[j++];
        }
    }
    while (i < ls) {
        (*iterations)++;
        a[k++] = leftArray[i++];
    }
    while (j < rs) {
        (*iterations)++;
        a[k++] = rightArray[j++];
    }
}

void mergeSort(int a[], int n, int *iterations) {
    if (n < 2)
        return;

    int ls = n / 2;
    int rs = n - ls;

    int leftArray[ls], rightArray[rs], i;

    for (i = 0; i < ls; i++) {
        (*iterations)++;
        leftArray[i] = a[i];
    }
    for (i = ls; i < n; i++) {
        (*iterations)++;
        rightArray[i - ls] = a[i];
    }

    mergeSort(leftArray, ls, iterations);
    mergeSort(rightArray, rs, iterations);
    merge(a, leftArray, ls, rightArray, rs, iterations);
}

void quickSort(int a[], int low, int high, int *iterations) {
    if (low < high) {
        int pivot = a[high];
        int i = low - 1, temp;

        for (int j = low; j <= high - 1; j++) {
            (*iterations)++;
            if (a[j] < pivot) {
                ++i;
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[i + 1];
        a[i + 1] = a[high];
        a[high] = temp;

        quickSort(a, low, i, iterations);
        quickSort(a, i + 2, high, iterations);
    }
}

void display(int a[], int n, int iterations) {
    int i;
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nIteration count = %d\n", iterations);
}

int main() {
    int n, i;
    int choice;

    while (1) {
        printf("Welcome to Sorting Program\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 6) {
            printf("   Thank You...\n");
            return 0;
        }

        if (choice >= 1 && choice <= 5) {
            printf("Enter the size of the array: ");
            scanf("%d", &n);
            int a[n];
            int iterations = 0;

            printf("Enter %d integers:\n", n);
            for (i = 0; i < n; i++) {
                scanf("%d", &a[i]);
            }

            switch (choice) {
                case 1:
                    printf("\nWelcome to Bubble Sort\n");
                    bubbleSort(a, n, &iterations);
                    display(a, n, iterations);
                    break;
                case 2:
                    printf("\nWelcome to Insertion Sort\n");
                    insertionSort(a, n, &iterations);
                    display(a, n, iterations);
                    break;
                case 3:
                    printf("\nWelcome to Selection Sort\n");
                    selectionSort(a, n, &iterations);
                    display(a, n, iterations);
                    break;
                case 4:
                    printf("\nWelcome to Merge Sort\n");
                    mergeSort(a, n, &iterations);
                    display(a, n, iterations);
                    break;
                case 5:
                    printf("\nWelcome to Quick Sort\n");
                    quickSort(a, 0, n - 1, &iterations);
                    display(a, n, iterations);
                    break;
            }
            printf("\n");
        } else {
            printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}
