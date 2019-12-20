#include <iostream>
using namespace std;
int main() {
    int N;
    cin>>N;
    int arr[N] = {0};
    int num = N, i=0;
    while(num--){
        cin>>arr[i];
        i++;
    }
    int maxlen =0;
    for(i=0;i<N;i++){
        int len =0;
        if(arr[i] != -1){ //not visited
            len+=1;
            int temp =arr[i];
            arr[i]=-1;
            while(arr[temp]!= -1){ // traversing the loop from current index
                len+=1;
                int num = arr[temp];
                arr[temp] = -1;
                temp = arr[num];
            }
        }
        maxlen = max(maxlen, len);
    }
    cout<<maxlen<<endl;
}