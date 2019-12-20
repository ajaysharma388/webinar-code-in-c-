#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testcases;
	cin >> testcases;
	while(testcases--){
		int n,msb=5;
		cin >> n;
		float num=0,inc=1;
		while(msb && num*num!=n){
			num+=inc;
			if(num*num>n){
				num-=inc;
				inc/=10.0;
				msb--;
			}
		}
		cout<<n<<" : "<<num<<endl;
	}
	return 0;
}

// Sample Input :

// 5
// 10 
// 32 
// 36
// 89
// 96

// Sample Output :

// 10 : 3.16221
// 32 : 5.65681
// 36 : 6
// 89 : 9.43391
// 96 : 9.79792