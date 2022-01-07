#include<iostream>
using namespace std;

int in[100000];

int main(){
    int N,S;
    cin>>N>>S;
    
    int ans = 987654321;
    
    for(int i=0;i<N;i++)
        cin>>in[i];
    
    int s = 0, e = 0;
    int tmp = in[e];
    while(s<N){
        //cout<<s<<" "<<e<<endl;
        if(tmp>=S){
            ans = min(ans, e-s+1);
            tmp-=in[s];
            s++;
        }
        else{
            if(e<N){
                e++;
                tmp+=in[e];
            }
            else{
                tmp-=in[s];
                s++;
            }
        }
        
    }
    if(ans == 987654321)
        cout<<0;
    else
        cout<<ans;
    
}
