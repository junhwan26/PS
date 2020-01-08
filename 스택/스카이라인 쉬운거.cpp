#include<stdio.h>
#include<vector>
#include<stack> 
#include<algorithm>
using namespace std;

stack<int> st;
typedef struct dot{
	int x,y;
}dot;

int comp(dot a,dot b){
	if(a.x<b.x)
		return 1;
	return 0;
}

vector<dot> v;
int main(){
	int n;
	scanf("%d",&n);

	for(int i=0;i<n;i++){
		dot temp;
		scanf("%d %d",&temp.x,&temp.y);
		v.push_back(temp);
	}
	dot temp;
	temp.x=-1;
	temp.y=0;
	sort(v.begin(),v.end(),comp);

	v.push_back(temp);
	st.push(0);
	int ans=0;
	for(int i=0;i<v.size();i++){
		if(st.top()<=v[i].y){
			st.push(v[i].y);
		}
		else{
			int tmp=-1;
			while(st.top()>v[i].y){
				if(st.top()!=tmp)
				{
					tmp=st.top();
					ans++;	
				}
				st.pop();
				
			}
			st.push(v[i].y);
		}
		
	//	printf("%d %d ans=%d st,size=%d\n",v[i].x,v[i].y,ans,st.size());
	}
	
	printf("%d",ans);
}	
