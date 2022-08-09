#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int cow[500000];

int N,M,c1,c2;
int lowerbound(int horse){
    int l = 0, r = N;
    while(l<r){
        int mid = (l+r)/2;
        if(cow[mid] >= horse)
            r = mid;
        else
            l = mid+1;
    }
    return l;
}


int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        
        scanf("%d %d",&N,&M);
        scanf("%d %d",&c1,&c2);
        for(int i=0; i<N; i++)
            scanf("%d", &cow[i]);
        sort(cow, cow+N);
        int horse, min = 200000000, cnt = 0;
        for(int i=0; i<M; i++){
            cin>>horse;
            int j = lowerbound(horse);
            
            
            int dist;
            if(j < N){
                dist = cow[j] - horse;
                if(dist == min){
                    cnt++;
                }
                if(dist < min){
                    min = dist;
                    cnt=1;
                }
            }
            if(j > 0){
                dist = abs(horse - cow[j-1]);
                cout<<dist<<endl;
                if(dist == min){
                    cnt++;
                }
                if(dist < min){
                    min = dist;
                    cnt=1;
                }
            }
            
        
        }
        cout<<"#"<<test_case<<" "<<min+abs(c1-c2)<<" "<<cnt<<endl;
            

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
