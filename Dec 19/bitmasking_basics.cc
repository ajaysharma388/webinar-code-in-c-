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

int replaceBits(int num,int data,int i,int j){
	int mask = (~0)<<j+1;
	mask|=((1<<i)-1);
	num = (num & mask);
	data<<=i;
	return num|data;
}

// O(log N) is the complexity of this method 
// to calculate the number of the set bits.
int countSetBits(int num){
	int ans = 0;
	while(num){
		ans+=(num&1);
		num>>=1;
	} 
	return ans;
}
// O(No. of set bits) is the complexity of this method 
// and in the worst case it might be O(log N) when all 
// bits all set.
int countSetBitsFast(int num){
	int ans = 0;
	while(num){
		num &= (num-1);
		ans++;
	} 
	return ans;
}

string printBinary(int num){
	string bin = "";
	while(num){
		bin+=(num & 1)?'1':'0';
		num>>=1;
	}
	reverse(bin.begin(), bin.end());
	return bin;
}

void printBinaryRec(int num){
	if(num==0) return;
	printBinaryRec(num>>1);
	int cur = (num&1)?1:0;
	cout<<cur;
} 

void theBinary(int num){
	cout<<endl<<num<<" : ";
	int p=1;
	int ans=0;
	while(num){
		ans+=p*((num&1)?1:0);
		p*=10;
		num>>=1;
	}
	cout<<ans<<endl;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n,i,j;
	cin >> m >> n >> i >> j;
	cout<<"Result is : "<<replaceBits(m,n,i,j)<<endl;
	cout<<57<<" : "<<countSetBits(57)<<endl;
	cout<<"Bits in -1 : "<<countSetBitsFast(-1)<<endl;
	cout<<"Binary Of 57 : "<<printBinary(57)<<endl;
	cout<<"set bits in 57 : "<<__builtin_popcount(57)<<endl; 
	// built in method for counting the number of set bits 
	// inside the binary reperesentation of the number.
	cout<<57<<" : ";
	printBinaryRec(57);
	theBinary(20);
	return 0;
}


// Sample Input :

// 15 2 1 3

// Sample Output :

// Result is : 5
// 57 : 4
// Bits in -1 : 32
// Binary Of 57 : 111001
// set bits in 57 : 4
// 57 : 111001
// 20 : 10100