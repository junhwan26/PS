#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    cin>>s;
    int flag=1, result=0, num=0;
    for(int i = 0; i < s.length() ; i++){
       
        if(s[i] == '+' || s[i] == '-'){
            result += num * flag;
            num=0;
        }
        else{
            num *= 10;
            num += s[i]-'0';
        }
        
        if(s[i] == '-')
            flag=-1;
        
        //cout<<num<<" "<<result<<endl;
        
    }
    
    result += num * flag;
    
    cout<<result;
}
