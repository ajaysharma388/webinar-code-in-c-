#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,xor=0;
    scanf("%d",&n);
    int *a = (int*) malloc(n * sizeof(int));
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        xor^=a[i];
    }
    printf("Unique Number is %d",xor);
    free(a);
    return 0;
}

// Sample Input : 

// 7
// 5 1 2 3 5 2 1 

// Sample Output :

// Unique Number is 3