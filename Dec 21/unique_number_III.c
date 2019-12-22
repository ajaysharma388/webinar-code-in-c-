#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int
#define endl "\n"

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int A[64];
	memset(A,0,sizeof(A));
	while(n--){
		int num;
		cin >> num;
		int i=0;
		while(num){
			if(num&1){
				A[i]++;
			}
			i++;
			num>>=1;
		}
	}
	ll pow=1;
	ll res=0;
	for(int i=0;i<64;++i){
		A[i] = A[i]%3;
		res=res+(pow*A[i]);
		pow<<=1;
	}
	cout<<res<<endl;
	return 0;
}