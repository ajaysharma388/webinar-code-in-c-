#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

string roman[] = {"I","IV","V","IX","X","XL","L",
    					"XC","C","CD","D","CM","M"};
int value[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};

int bsearch(int num){
	int s=0,e=13;
	int res=INT_MIN;
	while(s<e){
		int m=(s+e)/2;
		if(num==value[m]){
			return m;
		}else if(num>value[m]){
			res=max(res,m);
			s=m+1;
		}else{
			e=m;
		}
	}
	return res;
}

string intToRoman(int num) {
	int n = bsearch(num);
	string s = "";
	while(num){
        if(value[n]<=num){
			while(value[n]<=num){
			    num-=value[n];
			    s+=roman[n];
		    }
		}
		n--;
	}
	return s;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int number,testCases;
	cin >> testCases;
	while(testCases--){
		cin >> number;
		cout<<intToRoman(number)<<endl;
	}
	return 0;
}

// Sample Input :

// 5
// 59
// 45
// 35
// 135
// 599

// Sample Output :

// LIX
// XLV
// XXXV
// CXXXV
// DXCIX