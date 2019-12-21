#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

bool isOdd(const int num){
	return (num&1);
}

int getithBit(const int num,const int i){
	int mask=(1<<i);
	return (num&mask)>0?1:0;
}

int setithBit(const int num,const int i){
	int mask=(1<<i);
	return (num|mask);
}

int clearIthBit(const int n,const int i){
	int mask = ~(i<<1);
	return (n&mask);
}

int updateBit(const int n,const int i,const int v){
	int mask = (1<<i);
	if(v) return n | mask;
	return n-mask;
}

int clearLastIbits(const int num,const int i){
	int mask = (-1<<i);
	return (num & mask);
}

int clearLastItoJbits(const int num,const int i,const int j){
	int mask =(~0)<<(j+1);
	int data = (1<<i)-1;
	mask|=data;
	return (num & mask); //exclusive (j,i) bits.
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	cin >> n >> i >> j;
	cout<<"Result is : "<<clearLastItoJbits(n,i,j)<<endl;
	
	// if(isOdd(n)){
	// 	cout<<"Odd Number : "<<n<<endl;
	// }else{
	// 	cout<<"Even Number : "<<n<<endl;
	// }
	// cin >> i;
	// n = updateBit(5,2,0);
	// n = updateBit(n,3,1);
	// cout<<"Updated Bit : "<<n<<endl;

	return 0;
}