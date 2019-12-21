#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

// prototype declaration of function.
int getMaxSumOfSubMatrix(int**,int,int);

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
	for(int j=n-1;j>=0;--j){
		ll sum=0;
		for(int i=m-1;i>=0;--i){
			sum+=a[i][j];
			a[i][j]=sum;
		}
	}
	for(int i=m-1;i>=0;--i){
		ll sum=0;
		for(int j=n-1;j>=0;--j){
			sum+=a[i][j];
			a[i][j]=sum;
		}
	}
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\nMaximum Sub Array Sum : "<<getMaxSumOfSubMatrix(a,m,n)<<endl;
	for(int i=0;i<m;++i){
		delete []a[i];
	}
	delete []a;
	return 0;
}

// Function Defination.
int getMaxSumOfSubMatrix(int **a,int m,int n){
	int data=INT_MIN;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			data = max(data,a[i][j]);
		}
	}
	return data;
}

// Question : We are supposed to answer the Q queries of the user to find the 
// Sum of matrix in the given range.

// Sample Input :

// 4 4
// -5 -3 2 6
// -4 7 8 12
// -1 14 22 29
// 4 16 24 54

// 3 3
// -5 -4 -1 
// -3 2 4
// -2 5 8

// Sample Output :

// 185 191 157 101 
// 185 186 149 95 
// 162 159 129 83 
// 98 94 78 54 

// Maximum Sub Array Sum : 191

// 4 14 11 
// 14 19 12 
// 11 13 8 

// Maximum Sub Array Sum : 19