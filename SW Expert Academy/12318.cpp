int check[11][11];
int m[11][11];
int queue[1000000];
int f,r;
int front(){
    return queue[f];
}

void pop(){
    f++;
    f%=1000000;
}

void push(int a){
    queue[r++] = a;
    r%=1000000;
}
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int N;
void bfs_init(int map_size, int map[10][10]) {
    N = map_size;
    for(int i=1;i<=map_size; i++){
        for(int j=1;j<=map_size; j++){
            check[i][j] = 0;
            m[j][i] = map[i-1][j-1];
        }
    }
    
}



int bfs(int x1, int y1, int x2, int y2) {
    for(int i=1;i<=N; i++){
        for(int j=1;j<=N; j++){
            check[i][j] = 0;
        }
    }
    f=0; r=0;
    push(x1);
    push(y1);
    push(0);
    check[x1][y1]=1;
    while(f!=r){
        //printf("=%d %d\n",f,r);
        int tmp1 = front();
        pop();
        int tmp2 = front();
        pop();
        int day = front();
        pop();
        //printf("==%d %d\n",tmp1,tmp2);
        if(x2 == tmp1 && y2 == tmp2)
            return day;
        for(int i=0; i<4; i++){
            int nx = tmp1+dir[i][0], ny = tmp2+dir[i][1];
            //printf("===%d %d\n",nx,ny);
            if( nx<1 || ny<1 || nx > N || ny>N || check[nx][ny] || m[nx][ny])
                continue;
            push(nx); push(ny); push(day+1);
            check[nx][ny]=1;
            //printf("push=%d %d\n",nx,ny);
        }
    }
    return-1;
}
