#include <stdio.h>
#include <time.h>

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start = clock();  

    for(int i = 1; i <= n; i++) {
        printf("UPES\n");
    }

    clock_t end = clock();    

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Execution time = %f seconds\n", time_taken);
    printf("Time Complexity = O(n)\n");

    return 0;
}