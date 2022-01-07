#include<iostream>
#include<string>

using namespace std;

int N,flag=0;

void f(string a){
    //cout<<"["<<a<<"]\n";
    if(flag || a.length()>N)
        return;
    
    for(int cnt=2;cnt<=a.length();cnt+=2){
        for(int start = 0; start+cnt<=a.length(); start++){
            //cout<<a.substr(start, cnt/2)<<"/"<<a.substr(start+cnt/2,cnt/2)<<endl;
            if(a.substr(start, cnt/2).compare(a.substr(start+cnt/2,cnt/2))==0)
                return;
        }
    }
    
    
    if(a.length() == N){
        cout<<a;
        flag=1;
        return;
    }
    
    f(a+"1");
    f(a+"2");
    f(a+"3");
}

int main(){
    cin>>N;
//    string a="123123";
//    for(int cnt=2;cnt<=a.length();cnt+=2){
//        for(int start = 0; start+cnt<=a.length(); start++){
//            cout<<a.substr(start, cnt/2)<<" "<<a.substr(start+cnt/2,cnt/2)<<endl;
//        }
//    }
    f("1");
    
}
