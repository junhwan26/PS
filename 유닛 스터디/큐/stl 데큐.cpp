#include<iostream>
#include<deque>

using namespace std;

int main()
{
	deque<int> dq;
	
	int a=2;
	dq.push_back(a);
	dq.push_back(3);
	dq.push_front(1);
	
	cout<<dq.front()<<" "<<dq.back()<<endl;
	
	dq.pop_front();
	dq.pop_back();
	
	cout<<dq.front()<<" "<<dq.back()<<endl;
	
	return 0;
}
