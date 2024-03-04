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

int start(int arr[], int n, int head, char direction) {
    if (direction == 'r') {
        for (int i = 0; i < n; i++) {
            if (arr[i] >= head) {
                return i;
            }
        }
    } else if (direction == 'l') {
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] <= head) {
                return i;
            }
        }
    }
    return n;
}

void look(int arr[], int n, int head, char direction, int disk_size) {
    int total_head_movement = 0;
    int starting_index;

    sort(arr, n);

    starting_index = start(arr, n, head, direction);

    printf("Movement Sequence: \n");

    if (direction == 'r') {
        for (int i = starting_index; i < n; i++) {
            if (arr[i] < disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }

        for (int i = starting_index - 1; i >= 0; i--) {
            if (arr[i] >= 0) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }
    }

    else if (direction == 'l') {
        for (int i = starting_index; i >= 0; i--) {
            if (arr[i] >= 0) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }

        for (int i = starting_index + 1; i < n; i++) {
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

    look(arr, n, head, direction, disk_size);

    return 0;
}
