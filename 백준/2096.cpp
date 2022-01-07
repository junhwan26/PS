#include<iostream>
using namespace std;
         
int M[3], m[3];
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int tmp0,tmp1,tmp2,a,b,c;
        cin>>tmp0>>tmp1>>tmp2;
        
        
        
        a = max(M[0],M[1])+tmp0;
        b = max( max(M[0],M[1]), M[2]) +tmp1;
        c = max(M[1],M[2])+tmp2;
        
        M[0] = a;
        M[1] = b;
        M[2] = c;
          
        a = min(m[0],m[1])+tmp0;
        b = min( min(m[0],m[1]), m[2]) +tmp1;
        c = min(m[1],m[2])+tmp2;
        
        m[0] = a;
        m[1] = b;
        m[2] = c;
          
          
    }
    
    cout<<max(M[0],max(M[1],M[2]))<<" "<< min(m[0],min(m[1],m[2]));
}
