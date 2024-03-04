#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int calculate(int arr[], int n, int head) {
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

    return total;
}

void prints(int arr[], int n, int head) {
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
