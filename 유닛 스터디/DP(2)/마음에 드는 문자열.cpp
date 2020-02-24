#include<iostream>
using namespace std;
#include<stack>


int main(){
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		stack<char> st;
		string tmp;
		cin>>tmp;
		st.push(tmp[0]);
		for(int j=1;j<tmp.size();j++){
			if(!st.empty()&&st.top()==tmp[j])
				st.pop();
			else
				st.push(tmp[j]);
		}
		
		if(st.size()==0)
			ans++;
	}
	cout<<ans;
}
