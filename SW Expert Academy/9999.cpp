#include<cstring>
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

long long sum[200000];
long long v[200000];
int main(int argc, char** argv)
{
    
    int test_case;
    int T;
    freopen("2_input.txt", "r", stdin);
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        memset(sum, 0, sizeof(sum));
        memset(v, 0, sizeof(v));
        long long L,N;
        scanf("%lld %lld",&L,&N);
        scanf("%lld %lld",&v[0],&v[1]);
        sum[1] = v[1]-v[0];
        for(int i=1; i<N;i++){
            scanf("%lld %lld",&v[i*2],&v[i*2+1]);
            sum[i*2] =  sum[2*i-1];
            sum[i*2+1] = sum[2*i] + v[i*2+1] - v[i*2];
        }
        
//        cout<<"v[0]:"<<v[0]<<" L :"<<L<<" N:"<<N<<endl;
        
//                for(int i=0; i<2*N-1; i++){
//                    if(sum[i])
//                    cout<<i<<" "<<sum[i]<<endl;
//                }
        long long ans = 0;
        
        for(int i=0; i<2*N; i+=2){
            long long t_ = v[i]+L;
            long long index = upper_bound(v, v+2*N, t_) - v;
            
//            cout<<"i: "<<i<<" t_:"<<t_<<" index: "<<index;
            
                
            if(!(index&1)){
                long long tmp = sum[index-1] - sum[i];
                ans = max(ans,tmp);
//                cout<<" tmp2: "<<ans<<endl;
            }
            else{
                long long tmp = sum[index-1] - sum[i] + t_ - v[index-1];
                ans = max(ans,tmp);
//                cout<<" tmp1: "<<ans<<endl;
            }
                
            
        }
//        cout<<"v[0]:"<<v[0]<<" L :"<<L<<" N:"<<N<<endl;
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
