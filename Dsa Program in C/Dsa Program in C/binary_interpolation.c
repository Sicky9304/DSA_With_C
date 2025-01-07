#include<stdio.h>

int interpolationSearch(int a[], int size, int target);
int binarySearch(int a[], int size, int target);

// Interpolation search
int interpolationSearch(int a[], int target, int size) {
    int lo = 0, hi = size - 1, pos, it = 0;
    while (lo <= hi) {
        it++;
        pos = lo + ((target - a[lo]) / (a[hi] - a[lo])) * (hi - lo);
        if (a[pos] == target) {
            printf("%d found at the location %d after %d iterations.\n", target, pos + 1, it);
            return pos;
        } else if (a[pos] > target)
            hi = pos - 1;
        else
            lo = pos + 1;
    }
    printf("%d is not present in the array. Total iterations: %d.\n", target, it);
    return -1;
}

// Binary search
int binarySearch(int a[], int size, int target) {
    int lo = 0, hi = size - 1, mid, it = 0;
    while (lo <= hi) {
        it++;
        mid = (lo + hi) / 2;
        if (a[mid] == target) {
            printf("%d found at the location %d after %d iterations.\n", target, mid + 1, it);
            return mid;
        } else if (a[mid] > target) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    printf("%d is not present in the array. Total iterations: %d.\n", target, it);
    return -1;
}

int main() {
    int n, i, target, choice;
    
    while (1) {
        printf("Choose the search method \n1 for Binary Search,\n2 for Interpolation Search,\n3 for Exit: ");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);

        if (choice == 3) {
            return 0;
        }
        
        if (choice < 1 || choice > 3) {
            printf("Invalid choice\n");
            continue;
        }
        
        printf("Enter the size of the array: ");
        scanf("%d", &n);
        
        int arr[n];
        
        printf("Enter the elements in a sorted manner: \n");
        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        
        printf("Enter the target element: ");
        scanf("%d", &target);
            
        switch (choice) {
            case 1:
                binarySearch(arr, n, target);
                break;
            case 2:
                interpolationSearch(arr, target, n);
                break;
        }
    }

    return 0;
}

