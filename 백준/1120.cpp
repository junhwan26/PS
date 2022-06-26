#include<iostream>
#include<string>
using namespace std;

int main(){
    string a,b;
    cin>>b>>a;
    int ans = 999999;
    for(int i=0;i<=a.length()-b.length();i++){
        int cnt =0;
        for(int j=0;j<b.length();j++){
            if(a[i+j] != b[j])
                cnt++;
        }
        ans = min(ans, cnt);
    }
    cout<<ans;
}
