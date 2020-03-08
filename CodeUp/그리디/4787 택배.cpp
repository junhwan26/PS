#include<iostream>
#include<algorithm> 
using namespace std;

pair<int, int> pii;

typedef struct In{
    int from,to,cost;
}In;

In ins[10001];

// 목적지, 출발지 순으로 정렬 
int cmp(In a, In b){    
    if(a.to!=b.to)
        return a.to < b.to;
    return a.from < b.from;
}

int box[2001];        // 그 구간에서 트럭이 들고 있는 상자의  

int main(){
    int ans=0;
    int n,c,m;
    cin>>n>>c>>m;

    for (int i=0; i < m; i++){ 
        scanf("%d %d %d", &ins[i].from, &ins[i].to, &ins[i].cost); 
    }
    
    sort(ins, ins + m , cmp);
    for(int i=0;i<m;i++){

        In now = ins[i]; // 이번에 볼 입력 값
    
        int already = 0; // 주어진 구간에서의 최대 상자 수
        
        for (int i = now.from; i < now.to; i++) 
            already=max(already,box[i]);

        // 상자의 최대 갯수를 넘길 수 있기 때문에 
        // 지금 보고 있는 상자의 개수와 남은 용량중 작은 것을 선택
        int add = min(now.cost, c - already); 
        
        for (int i = now.from; i < now.to; i++) { //구간에 추가 
            box[i] += add; 
        } 
    
        ans += add; // 추가한 만큼을 답에 더해줌 
    }
    
    cout << ans << "\n";
    return 0;
} 
