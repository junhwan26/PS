#include<iostream>
using namespace std;

int in[500];
int tmp[500];
int n;

void reverse(int initail,int final){
	
	for(int i=initail;i<final;i++)
		tmp[i]=in[i];
		
	int j=final;
	for(int i=initail;i<final;i++){
		in[i]=tmp[j--];
	}
	
}
void printin(){
	for(int i=0;i<n;i++)
		cout<<in[i]<<" ";
	cout<<"\n";
}


int main(){
		
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	
	int flag=0;
	int revi,revf;
	
	for(int i=0;;i++){
		if(in[(i+1)%n]<in[i%n]&&!flag){
			flag=1;
			revi=i+1;
		}
		else if(in[(i+1)%n]>in[i%n]&&flag){
			revf=i;
			break;
		}
	}
	cout<<revi<<" "<<revf<<"\n";
	
	if(revi>revf){
		for(int i=revi;i<n;i++){
			tmp[i]=in[i];
		}
		for(int i=revi-1;i>=0;i--){
			in[i+n-revi]=in[i];
		}
		int k=0;
		for(int i=revi;i<n;i++){
			in[k++]=tmp[i];
		}
		revf+=n-revi;
		revi+=0;
		
	}
	
	printin();
	reverse(revi,revf);
	printin();
}
