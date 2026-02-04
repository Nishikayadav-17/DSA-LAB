#include <stdio.h>

int main() {
    int n, k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key that is to be searched: ");
    scanf("%d", &k);

    int comparisons = 0;
    int found = -1;

    for(int i = 0; i < n; i++) {
        comparisons++;

        if(arr[i] == k) {
            found = i;
            break;
        }
    }

    if(found != -1)
        printf("Key found at index %d\n", found);
    else
        printf("Key not found\n");

    printf("Number of comparisons = %d\n", comparisons);

    return 0;
}
