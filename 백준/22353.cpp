#include<iostream>
using namespace std;
int main(){
    double a,d,k;
    cin>>a>>d>>k;
    d/=100;
    k/=100;
    double ans=0;
    double p=1;
    for(double i=1; ; i++){
        if(d>=1){
            ans += i*a*p;
            break;
        }
        ans+=(a*i)*d*p;
        p *= (1-d);
        d =d*(1+k);
    }
    
    printf("%.7lf",ans);
}
