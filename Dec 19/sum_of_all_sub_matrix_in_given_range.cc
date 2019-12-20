#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// prototype declaration of function.
int sumOfSubMatrix(int**,int,int,int,int);

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,n;
	cin >> m >> n;
	int **a = new int*[m];
	for(int i=0;i<m;++i){
		a[i] = new int[n];
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cin >> a[i][j];
		}
	}	
	for(int i=0;i<m;++i){
		ll sum=0;
		for(int j=0;j<n;++j){
			sum+=a[i][j];
			a[i][j]=sum;
		}
	}
	for(int j=0;j<m;++j){
		ll sum=0;
		for(int i=0;i<n;++i){
			sum+=a[i][j];
			a[i][j]=sum;
		}
	}
	for(int j=0;j<m;++j){
		for(int i=0;i<n;++i){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	int q;
	cin>>q;
	while(q--){
		int s,e,u,l;
		cin >> s >> e >> u >> l;
		// Function call.
		cout<<"Sum is : "<<sumOfSubMatrix(a,s,e,u,l)<<endl;
	}
	for(int i=0;i<m;++i){
		delete []a[i];
	}
	delete []a;
	return 0;
}

// Function Defination.
int sumOfSubMatrix(int **a,int s,int e,int u,int l){
	if(s>0 and u>0)	return a[e][l]+a[s-1][u-1]-a[e][u-1]-a[s-1][l];
	else if(u==0 and s!=0)	return a[l][e]-a[l][s-1];
	else if(s==0 and u!=0)	return a[l][e]-a[u-1][e];
	else return a[l][e];
}

// Question : We are supposed to answer the Q queries of the user to find the 
// Sum of matrix in the given range.

// Sample Input :

// 4 4
// 1 1 1 1 
// 1 1 1 1
// 1 1 1 1
// 1 1 1 1
// 3
// 0 3 0 3
// 1 3 0 2
// 1 3 1 3

// 4 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// 3
// 0 3 0 3
// 1 3 0 2
// 1 3 1 3

// Sample Output :

// 1 2 3 4 
// 2 4 6 8 
// 3 6 9 12 
// 4 8 12 16 
// Sum is : 16
// Sum is : 9
// Sum is : 9

// 1 3 6 10 
// 3 9 18 30 
// 6 18 36 60 
// 10 30 60 100 
// Sum is : 100
// Sum is : 54
// Sum is : 81