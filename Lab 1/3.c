// Insertion Sort, User Input

#include <stdio.h>

int main() {
    int n,i,j,k;

    printf("Enter number of elements: ");
    scanf("%d", &n);

int arr[n];

for(i=0; i<n;i++){
    printf("Enter the element: ");
    scanf("%d", &arr[i]);
}

for(i=1; i<n; i++){
    k=arr[i];
    j=i-1;

    while(j>=0 && arr[i]>k){
        arr[j+1]=arr[j];
        j=j-1;
    }
    arr[j+1]=k;
}
printf("Therefore, the sorted array is:");
for(i=0;i<n;i++){
    printf("%d", arr[i]);
}
return 0;
}