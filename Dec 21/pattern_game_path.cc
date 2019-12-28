#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

void stairUp(char**arr,int row,int col,int step,int cen){
	vector<int> rowNo;
	vector<int> vertical;
	vector<int> horizontal;
	int i=0;int j=step;
	while(j){
		rowNo.push_back(j);
		vertical.push_back(i);
		j--;
		i+=2;
	}	
	for(int k=0;k<vertical.size();++k){
		horizontal.push_back(vertical[k]+1);
	}
	for(int k=0;k<rowNo.size();++k){
		arr[rowNo[k]][vertical[k]] = '|';
		arr[rowNo[k]-1][horizontal[k]] = '_';
	}
	i = horizontal[horizontal.size()-1]+1;
	while(cen){
		arr[0][i] = '_';
		i++;
		cen--;
	}
	vertical.clear();
	horizontal.clear();
	rowNo.clear();
	j=0;
	if(i%2==0){
		while(i<col){
			if(i&1){
				arr[j][i] = '|';
			}else{
				arr[j][i] = '_';
				j++;
			}
			i++;
		}
	}else{
		while(i<col){
			if(i%2==0){
				arr[j][i] = '|';
			}else{
				arr[j][i] = '_';
				j++;
			}
			i++;
		}
	}
	return;
}

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int l,c,r;
		r = n%10;
		n /= 10;
		c = n%10;
		n /= 10;
		l = n%10;
		int row = max(r,l)+1;
		int col = 2*(r+l)+c;
		char **arr = new char*[row];
		for(int i=0;i<row;++i){
			arr[i] = new char[col];
		}
		for(int i=0 ; i<row ; ++i){
			for(int j=0 ; j<col ; ++j){
				arr[i][j] = ' ';
			}
		}
		stairUp(arr,row,col,l,c);
		for(int i=0 ; i<row ; ++i){
			for(int j=0 ; j<col ; ++j){
				cout<<arr[i][j];
			}
			cout<<endl;
		} 	
		for(int i=0;i<row;++i){
			delete []arr[i];
		}
		delete []arr;
		cout<<endl<<endl;
	}
	return 0;
}