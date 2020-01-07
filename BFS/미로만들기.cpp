#include<stdio.h>
int n;
int in[50][50];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d[50][50];
#include<deque>
using namespace std;
struct dot{
	int x,y;
};
deque<dot> dq;
// 0 검은 방 1 흰방
// 흰방으로 갈 수있음 

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			d[i][j]=-1;
			scanf("%1d",&in[i][j]);
		}
	dq.push_back({0,0});
	d[0][0]=0;

	while(!dq.empty())
	{
		int a=dq.front().x,b=dq.front().y;
		dq.pop_front();
		if(a==n-1&&b==n-1)
		{
			printf("%d",d[a][b]);
			return 0;
		}
		for(int i=0;i<4;i++)
		{
			int na=a+dir[i][0],nb=b+dir[i][1];
			if(na>=n||nb>=n||na<0||nb<0||d[na][nb]>=0) continue;	 
            if (in[na][nb]) {
                d[na][nb] = d[a][b];
                dq.push_front({na, nb});
            } 
			else {
                d[na][nb] = d[a][b]+1;
                dq.push_back({na, nb});
            }


		}
	}
	
	 
	
}
