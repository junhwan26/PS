#include<iostream>
using namespace std;

int dp[30];
int dpg[30];

int f(int n){
	if(n==0)
		return 0;
    if(dp[n])
        return dp[n];
    else
    {
        dp[n]=f(n-1)*2+1;
        return dp[n];
    }
}

int g(int n){
	if(n==0)
		return 0;
	if(!dpg[n])
	{
		int ans=f(n);
		for (int i = 1; i < n; i++) {
    		//cout<<f(i)<<" "<<f(n-i)<<"\n";
        	ans=min(ans,g(i)*2+f(n-i));
    	}
    	dpg[n]=ans;
	}
	return dpg[n];

}

int main(){
    int n;
    cin>>n;
    int ans=f(n);
    

	cout<<g(n);
}
