#include <stdio.h>
int main() {
    int n, i, id, low, high, mid;
    int comparisons = 0;
    int found = 0;
    printf("Enter number of employees: ");
    scanf("%d", &n);
    int empID[n];
    printf("Enter employee IDs in ascending order:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &empID[i]);
    }
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        comparisons++;
        if (empID[mid] == id) {
            printf("Employee ID %d found at position %d\n", id, mid + 1);
            found = 1;
            break;
        }
        else if (id < empID[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if (!found) {
        printf("Employee ID %d is absent\n", id);
    }
    printf("Number of comparisons = %d\n", comparisons);
    return 0;
}
