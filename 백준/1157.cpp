#include <iostream>
#include<string>
using namespace std;
int cnt[26];
string str;

int main(int argc, const char * argv[]) {
    
    cin >> str;
    for(int i=0;i<str.length();i++){
        if( str[i]>='a' && str[i]<='z'){
            cnt[int(str[i])-'a']++;
        }
        else{
            cnt[int(str[i])-'A']++;
        }
    }
    
    int max=-1,result=0;
    char maxi='?';
    for(int i=0;i<26;i++){
        if(cnt[i]>0 && max<cnt[i]){
            max=cnt[i];
            maxi=i+'A';
            result=1;
        }
        else if(max==cnt[i])
            result++;
        
           
    }
    if(result==1)
        cout<<maxi;
    else
        cout<<"?";
}
