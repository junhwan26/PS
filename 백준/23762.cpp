#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
pair<int, int> in[100001];
int dp1[100001][2];
int dp2[100001][2];
int cpy[100001];

vector<pair<int, int>> v[100001][2];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        in[i].first=tmp;
        in[i].second=i;
    }
        
    sort(in,in+n);
    
    dp1[0][0] = 1;
    v[0][0].push_back(in[0]);
    dp1[0][1] = 1000000001;
    
    dp1[1][0] = 2;
    v[1][0].push_back(in[0]);
    v[1][0].push_back(in[1]);
    dp1[1][1] = 1000000001;
    
    dp1[2][0] = 3;
    v[2][0].push_back(in[0]);
    v[2][0].push_back(in[1]);
    v[2][0].push_back(in[2]);
    dp1[2][1] = 1000000001;
    
    dp1[3][0] = 4;
    v[3][0].push_back(in[0]);
    v[3][0].push_back(in[1]);
    v[3][0].push_back(in[2]);
    v[3][0].push_back(in[3]);
    dp1[3][1] = 0;
    dp2[3][1] = in[3].first - in[0].first;
//
//    for(int k=0;k<n;k++)
//        cout<<in[k].first<<" ";
//    cout<<endl;
//    
    for(int i=4;i<n;i++){
        if(dp1[i-1][0] > dp1[i-1][1]){
            //cout<<"*1*"<<endl;
            dp2[i][0] = dp2[i-1][1];
            dp1[i][0] = dp1[i-1][1]+1;
            v[i][0]=v[i-1][1];
            v[i][0].push_back(in[i]);
        }
        else if(dp1[i-1][0] < dp1[i-1][1]){
            //cout<<"*2*"<<endl;
            dp2[i][0] = dp2[i-1][0];
            dp1[i][0] = dp1[i-1][0]+1;
            v[i][0]=v[i-1][0];
            v[i][0].push_back(in[i]);
        }
        else{
            if(dp2[i-1][0] > dp2[i-1][1]){
                //cout<<"*1*"<<endl;
                dp2[i][0] = dp2[i-1][1];
                dp1[i][0] = dp1[i-1][1]+1;
                v[i][0]=v[i-1][1];
                v[i][0].push_back(in[i]);
            }
            else {
                //cout<<"*2*"<<endl;
                dp2[i][0] = dp2[i-1][0];
                dp1[i][0] = dp1[i-1][0]+1;
                v[i][0]=v[i-1][0];
                v[i][0].push_back(in[i]);
            }
        }
        if(dp1[i-4][0] > dp1[i-4][1]){
            //cout<<"*3*"<<endl;
            dp2[i][1] = dp2[i-4][1] + in[i].first - in[i-3].first;
            dp1[i][1] = dp1[i-4][1];
            v[i][1]=v[i-4][1];
        }
        else if(dp1[i-4][0] < dp1[i-4][1]){
            //cout<<"*4*"<<endl;
            dp2[i][1] = dp2[i-4][0] + in[i].first - in[i-3].first;
            dp1[i][1] = dp1[i-4][0];
            v[i][1]=v[i-4][0];
        }
        else{
            if(dp2[i-4][0] > dp2[i-4][1]){
                //cout<<"*3*"<<endl;
                dp2[i][1] = dp2[i-4][1] + in[i].first - in[i-3].first;
                dp1[i][1] = dp1[i-4][1];
                v[i][1]=v[i-4][1];
            }
            else{
                //cout<<"*4*"<<endl;
                dp2[i][1] = dp2[i-4][0] + in[i].first - in[i-3].first;
                dp1[i][1] = dp1[i-4][0];
                v[i][1]=v[i-4][0];
            }
        }
//        cout<<v[i][0].size()<<" "<<v[i][1].size()<<endl;
//        for(int k=0;k<n;k++)
//            cout<<dp1[k][0]<<" ";
//        cout<<endl;
//        for(int k=0;k<n;k++)
//            cout<<dp1[k][1]<<" ";
//        cout<<endl;
    }
    
    
    if(dp1[n-1][1] > dp1[n-1][0]){
        
        printf("%d\n",dp2[n-1][0]);
        for(int i=0;i<v[n-1][0].size();i++){
            printf("%d\n",v[n-1][0][i].second);
            
        }
    }
    else if(dp1[n-1][1] < dp1[n-1][0]){
        printf("%d\n",dp2[n-1][1]);
        
        for(int i=0;i<v[n-1][1].size();i++){
            printf("%d\n",v[n-1][1][i].second);
            
        }
    }
    else{
        if(dp2[n-1][1] > dp2[n-1][0]){
            cout<<dp2[n-1][0]<<endl;
            
            for(int i=0;i<v[n-1][0].size();i++){
                printf("%d\n",v[n-1][0][i].second);
                
            }
        }
        else{
            cout<<dp2[n-1][1]<<endl;
            for(int i=0;i<v[n-1][1].size();i++){
                printf("%d\n",v[n-1][1][i].second);
                
            }
        }
    }
}
