#include<iostream>
#include<string>
using namespace std;

string A,B;
using namespace std;
int main(){
    cin>>A>>B;
    int i=0, j=0, k=0;
    //cout<<"i j\n";
    while(i<A.size() && j <B.size()){
        //cout<<A[i]<<" "<<B[j]<<endl;
        if('0' <= A[i] && A[i] <= '9')
            i++;
        else {
            if(A[i] != B[j]){
                j=0;
                k++;
                i=k;
            }
            else{
                j++;
                i++;
            }

        }
    }
    
    if(j==B.size())
        cout<<1;
    else
        cout<<0;
}
