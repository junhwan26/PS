#include<iostream>
using namespace std;

int in[101];
int tab[101];
int main(){
	int n,k;
	cin>>n;
	cin>>k;
	
	for(int i=0;i<k;i++){
		cin>>in[i];
		cnt[in[i]]++;
	}
	
	int ans=0;
	
	for(int i=0;i<k;i++){
		
		int min=101,flag=1,index;
		
		for(int j=0;j<n;j++){
			//cout<<tab[j]<<" "<<in[i];
			if( tab[j]==0 || tab[j]==in[i]){
				tab[j]=in[i];
				flag=0;
				break;
			//	cout<<"-";
			}
		}
		
		if(flag){
			int maxj=0,maxt=0;
			for(int j=0;j<n;j++){
				int flag1=1;
				//cout<<"===================\n"<<j<<" "<<tab[j]<<"\n";
				
				for(int t=i+1;t<k;t++){
					if(in[t]==tab[j]){
						if(t>maxt){
					//		cout<<t<<" "<<in[t]<<"\n";
							maxj=j;
							maxt=t;
							flag1=0;
							break;
						}	
					}
				}
				//cout<<"maxt = "<<maxt<<" maxj = "<<maxj<< " flag = "<<flag<<"\n"<<"===================\n";
				if(flag1){
					maxj=j;
					break;
				}
					
			}
			
			
			tab[maxj]=in[i];
			ans++;
		}
		
	//	for(int j=1;j<=k;j++)
	//		cout<<cnt[j]<<" ";
	//	cout<<"\n";
	//	for(int l=0;l<n;l++)
	//		cout<<tab[l]<<" ";
		
	//	cout<<"\n"<<in[i]<<" "<<ans<<"\n";
	//	
	}
	cout<<ans;
}
