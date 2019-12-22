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
		prod*=a[i];
	}
	int result = floor(num/prod);
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
		result+=genSubsets(i,a,num);
	}
	printf("%d\n", result);
	return 0;
}