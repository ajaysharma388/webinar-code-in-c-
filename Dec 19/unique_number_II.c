#include<stdio.h>
#include<stdlib.h>

int main(){
	int n,xor=0,pos=0,x,y;
	scanf("%d",&n);
	int *a = (int*) malloc(n * sizeof(int));
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
        xor^=a[i];
	}
    x=xor;
    while((x&1)!=1){
        pos++;
        x>>=1;
    }
    for(int i=0;i<n;++i){
        printf("%d ",a[i]);
	}
    x = 0;
    y = 1<<pos;
    printf("\n%d ",y);
	for(int i=0;i<n;++i){
		if((a[i]&y)==0){
            x^=a[i];
        }
	}
    y = xor^x;
    printf("Unique Number's are %d and %d\n",x,y);

	return 0;
}

// Sample Input : 

// 8
// 5 1 2 3 5 7 2 1 

// Sample Output :

// 4 Unique Number's are 3 and 7