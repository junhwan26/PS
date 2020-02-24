#include<iostream>

int dp[3001][3001][2][2];
int check[3001][3001][2][2];
int in[3001];
using namespace std; 
//1이 내 차레 
int f(int l,int r,int sum,int turn){
	//cout<<sum;	
	if(l>r){
		if(!sum)
			return 1;
		else 
			return 0;
	}
	
	if(dp[l][r][sum][turn]){
		return dp[l][r][sum][turn]%2;
	}
	
	if(l==r){
		if(turn==1){
			if((in[l]+sum)%2==0){
				return 1;
			}
			else{
				return 0;
			}
		} 
		else{
			if(!sum){
				return 1;
			}
			else{
				return 0;
			}
		}
	}
	
	else{
		if(turn==1){
			dp[l][r][sum%2][turn]=(f(l+1,r,(sum+in[l])%2,0) || f(l+2,r,(sum+in[l]+in[l+1])%2,0) || f(l,r-1,(sum+in[r])%2,0) || f(l,r-2,(sum+in[r]+in[r-1])%2,0)) + 2;
			//cout<<l<<" "<<r<<" "<<sum<<" "<<turn<<" "<<dp[l][r][sum%2][turn]<<"\n";
			return dp[l][r][sum%2][turn]%2;
		}
		else{
			
			dp[l][r][sum][turn]=(f(l+1,r,sum,1) && f(l+2,r,sum,1) && f(l,r-1,sum,1) && f(l,r-2,sum,1))+ 2;
			//cout<<l<<" "<<r<<" "<<sum<<" "<<turn<<" "<<dp[l][r][sum%2][turn]<<"\n";
			return dp[l][r][sum][turn]%2;
		}
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>in[i];
	}	
	
	if(f(1,n,0,1))
		cout<<"Yes";
	else
		cout<<"No";
}
