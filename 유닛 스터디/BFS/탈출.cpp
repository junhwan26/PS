#include<stdio.h>
int c,r;
int map[50][50];
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int d[50][50];
#include<iostream> 
struct dot
{
	int x,y;
};
#include<queue>
using namespace std;
queue<dot> q;
queue<dot> qwater;
void print()
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
			printf("%d ",map[i][j]);
		printf("\n");
	}
	printf("\n");
}

void printd()
{
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
			printf("%d ",d[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	scanf("%d %d",&c,&r);
	int a,b,goala,goalb;
	for(int i=0;i<c;i++)
	{
		char tmp[51];
		scanf("%s",tmp);
		for(int j=0;j<r;j++)
		{
			if(tmp[j]=='S') //시 작 
			{ 
				map[i][j]=1;
				a=i;b=j;
			}
			else if(tmp[j]=='D') // 끝 
			{ 
				map[i][j]=2;
				goala=i;
				goalb=j;
			}
			else if(tmp[j]=='*')	//물 
			{
				map[i][j]=-1;
				qwater.push({i,j});
			}
			else if(tmp[j]=='X') //돌 
				map[i][j]=-2;
		
			d[i][j]=-1;
		}	
	}
	//printf("매핑\n");	print(); 	printf("goala=%d goalb=%d\n",goala,goalb);	//디버깅 

	//printf("hi");
	d[a][b]=0; 	//a,b 는 현위치 
	q.push({a,b});
	// 물 -1, 돌 -2, 끝 2, 시작 1 빈공간  0 
	while(!q.empty())
	{			
		int qwsize=qwater.size();
		//cout<<qwsize;
		for(int j=0;j<qwsize;j++)
		{
			int wa=qwater.front().x,wb=qwater.front().y;
			qwater.pop();
			for(int i=0;i<4;i++)
			{
				int nwa=wa+dir[i][0],nwb=wb+dir[i][1];
				if(nwa>=c||nwb>=r||nwa<0||nwb<0) continue;
				if(map[nwa][nwb]==1||map[nwa][nwb]==0)
				{
				map[nwa][nwb]=-1;
				qwater.push({nwa,nwb});
				}
			}
		}
		
		int qsize=q.size();
		for(int j=0;j<qsize;j++)
		{
			a=q.front().x; b=q.front().y;
			q.pop();
			for(int i=0;i<4;i++)
			{
				int na=a+dir[i][0],nb=b+dir[i][1];
				if(na>=c||nb>=r||na<0||nb<0||d[na][nb]>=0||map[na][nb]<0) continue;	 
		 	    q.push({na,nb});
	   	    	d[na][nb]=d[a][b]+1;
            		// printf("비버 위치는 %d %d\n",na,nb); //디버깅 
			}			
		}
			// printf("d배열은 어떨까\n"); printd(); //디버 깅 
			
		if(d[goala][goalb]>=0)
			break;

	}	
	//printf("물 채워짐\n");	print();
		
	
	if(d[goala][goalb]==-1)
		printf("KAKTUS");
	else 
	printf("%d",d[goala][goalb]);
}
