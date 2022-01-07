#include<iostream>
#include<string>
#include<algorithm>


using namespace std;

int inorder[100000];
int postorder[100000];

void preorder(int istart, int iend, int pstart, int pend){
    //cout<<istart<<" "<<iend<<endl;
    if(istart > iend || pstart > pend)
        return;
    
    int root=istart;
    while(inorder[root]!=postorder[pend])
        root++;
    int len = root - istart - 1;
    
    cout<<postorder[pend]<<" ";
    preorder(istart, root-1, pstart, pstart+len);
    preorder(root+1, iend, pstart+len+1, pend-1);
}

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>inorder[i];
            
    }
    
    for(int i=0;i<N;i++){
        string tmp;
        cin>>postorder[i];
    }
    preorder(0,N-1,0,N-1);
}
