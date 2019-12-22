#include <stdio.h>
int main(){
	int a,b,t;
	scanf("%d",&t);
	while(t--){
		unsigned long long int res=1;
		// we are trying to calculate the A^B using fast exponentiation.
		// Time Complexity is O(log N).
		scanf("%d %d",&a,&b);
		while(b){
			if(b&1){
				res*=a;
			}
			a*=a;
			b>>=1;
		}
		printf("%d\n",res);
	}
}