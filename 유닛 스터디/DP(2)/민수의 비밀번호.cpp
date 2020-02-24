#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define INF 1000000
vector<int> prime;
vector<string> check;
int d[4];
int p(int n){
	if(n==1)
		return 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}

int main(){

	string s;
	cin>>s;

	int ans=0;
	int cnt=0;
	
	int min=1;
	for(int i=0;i<s.size();i++){
		if(s[i]=='*')
			cnt++;
		min*=10;
	}
	
	min/=10;
	
	int max=1;
	for(int i=0;i<cnt;i++){
		max*=10;
	}
	
	int c=max/10;
	max-=1;
	
	//cout<<min<<"\n";


	for(;max>=0;max--){
		int num=max;
		int m=c;
	//	cout<<"max "<<max<<" m "<<m<<"\n"; 
		for(int i=0;i<cnt;i++){
			d[i]=num/m;
			num%=m;
			m/=10;
		}
		
		m=min;
		int j=0;
		int tmp=0;
	//	cout<<"d =";
	//	for(int i=0;i<cnt;i++)
	//		cout<<d[i]<<" ";
	//	cout<<"\n";
	
		for(int i=0;i<s.size();i++){
			if(s[i]=='*')	
				tmp+=d[j++]*m;
			else
				tmp+=(s[i]-'0')*m;
				m/=10;
		}
		ans+=p(tmp);
	//	cout<<tmp<<"\n";
	}
	
	cout<<ans;
}
