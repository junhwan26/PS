#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct {
    int x;
    int y1,y2;
    int check;
    
} rec;

bool cmp(const rec &a, const rec &b){
    if(a.x<b.x)
        return true;
    else if(a.x == b.x){
        if(a.check<b.check)
            return true;
    }
    return false;
}

vector<rec> v;

int Y[20001];

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        double a,b,c,d;
        cin>>a>>b>>c>>d;
        rec tmp = {(int)(a*10),(int)(b*10),(int)(b*10)+(int)(d*10),-1};
        v.push_back(tmp);
        tmp = {(int)(a*10)+(int)(c*10),(int)(b*10),(int)(b*10)+(int)(d*10),1};
        v.push_back(tmp);
    }
    sort(v.begin(),v.end(),cmp);
    
    int x=0;
    int ans=0;
    
    for(int i=0;i<v.size();i++){
        int h=0;
        

        for(int j=0;j<=20000;j++){
            if(Y[j]>0)
                h++;
        }
        //cout<<v[i].x-x<<" "<<h<<endl;
        
        ans+=h*(v[i].x-x);
        
        for(int j=v[i].y1; j<v[i].y2; j++){
            if(v[i].check == -1)
                Y[j]++;
            else
                Y[j]--;
        }
        
        x=v[i].x;
    }
    //cout<<ans<<endl;
    if((int)ans%100==0)
        cout<<ans/100;
    else
        printf("%.2f",ans/100.0);
    
}
