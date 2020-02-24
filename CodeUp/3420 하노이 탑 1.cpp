#include<iostream>
using namespace std;

void f(int num,char from, char by,char to){
	if(num==0)
		return;
	f(num-1,from,to,by);
	cout<<"Disk "<<num<<" : "<<from<<" to "<<to<<"\n";
	f(num-1,by,from,to);
}

int main(){
	int n;
	cin>>n;
	f(n,'A','B','C');
}
