#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int t =n;
    long double arr[n], temp[n][2];// 0th col for floor & 1st col for ceil
    int i=0;
    while(t--){
        cin>>arr[i];
        i++;
    }
    for(i=0; i<n;i++){
        temp[i][0] = floor(arr[i]);
        temp[i][1]= ceil(arr[i]);
        if( temp[i][0] == -0){
             temp[i][0] =0;
        }
        if( temp[i][1] == -0){
             temp[i][1] =0;
        }
    }
    int floorsum =0;
    for(i=0; i<n; i++){
        floorsum += temp[i][0];
    //  floorsum += floor(arr[i]);
    }
     for(i=0; i<n; i++){
         if(floorsum <0){
             cout<<temp[i][1]<<" ";
             floorsum += (temp[i][1] - temp[i][0]);
             //floorsum += (ceil(arr[i]) - floor(arr[i]));
         }
         else{
             cout<<temp[i][0]<<" ";
         }
    }
    return 0;
}