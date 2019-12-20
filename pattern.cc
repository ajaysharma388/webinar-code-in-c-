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
	bool data=true;
	int n;
	cin >> n;
	for(int i=0;i<n;++i){
		data = (i&1)?true:false;
		for(int j=0;j<=i;++j){
			cout<<data;
			data=!data;
		}
		cout<<endl;
	}	
	return 0;
}

// Sample Input :

// 7

// Sample Output :

// 0
// 10
// 010
// 1010
// 01010
// 101010
// 0101010