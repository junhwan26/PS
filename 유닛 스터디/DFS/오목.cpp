#include <iostream>
#include<stdio.h>
#include<vector>

int in[20][20];
int check[20][20];
int dir[4][2]= {{0,1},{1,0},{1,1},{-1,1}};
int chk[4][2]={{0,-1},{-1,0},{-1,-1},{1,-1}};
int cnt[4];

using namespace std;

void f(int a, int b, int c)
{
    check[a][b]=1;
    int i;
    if(c==-1)
        for(i=0; i<4; i++)
        {
            int na = a+dir[i][0],nb = b+dir[i][1];
            int pa=a+chk[i][0], pb=b+chk[i][1];
            if(na<1||nb<1||na>=20||nb>=20||in[na][nb]==0||in[pa][pb]==in[a][b])
                continue;
            if(in[na][nb]==in[a][b])
            {
                cnt[i]+=2;
             //  printf("%d %d cnt[%d]=%d\n",na,nb,i,cnt[i]);
                f(na,nb,i);

            }
        }
    else
    {
        int na=a+dir[c][0],nb=b+dir[c][1];
        if(na<1||nb<1||na>=20||nb>=20||in[na][nb]==0)
            return;
        if(in[na][nb]==in[a][b])
        {
            cnt[c]++;
           // printf("%d %d cnt[%d]=%d\n",na,nb,c,cnt[c]);
            f(na,nb,c);
        }
    }
}

int main()
{
    int n,i,j;
    for(i=1; i<20; i++)
        for(j=1; j<20; j++)
            scanf("%d",&in[i][j]);
            
    int flag=0;
    for(i=1; i<=19; i++)
    {
        for(j=1; j<=19; j++)
        {
            if(in[i][j]==0)
                continue;
            cnt[0]=0;cnt[1]=0;cnt[2]=0;cnt[3]=0;
           // printf("%d %d\n",i,j );
            f(i,j,-1);
            if(cnt[0]==5||cnt[2]==5||cnt[1]==5||cnt[3]==5)
            {
                printf("%d\n%d %d",in[i][j],i,j);
                flag=1;
            }

        }
    }
    if(flag==0)
        printf("0");
}


