#include<stdio.h>
#include<vector> 
#include<algorithm>
using namespace std;
vector<int> in[10001];
int btree[10001][2];
int Max=0,maxi;
int n;
int cnt=1;
int check[10001];
void inorder(int i,int j)
{
	if(i<=0||j>=10001||i>=10001||j<=0) return;
	inorder(btree[i][0],j+1);
	in[j].push_back(cnt);
	cnt++;
	inorder(btree[i][1],j+1);
}

int findtop()
{
	for(int i=1;i<=n;i++)
	{
		if(btree[i][0]!=-1)
		check[btree[i][0]]=1;
		if(btree[i][1]!=-1)
		check[btree[i][1]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(!check[i])
		return i;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p,l,r;
		scanf("%d %d %d",&p,&l,&r);
		btree[p][0]=l; btree[p][1]=r;
	}
	inorder(findtop(),1);
	
	for(int i = 1;i<=n;i++)
	{
		if(in[i].size()==0) break;
		sort(in[i].begin(),in[i].end());
		int nmax=in[i][in[i].size()-1],nmin=in[i][0];
		
		//printf("nmin = %d , nmax = %d\n",nmin,nmax);
		if(nmax-nmin+1>Max)
		{
			Max=nmax-nmin+1;
			maxi=i;
		}
	}
	printf("%d %d",maxi,Max);
	
} 
