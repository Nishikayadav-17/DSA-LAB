#include <stdio.h>

int main() {
    int n, i, choice, element, index;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n + 1];  

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nChoose the type of insertion:\n");
    printf("Press 1 to insert at beginning\n");
    printf("Press 2 to insert at given index\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter element to be inserted at the beginning: ");
        scanf("%d", &element);

        for (i = n; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = element;
        n++;
    }
    else if (choice == 2) {
        printf("Enter index (0 to %d) in which you have to insert the element: ", n);
        scanf("%d", &index);

        printf("Enter element to insert: ");
        scanf("%d", &element);

        for (i = n; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        arr[index] = element;
        n++;
    }
    else {
        printf("Invalid choice");
        return 0;
    }

    printf("\nArray after insertion:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}