#include<iostream>
#include<vector>

using namespace std;

char tree[26][2];

void preorder(char a){
    if(a=='.'||a==0)
        return;
    cout<<a;
    preorder(tree[a-'A'][0]);
    preorder(tree[a-'A'][1]);
    
}

void inorder(char a){
    if(a=='.'||a==0)
        return;
    inorder(tree[a-'A'][0]);
    cout<<a;
    inorder(tree[a-'A'][1]);
    
}

void postorder(char a){
    if(a=='.'||a==0)
        return;
    postorder(tree[a-'A'][0]);
    postorder(tree[a-'A'][1]);
    cout<<a;
}


int main(){
    
    int N;
    cin>>N;
    while(N--){
        char A,B,C;
        cin>>A>>B>>C;
        tree[A-'A'][0] = B;
        tree[A-'A'][1] = C;
    }
    
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    
}
