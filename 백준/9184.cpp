#include<iostream>
using namespace std;

int dp[103][103][103];

int w(int a, int b, int c){
    //cout<<a<<" "<<b<<" "<<c<<"\n";
    if(dp[a][b][c])
        return dp[a][b][c];
    
    if( a <= 50 || b <= 50 || c <= 50)
        return dp[a][b][c] = 1;
    
    
    if( a > 70 || b > 70 || c > 70 )
        return dp[a][b][c] = w(70,70,70);
    
    if(a < b && b < c)
        return  dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    
        
    return dp[a][b][c] =  w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    
}

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    while( a != -1 || b != -1 || c != -1){
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<w(a+50,b+50,c+50)<<"\n";
        cin>>a>>b>>c;
    }
}
