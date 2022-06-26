#include<iostream>
#include<algorithm>
using namespace std;
int arr[51];
int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; i++)
        cin>>arr[i];
    
    sort(arr, arr+N+1);

    
    int b,ans=0;
    
    cin>>b;
    
    for(int i=1; i<=N ;i++){
        if(arr[i] == b){
            break;
        }
        if(arr[i]>b){
            int left = arr[i-1]+1;
            int right = arr[i]-1;
            ans = right - left + (right - b )*(b-left);
            break;
        }
    }
    cout<<ans;
    
}
