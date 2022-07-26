#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        char s[10];
        int cnt;
        int flag=1;
        scanf("%s %d", s, &cnt);
        int i=0;
        
        while(cnt){
            int max=-1,maxj=-1;
            int same=0;
            for(int j=strlen(s)-1; j>i; j--){
                if(max<s[j]-'0'){
                    max =s[j]-'0';
                    maxj = j;
                }
            }
            //cout<<s<<endl;
            //cout<<"maxj: "<<maxj<<" s[maxj]: "<<s[maxj]<<endl;
            for(int k = 1;k<cnt;k++){
                if(s[maxj] == s[maxj-k]){
                    same++;
                }
                else{
                    break;
                }
            }
            if(same>0){
                //cout<<"i : "<<i<<" same : "<<same<<endl;
                //cout<<"before "<<s<<" / after ";
                sort(s+i, s+i+same+1);
                //cout<<s<<endl;
            }
            
            
            //printf("max : %d, s[i] : %c\n",max,s[i]);
            while(i<strlen(s) && s[i]-'0'>=max)
                i++;
            //printf("max : %d, s[i] : %c\n",max,s[i]);
            
            if(maxj!=-1 && i<maxj){
                int tmp = s[i];
                s[i] = s[maxj];
                s[maxj] = tmp;
                i++;
                //printf("1 ");
            }
            else{
                //printf("맨뒤에거 바꾸기 쇼 ");
                if(flag){
                    char a[10];
                    strcpy(a, s);
                    for(int i=0; i<strlen(a)-1;i++){
                        if(a[i] == a[i+1])
                            cnt=0;
                    }
                    flag=0;
                    if(cnt==0)
                        break;
                }
                
                int tmp = s[strlen(s)-2];
                s[strlen(s)-2] = s[strlen(s)-1];
                s[strlen(s)-1] = tmp;
                
            }
            cnt--;
//            printf("%d %s\n",cnt,s);
        }
        printf("#%d %s\n",test_case, s);


    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
