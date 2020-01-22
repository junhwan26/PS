#include<iostream>
#include<string>
using namespace std;

int main(){
	freopen("word.in","r",stdin);
    freopen("word.out","w",stdout);
    
	int n,k;
	scanf("%d %d",&n,&k);
	int count=0;
	for(int i=0;i<n;i++){
		string in;
		cin>>in;	
		if(count+in.length()<=k)
		{
			if(count!=0)
			cout<<" ";
			cout<<in;
			count+=in.length();
		}
		else{
		cout<<"\n";
		count=in.length();
		cout<<in;
		}
		
	}
}

