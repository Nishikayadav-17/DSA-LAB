#include <stdio.h>
#include <time.h>

void printHELLO(int n) {
    int i, j, k;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            for(k = 1; k <= 100; k++) {
                printf("HELLO \n");
            }
        }
    }
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    clock_t start = clock();  

    printHELLO(n);              

    clock_t end = clock();     

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution time = %f seconds\n", time_taken);
    printf("Time Complexity = O(n*n)\n");

    return 0;
}