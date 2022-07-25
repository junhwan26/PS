int stack[100];
int curr = 0;

void pop(){
    curr--;
}
int top(){
    return stack[curr-1];
}
void push(int n){
    stack[curr++] = n;
}

int tree[101][6];
void dfs_init(int N, int path[100][2])
{
    for(int i=0;i<=100;i++){
        for(int j=0; j<=5;j++)
            tree[i][j] = 0;
    }
        
    for(int i=0;i<N-1;i++){
//        printf("%d %d\n",path[i][0], path[i][1]);
        tree[path[i][0]][++tree[path[i][0]][0]] =path[i][1];
    }
//    for(int i=0;i<=100;i++){
//        if(tree[i][0]==0)
//            continue;
//        printf("#%d",i);
//        for(int j=0; j<=5;j++)
//            printf("%5d ", tree[i][j]);
//        printf("\n");
//    }
        
            

}


int dfs(int n)
{
    curr=0;
    push(n);
    while(curr>0){
        int tmp = top();
        pop();
        if(tmp>n)
            return tmp;
        for(int i=tree[tmp][0];i>0;i--)
            push(tree[tmp][i]);
    }
    return -1;
}
