#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> q;
	cout<<"q.empty() [is_empty => 1, is_not_empty => 0] : "<<q.empty()<<endl;
	cout<<"q.push(1)"<<endl;
	q.push(1);
	int a=2;
	cout<<"q.push(a) : a value is 2"<<endl;
	q.push(a);
	cout<<"q.push(3)"<<endl;
	q.push(3);
	
	cout<<"q.front() : "<<q.front()<<endl;
	
	cout<<"q.pop"<<endl;
	q.pop();
	
	cout<<"q.front() : "<<q.front()<<endl;
	
	cout<<"q.empty() [is_empty => 1, is_not_empty => 0] : "<<q.empty()<<endl;
	return 0;
	
}
