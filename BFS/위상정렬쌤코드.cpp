#include <stdio.h>  //작업순서 정하기

using namespace std;
int G[100][100],visited[100],in_deg[100];
int n, m, path[100], cnt;

void dfs(int here){
        visited[here]=1;
        for(int there= 1; there<=n; there++)
            if(visited[there]==0 && G[here][there])
                    dfs(there);
        path[cnt++]=here;
}

int main()
{
    int s, e;
    scanf("%d", &n);
    	while(~scanf("%d %d",&s,&e)) {
        G[s][e]=1;
        in_deg[e]++;
    }

    for(int k=n; k>=1; k--){
        if(!visited[k] && !in_deg[k]) {
            visited[k]=1;
            dfs(k);
        }
    }
    for(int i=cnt-1; i>=0; i--)
        printf("%d ", path[i]);


    return 0;
}
/*
5 5
1 2
2 3
1 5
4 5
5 3
*/

