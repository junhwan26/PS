
#include<iostream>
int arr[100000];
int tmp[100000];
int N;
long long result;
using namespace std;

void merge(long long start, long long mid, long long end){
    long long p = start, q =mid+1;
    long long cur = start;
    while(p<= mid && q<=end){
        if(arr[p] < arr[q]){
            tmp[cur++] = arr[p++];
        }
        else{
            tmp[cur++] = arr[q++];
            result += mid-p+1;
        }
    }
    while(p<=mid)
        tmp[cur++] = arr[p++];
    while(q<=end)
        tmp[cur++] = arr[q++];
    for(long long i = start; i<=end; i++)
        arr[i] = tmp[i];
}

void mergeSort(long long start, long long end){
    if(start>=end)
        return;
    long long mid = (start+end)/2;
    mergeSort(start,mid);
    mergeSort(mid+1,end);
    merge(start,mid,end);

}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        result = 0LL;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }

        mergeSort(0,N-1);
        cout<<"#"<<test_case<<" "<<result<<endl;

        

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
