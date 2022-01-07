#include<iostream>
using namespace std;

long long CCW(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long tmp = x1*y2+x2*y3+x3*y1 - (y1*x2 + y2*x3 + y3 * x1);
    if(tmp>0)
        return 1;
    else if(tmp<0)
        return -1;
    else
        return 0;
}

int main(){
    long long x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    long long x3,y3,x4,y4;
    cin>>x3>>y3>>x4>>y4;
    
    long long a1 = CCW(x1,y1,x2,y2,x3,y3), a2 = CCW(x1,y1,x2,y2,x4,y4);
    long long b1 = CCW(x3,y3,x4,y4,x1,y1), b2 = CCW(x3,y3,x4,y4,x2,y2);
    
    if( a1*a2 <= 0 && b1*b2 <= 0 ){
        if(a1*a2 == 0 && b1*b2 == 0){
            //cout<<max(x1,x2) <<" "<< min(x3,x4)<<"\n"<< min(x1,x2) <<" "<< max(x3,x4) <<endl<< max(y1,y2) <<" "<< min(y3,y4) <<endl<< min(y1,y2) <<" "<< max(y3,y4);
            if(max(x1,x2) >= min(x3,x4) && min(x1,x2) <= max(x3,x4) && max(y1,y2) >= min(y3,y4) && min(y1,y2) <= max(y3,y4))
                cout<<1;
            else
                cout<<0;
            
        }
        else
            cout<<1;
    }
    else{
        cout<<0;
    }
    

}
