#include<iostream>
#include<algorithm>
using namespace std;
struct A{
	int end,start,date; 
};

A in[100000];

int cmp(A a, A b){
	return a.start<b.start;
}
int main(){
	int n;
	
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		
		in[i].start=a*100+b;
		in[i].end=c*100+d;	
	}
	
	sort(in,in+n,cmp);
//	for(int i=0;i<n;i++){
//		cout<<in[i].start<<" "<<in[i].end<<" / ";
//	}cout<<"\n";
	
	int now=301,ans=0,index,max=0;
	for(int i=0;i<=n-1;i++){
		
		if(now>1130)
			break;
		
		if(max<in[i].end&&in[i].start<=now){
			index=i;
			max=in[i].end;
//			cout<<"choosing "<<i<<" : "<<in[index].start<<" "<<in[index].end<<"\n";
			
		}
		
		if(in[i].start>now&&max!=0){
			now=in[index].end;
			ans++;
//			cout<<"selected "<<i<<" : "<<in[index].start<<" "<<in[index].end<<"\n";
			i--;
			max=0;
		}
		else if(max!=0&&i==n-1){
			now=in[index].end;
			ans++;
		}
		else if(max==0){
			ans=0;
			break;
		}
	}
	if(now<=1130)
		ans=0;
	cout<<ans;
}
