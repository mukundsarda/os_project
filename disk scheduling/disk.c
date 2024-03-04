#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
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

//FCFS
void fcfscalculate(int arr[], int n, int head) {
    int total = 0;
    int currentHead = head;

    for (int i = 0; i < n; i++) {
        total += abs(arr[i] - currentHead);
        currentHead = arr[i];
    }
	printf("Total Head Movement: %d\n", total);
}

void fcfsprints(int arr[], int n, int head) {
    printf("Movement Sequence: %d", head);

    for (int i = 0; i < n; i++) {
        printf(" -> %d", arr[i]);
    }

    printf("\n");
}

//SSTF
int sstf(int arr[], int n, int currhead, int visited[]) {
    int minDistance = INT_MAX;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int distance = abs(arr[i] - currhead);
            if (distance < minDistance) {
                minDistance = distance;
                index = i;
            }
        }
    }
    return index;
}

void sstfcalculate(int arr[], int n, int head) {
    int total = 0;
    int currhead = head;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = sstf(arr, n, currhead, visited);
        visited[index] = 1;
        total += abs(arr[index] - currhead);
        currhead = arr[index];
    }
	printf("Total Head Movement: %d\n", total);
}

void sstfprints(int arr[], int n, int head) {
    printf("Movement Sequence: %d", head);

    int currhead = head;
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int index = sstf(arr, n, currhead, visited);
        visited[index] = 1;
        printf(" -> %d", arr[index]);
        currhead = arr[index];
    }

    printf("\n");
}

//SCAN
int scanstart(int arr[], int n, int head) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= head) {
            return i;
        }
    }
    return n;
}

void scan(int arr[], int n, int head, char direction, int disk_size) {
    int total_head_movement = 0;
    int starting_index;

    sort(arr, n);

    starting_index = scanstart(arr, n, head);

    printf("Movement Sequence: \n");

    if (direction == 'r') {
        for (int i = starting_index; i < n; i++) {
            if (arr[i] <= disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }
        printf("%d \n",disk_size-1);
        // Move to the rightmost end
        total_head_movement += abs(head - (disk_size-1));
        head = disk_size-1;

        // Move towards the left
        for (int i = starting_index - 1; i >= 0; i--) {
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
        printf("%d \n",0);
        total_head_movement += abs(head - 0);
        head = 0;

        for (int i = starting_index; i < n; i++) {
            if (arr[i] < disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }
    }

    printf("\nTotal Head Movement: %d\n", total_head_movement);
}

//CSCAN
void cscan(int arr[], int n, int head, char direction, int disk_size) {
    int total_head_movement = 0;
    int starting_index;

    sort(arr, n);

    starting_index = scanstart(arr, n, head);

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

//LOOK
int lookstart(int arr[], int n, int head, char direction) {
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

    starting_index = lookstart(arr, n, head, direction);

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

//CLOOK
void clook(int arr[], int n, int head, char direction, int disk_size) {
    int total_head_movement = 0;
    int starting_index;

    sort(arr, n);

    starting_index = lookstart(arr, n, head, direction);

    printf("Movement Sequence: \n");

    if (direction == 'r') {
        for (int i = starting_index; i < n; i++) {
            if (arr[i] < disk_size) {
                printf("%d \n", arr[i]);
                total_head_movement += abs(head - arr[i]);
                head = arr[i];
            }
        }

        for (int i = 0; i < starting_index; i++) {
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

        for (int i = n - 1; i > starting_index; i--) {
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
    int choice, n, head, disk_size;
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

    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    do {
        // Display menu
        printf("\nDisk Scheduling Algorithms Menu:\n");
        printf("1. SCAN\n");
        printf("2. CSCAN\n");
        printf("3. FCFS\n");
        printf("4. SSTF\n");
        printf("5. LOOK\n");
        printf("6. CLOOK\n");
        printf("7. Exit\n");

        // User input for choice
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);

        // Perform the selected disk scheduling algorithm
        switch (choice) {
            case 1:
                printf("\nEnter the movement direction (l for left, r for right): ");
                scanf(" %c", &direction);
                scan(arr, n, head, direction, disk_size);
                break;
            case 2:
                printf("\nEnter the movement direction (l for left, r for right): ");
                scanf(" %c", &direction);
                cscan(arr, n, head, direction, disk_size);
                break;
            case 3:
                fcfscalculate(arr, n, head);
				fcfsprints(arr, n, head);
                break;
            case 4:
                sstfcalculate(arr, n, head);
				sstfprints(arr, n, head);
                break;
            case 5:
                printf("\nEnter the movement direction (l for left, r for right): ");
                scanf(" %c", &direction);
                look(arr, n, head, direction, disk_size);
                break;
            case 6:
                printf("\nEnter the movement direction (l for left, r for right): ");
                scanf(" %c", &direction);
                clook(arr, n, head, direction, disk_size);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 7.\n");
        }

    } while (choice != 7);

    return 0;
}
