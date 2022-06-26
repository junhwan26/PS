#include<iostream>
using namespace std;
int idx;
long long arr[1000001];

void f(long long a){
    for(int i=0; i<a%10 ; i++){
        arr[idx++] = a*10+i;
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<10;i++){
        arr[i] = i;
    }
    idx=10;
    for(int i=1; idx<=N && arr[i]<=987654321; i++){
        f(arr[i]);
    }
    if(arr[N] == 0 && N!=0)
        cout<<-1;
    else
        cout<<arr[N];
}
