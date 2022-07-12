#include<iostream>
#include<string>
#include<stack>
#include<stdio.h>
using namespace std;

stack<double> st;
double map[26];

int is_alpha(char a){
    if(a>='A' && a<='Z')
        return 1;
    return 0;
}

double calc(double a, double b, char c){
    if(c == '+')
        return b+a;
    if(c == '-')
        return b-a;
    
    if(c == '*')
        return a*b;
        
    if(c == '/')
        return b/a;
    return 0;
}

int main(){
    int N;
    string A;
    cin>>N;
    cin>>A;
    for(int i=0;i<N;i++)
        cin>>map[i];
    for(int i=0;i<A.size();i++){
        if(is_alpha(A[i]))
            st.push(map[A[i]-'A']);
        else{
            double a = st.top();
            st.pop();
            double b = st.top();
            st.pop();
            st.push(calc(a, b, A[i]));
        }
    }
    
    printf("%.2f", st.top());
}
