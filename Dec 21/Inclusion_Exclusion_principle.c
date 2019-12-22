#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int genSubsets(int n,int *arr,int num){
	int a[100];
	int j=0,k=0,prod=1;
	while(n){
		if(n&1){
			a[j] = arr[k];
			j++; 
		}
		k++;
		n>>=1;
	}
	for(int i=0;i<j;++i){
		printf("%d ", a[i]);
		prod*=a[i];
	}
	int result = floor(num/prod);
	printf(": %d \n",result);
	return (j&1)? result : (-1)*result;
}

int main(int argc, char const *argv[]){
	int n,num,result=0;
	scanf("%d %d",&n,&num);
	int *a = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<(1<<n);++i){
		result+=genSubsets(i,a,num-1);
	}
	printf("Result is : %d\n", result);
	return 0;
}

// Sample Input :

// 3 1000
// 2 3 5

// Sample Output :

// 2 : 499
// 3 : 333
// 2 3 : 166
// 5 : 199
// 2 5 : 99
// 3 5 : 66
// 2 3 5 : 33
// Result is : 733