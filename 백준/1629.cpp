    #include<iostream>

    using namespace std;

    long long func(long long a, long long b, long long c){
        
        a%=c;
        if(b==1)
            return a;
        
        if(b%2)
            return a*func(a*a, b/2, c)%c;
        
        return func(a*a,b/2,c)%c;
    }

    int main(){
        long long a,b,c;
        cin>>a>>b>>c;
        
        cout<<func(a,b,c)%c;
    }
