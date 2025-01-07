#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int l = 0, h = n - 1;
    int iterations = 0; // Counter for iterations
    while (l <= h) {
        iterations++;
        int m = l + (h - l) / 2;
        if (arr[m] == target) {
            printf("Binary Search: Target %d found at index %d in %d iterations\n", target, m, iterations);
            return m;
        } else if (arr[m] < target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    printf("Binary Search: Target %d not found after %d iterations\n", target, iterations);
    return -1;
}

int interpolationSearch(int arr[], int n, int target) {
    int l = 0, h = n - 1;
    int iterations = 0; // Counter for iterations
    while (l <= h && target >= arr[l] && target <= arr[h]) {
        iterations++;
        int m = l + ((target - arr[l]) * (h - l)) / (arr[h] - arr[l]);
        if (arr[m] == target) {
            printf("Interpolation Search: Target %d found at index %d in %d iterations\n", target, m, iterations);
            return m;
        } else if (arr[m] < target) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    printf("Interpolation Search: Target %d not found after %d iterations\n", target, iterations);
    return -1;
}

void displayArray(int arr[], int n) {
    int i;
    printf("Array: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to get array input from user
void getInput(int arr[], int n) {
    int i;
    printf("Enter %d sorted integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    getInput(arr, n);

    int target;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display Array\n");
        printf("2. Binary Search\n");
        printf("3. Interpolation Search\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;
            case 2:
                printf("Enter target value: ");
                scanf("%d", &target);
                binarySearch(arr, n, target);
                break;
            case 3:
                printf("Enter target value: ");
                scanf("%d", &target);
                interpolationSearch(arr, n, target);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please choose again.\n");
        }
    }

    return 0;
}