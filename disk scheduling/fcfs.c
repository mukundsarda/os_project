#include <stdio.h>
#include <stdlib.h>

int calculate(int arr[], int n, int head) {
    int total = 0;
    int currentHead = head;

    for (int i = 0; i < n; i++) {
        total += abs(arr[i] - currentHead);
        currentHead = arr[i];
    }

    return total;
}

void prints(int arr[], int n, int head) {
    printf("Movement Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        printf(" -> %d", arr[i]);
    }

    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the disk request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int head;
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    int total = calculate(arr, n, head);

    printf("Total Head Movement: %d\n", total);

    prints(arr, n, head);

    return 0;
}
