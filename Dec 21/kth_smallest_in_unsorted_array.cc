#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl "\n"

class node{
public:
	int data;
	node*left;
	node*right;
	node(const int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

node* insertInBST(node*root,const int data){
	if(root == NULL) return new node(data);
	if(root->data >= data){
		root->left = insertInBST(root->left,data);
	} else {
		root->right = insertInBST(root->right,data);
	}
	return root;
}

node* build(vector<int> &arr,int n){
	node*root = NULL;
	for(int i = 0; i < n; ++i){
		root = insertInBST(root,arr[i]);
	}
	arr.clear();
	return root;
}

void inorder(node*root,vector<int> &arr){
	if(root == NULL) return;
	inorder(root->left,arr);
	arr.push_back(root->data);
	inorder(root->right,arr);
	return;
}

// this implementation uses extra space for finding the kth 
// smallest element that means we are storing the inorder
// traversal of the tree nodes. we can also find without
// storing the extra space;

int main(){
	#ifndef ONLINE_JUGDE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	freopen("error.txt","w",stderr);
	#endif	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; ++i){
		cin >> arr[i];
	}
	cin >> k;
	node*root = build(arr,n);
	inorder(root,arr);
	cout << arr[k-1] << endl;
	return 0;
}

// Sample Input :

// 7
// 4 6 2 1 3 5 7
// 3

// Sample Output :

// 3