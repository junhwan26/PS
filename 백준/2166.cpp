#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

double dot[10000][2];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dot[i][0]>>dot[i][1];
    }
    double ans=0;
    double x1=dot[0][0], y1=dot[0][1];
    
    for(int i=1;i<n-1;i++){
        double x2= dot[i][0], y2= dot[i][1], x3=dot[i+1][0], y3=dot[i+1][1];
        ans += (x2-x1)*(y3-y1) - (x3-x1)*(y2-y1);
    }
    printf("%.1lf",abs(ans)/2);
    
}

