#include<iostream>
#include<algorithm>

using namespace std;
	int maxa,maxb,maxc; 
	int mina,minb,minc;
	
	
int main(){
	int n;
	cin>>n;
 	int ma,mb,mc;
	for(int i=0;i<n;i++){
		int nowa,nowb,nowc;
		cin>>nowa>>nowb>>nowc;
		ma=max(nowa+maxa,nowa+maxb);
		mb=max(nowb+maxa,max(nowb+maxb,nowb+maxc));
		mc=max(nowc+maxc,nowc+maxb);
		maxa=ma;maxb=mb;maxc=mc;
		
		ma=min(nowa+mina,nowa+minb);
		mb=min(nowb+mina,min(nowb+minb,nowb+minc));
		mc=min(nowc+minc,nowc+minb);
		mina=ma;minb=mb;minc=mc;
				
	}
	cout<<max(max(maxa,maxb),maxc)<<" "<<min(min(mina,minb),minc);
}
