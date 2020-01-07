

#include <stdio.h>// 치즈2 소스
#include <memory.h>
struct location{
    int x,y;
};
int A[102][102]; //최대사이즈100에 벽을만들기위해 +2 크기 할당
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};   //4방향 체크
location queue[10000];  
int main(){
    int n,m,i,j,k,check,time=0;
    int rear=-1,front=0,end=0;
    location cur;
    memset(A,-1,sizeof(int)*102*102);   //공기인 0과 겹치지 않기위해 -1로 초기화
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&A[i][j]);   //벽을 만들기위해 인덱스 1~n,m까지 입력
      
  
    while(end==0){  //end는 더이상 치즈가 없을경우 1
        end=1;
        front=0;
        rear=-1;
        queue[++rear].x=1;
        queue[rear].y=1;
        A[1][1]=2;  //내부공기와 외부공기의 차이를 두기위해 외부공기를 2로 만들어줌
        while(front<=rear){
            cur=queue[front++];
            for(i=0;i<4;i++){
                if(A[cur.x+dx[i]][cur.y+dy[i]]==0){
                    queue[++rear].x=cur.x+dx[i];
                    queue[rear].y=cur.y+dy[i];
                    A[cur.x+dx[i]][cur.y+dy[i]]=A[cur.x][cur.y];
                }
            }
        }   //이작업이끝나면 외부공기는 2가 되있음 
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                check=0;
                if(A[i][j]==1){ //치즈를 발견했을때 접촉면이 외부공기인 2인 경우
                    end=0;
                    for(k=0;k<4;k++){
                        if(A[i+dx[k]][j+dy[k]]==2)
                            check++;
                    }
                    if(check>=2) //접촉면이 2면이상인경우
                        A[i][j]=3;  //녹게될지점 3을 넣어줌
                }
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(A[i][j]>=2)   //외부공기와 녹게될지점모두 0인 공기로 초기화작업
                    A[i][j]=0;
            }
        }
        time++; //시간증가
    }
    printf("%d\n",time-1);
}
 


