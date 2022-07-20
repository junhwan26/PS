#include<iostream>
#include<string>
using namespace std;

string in[50];
int num[8];
string nums[10] ={"0001101", "0011001", "0010011", "0111101", "0100011", "0110001", "0101111", "0111011", "0110111", "0001011"};

int main(int argc, char** argv){
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        int N,M;
        cin>>N>>M;
        for(int i=0; i<N;i++)
            cin>>in[i];
        int i=0;
        int j=M-1;
        while(i<N  && in[i][j]!='1'){
            if(j<0){
                i++;
                j = M-1;
                continue;
            }
            j--;
        }
        
        int ans = 0, k=7;
        int cnt = 8;
        while(cnt>0){
            string tmp = in[i].substr(j-6,7);
            for(int l=0;l<10;l++){
                if(tmp.compare(nums[l]) == 0){
                    num[k--] = l;
                    //cout<<tmp<<"("<<l<<")"<<endl;
                    break;
                }
            }
            j-=7;
            cnt--;
        }
        if(k==-1){
            //cout<<"hi"<<endl;
            if(((num[0]+num[2]+num[4]+num[6])*3 + num[1] + num[3] + num[5]+ num[7])%10 == 0)
                ans = num[0]+num[1]+num[2]+num[3]+num[4]+num[5]+num[6]+num[7];
        }
        cout<<"#"<<test_case<<" "<<ans<<endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}



