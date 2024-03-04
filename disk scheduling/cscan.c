#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int findStartingIndex(int arr[], int n, int head) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= head) {
            return i;
        }
    }
    return n;
}

void cscan(int arr[], int n, int head, char direction, int disk_size) {
    int total_head_movement = 0;
    int starting_index;

    sort(arr, n);

    starting_index = findStartingIndex(arr, n, head);

    printf("Movement Sequence: \n");

    if (direction == 'r') {
        for (int i = starting_index; i < n; i++) {
            if (arr[i] < disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }

        total_head_movement += abs(head - (disk_size-1));
        head = 0;
        printf("%d \n", disk_size-1);
        printf("%d \n", 0);
        total_head_movement += disk_size-1;

        for (int i = 0; i < starting_index; i++) {
            if (arr[i] >= 0) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }
    }

    else if (direction == 'l') {
        for (int i = starting_index - 1; i >= 0; i--) {
            if (arr[i] >= 0) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }

        total_head_movement += abs(head - 0);
        head = disk_size-1;
        printf("%d \n", 0);
        printf("%d \n", disk_size-1);
        total_head_movement += disk_size-1;

        for (int i = n - 1; i >= starting_index; i--) {
            if (arr[i] < disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }
    }

    printf("\nTotal Head Movement: %d\n", total_head_movement);
}

int main() {
    int n, head, disk_size;
    char direction;

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the request sequence:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Enter the movement direction (l for left, r for right): ");
    scanf(" %c", &direction);

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    cscan(arr, n, head, direction, disk_size);

    return 0;
}
