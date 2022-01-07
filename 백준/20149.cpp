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
        if(a1==0 && a2 == 0){
            
            if(x1>x2){
                swap(x1, x2);
                swap(y1, y2);
            }
            else if(x1==x2 && y1>y2){
                swap(x1, x2);
                swap(y1, y2);
            }
            
            if(x3>x4){
                swap(x3, x4);
                swap(y3, y4);
            }
            else if(x3==x4 && y3>y4){
                swap(x3, x4);
                swap(y3, y4);
            }
            
            if(x2 >= x3 && x1 <= x4 && y2 >= y3 && y1 <= y4){
                cout<<1<<"\n";
                
                if((x2 == x3 && y2 == y3))
                    cout<<x2<<" "<<y2<<"\n";
                else if(x1 == x4 && y1 == y4)
                    cout<<x4<<" "<<y4<<"\n";
                
            }
            else
                cout<<0<<"\n";
            
        }
        else{
            cout<<1<<"\n";
            double x,y;
            x = (double)((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - y3*x4))/( (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4) );
            y = (double)((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - y3*x4)) / ( (x1 - x2)*(y3 - y4) - (y1 - y2)*(x3 - x4) );
            printf("%.10lf %.10lf",x,y);

        }
    }
    else{
        cout<<0;
    }
    

}
