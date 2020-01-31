#include<iostream>
#include<string>
using namespace std;

string temp;

int f(int l, int h,int d){
	//cout<<temp<<" "<<l<<" "<<h<<"\n";
	if(d>=2) return 0;
	if(l>=h)
		return 0;
		
	if (temp[l] != temp[h]) 
    {	 
    	return 1+ min(f(l,h-1,d+1),f(l+1,h,d+1));		
	}
	
	return f(l+1,h-1,d); 
	 
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>temp;
		int l = 0; 
    	int h = temp.size()- 1; 
		int ans=f(l,h,0);
		if(ans>2)
			ans=2;
		
			cout<<ans<<"\n";
			
	}
	
}
