#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>

typedef struct A{
	int end,dis;
}A;

bool operator <(const A& l, const A& r)
{
    if(l.end != r.end)
        return l.end < r.end;
    return l.dis < r.dis;
}


using namespace std;

queue<int> q;
map<int,int> dis;
map<int , vector<A> > tree;

map<int,int> head;
vector<int> in;


int main(){
	int n,m,c;
	cin>>n>>m>>c;
	
	for(int i=1;i<=n;i++)
	{
		
		int tmp;
		cin>>tmp;
		in.push_back(tmp);
		dis.insert(make_pair(tmp,tmp));
		head[tmp]=0;
	}
	
	for(int i=1;i<=c;i++){
		int a,b,x;
		cin>>a>>b>>x;
			
		A tmp={b,x};
		
		if(head[b]!=0){
			tree[b].push_back(tmp);
	
		}
			
		else{
			tree.insert(pair<int,vector<A> >(a, vector<A>()));
			tree[a].push_back(tmp);	
		}
		head[b]++;
	}
	
	
	for (std::map<int ,int >::iterator it=head.begin(); it!=head.end(); ++it)
	{
	  //	cout<< it->first <<" "<< it->second <<"\n";
		if(it->second==0){
			q.push(it->first);
		}
	}
	
/*	  
	for(int i=0;i<in.size();i++){
		cout<<dis[in[i]]<<"\n";
	}	
*/	
	 
	while(!q.empty()){
		int size=q.size();
		for(int i=0;i<size;i++){
			int tmp = q.front();
			q.pop();
//			cout<<"**"<<tmp<<"\n";
			for(int j=0;j<tree[tmp].size();j++){
				dis[tree[tmp][j].end] = max(dis[tree[tmp][j].end] , dis[tmp]+tree[tmp][j].dis);
				head[tree[tmp][j].end]--;
//				cout<<"head[tree[tmp][j].end] "<<head[tree[tmp][j].end]<<"\n";
				if(head[tree[tmp][j].end]==0)
					q.push(tree[tmp][j].end);
			}
		}		
	}
	
	for(int i=0;i<in.size();i++){
		cout<<dis[in[i]]<<"\n";
	}	
		
}
	
/*
4 10 3
1 2 3 4
1 2 5
2 4 2
3 4 4
*/

