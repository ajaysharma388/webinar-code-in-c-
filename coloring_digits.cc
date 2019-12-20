#include <iostream>
using namespace std;

const int digits = 10; //0-9
const int N = 200001;

char str[N];
char sol[N];

int len;
// 67398
// x = 5 => 22122 => 12222 => 36798
bool seqposs(char end1, char end2){
    // 914 ; x = 5;
    char start2 = end2;
    for(int i=0; i<len; i++){
        if(str[i] >= end2 ){
            sol[i] = '2';
            end2 = str[i];
        }
        else if(str[i] >= end1){
            sol[i] = '1';
            end1 = str[i];
        }
        else{
            return false;
        }
    }

    if(end1 > start2){
        return false;
    }
    sol[len] = '\0';
    cout<<sol<<endl;
    return true;
}

void colour(){
    cin>>len;
    cin>>str;
    for(int i=0; i<digits; i++){
        if(seqposs('0', '0'+i)){
            return ;
        }
    }
    cout<<"-"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        colour();
    }
}