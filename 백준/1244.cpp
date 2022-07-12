#include<iostream>
#include<vector>
using namespace std;

vector<int> v;


int main(){
    int n;
    cin>>n;
    v.push_back(-1);
    
    for(int i =0; i<n; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    
    
    int m;
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        if(a==1){
            for(int i =b; i<=n; i+=b)
                v[i] = !v[i];
        }
        else{
            int i=0;
            while(1){
                if(b-i <=0 || b+i >n || v[b+i] != v[b-i]){
                    i--;
                    break;
                }
                if(v[b+i] == v[b-i])
                    i++;
            }
            for(int j = b-i; j<=b+i; j++)
                v[j] = !v[j];
        }
        
    }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
        if(i%20==0)
            cout<<endl;
    }
    
}
