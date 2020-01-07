#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std; 
typedef struct a{
	int imp;
	int m;
}a;

int check[100];
int main(){
	int l;
	scanf("%d",&l);
	for(int p=0;p<l;p++){
	
	int n,m;
	scanf("%d %d",&n,&m);
	queue<a> q;
	vector<int> v;
	
	for(int i=0;i<n;i++){
		a temp;
		int tmp;
		

		
		scanf("%d",&tmp);
		temp.imp=tmp;
		temp.m=i;;
		q.push(temp);
		v.push_back(tmp);	
	}
	sort(v.rbegin(),v.rend());
	int k=0;
	while(!q.empty())
	{
		a pop=q.front();
		q.pop();
		if(pop.imp<v[k])
		{
			q.push(pop);
		}
		else if(pop.imp==v[k]){
			check[pop.m]=k+++1;
		}
	}
	//for(int i=0;i<n;i++)
	//	printf("%d ",check[i]);
	printf("%d\n",check[m]);
}
	
}
