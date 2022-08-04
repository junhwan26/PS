
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

//bool cmp(string A, string B) {
//    if (A.length() < B.length())
//        return true;
//    else if (A.length() > B.length())
//        return false;
//    return A < B;
//}
typedef struct AAA{
    char a[60];
}aaa;

bool cmp(AAA A, AAA B) {
    if (strlen(A.a) < strlen(B.a))
        return true;
    else if (strlen(A.a) > strlen(B.a))
        return false;
    for(int i=0; i<strlen(A.a); i++){
        if(A.a[i] != B.a[i])
            return A.a[i] < B.a[i];
    }
    return true;
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    
    
    for(test_case = 1; test_case <= T; ++test_case)
    {
        vector<aaa> v;
        
        int N;
        cin>>N;
        for(int i=0; i<N;i++){
            aaa tmp;
            //string tmp;
            scanf("%s",tmp.a);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), cmp);
        printf("#%d\n%s\n",test_case, v[0].a);
        for(int i=1; i<N; i++){
            if(strcmp(v[i-1].a, v[i].a)!=0)
                printf("%s\n",v[i].a);
        }
        
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
