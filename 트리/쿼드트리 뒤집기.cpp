#include <iostream>
#include <string>
 
using namespace std;
 
string s;

string rev(string::iterator &iter) 
{
    char first = *iter;
    ++iter;
    if (first == 'b' || first == 'w') 
		return string(1, first);

    string str1 = rev(iter);
  //  cout<<"str1 = "<<str1<<"\n";
    string str2 = rev(iter);
   // cout<<"str2 = "<<str2<<"\n";
    string str3 = rev(iter);
    //cout<<"str3 = "<<str3<<"\n";
    string str4 = rev(iter);
 	//cout<<"str4 = "<<str4<<"\n";
 	
    return string("x") + str3 + str4 + str1 + str2;
}
 
int main(void)
{
    int n = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        cin >> s;
        string::iterator iter = s.begin();
        cout << rev(iter) << '\n';
    }
 
    return 0;
}

