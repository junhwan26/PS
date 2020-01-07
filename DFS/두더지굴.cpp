#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int in[30][30];
int arr[30][30];
int cnt;
int n;
int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
void f(int x,int y)
{
	arr[y][x]=1;
	cnt++;
	for(int i=0;i<4;i++)
	{
		int nx = x+dir[i][0], ny = y+dir[i][1];
		if(nx<0||ny<0||nx>=n||ny>=n||in[ny][nx]==0||arr[ny][nx]==1)
			continue;
		f(nx,ny);
	}
	return;
}

int main()
{
	vector<int> ans;

	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&in[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(in[i][j]==0||arr[i][j]==1) continue;
			cnt=0;
			f(j,i);
			ans.push_back(cnt);
		}
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(i =0;i<ans.size();i++)
	{
		printf("%d\n",ans[i]);
	}	
}
