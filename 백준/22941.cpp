#include<iostream>

using namespace std;
int main(){
    long long HP_H, ATK_H, HP_D, ATK_D;
    cin>>HP_H>>ATK_H>>HP_D>>ATK_D;
    
    long long P,S;
    cin>>P>>S;
    
    //영웅이 죽는 턴
    long long TURN_H = (HP_H%ATK_D == 0) ?  HP_H/ATK_D :  HP_H/ATK_D+1;
    // 마왕이 죽는 턴
    long long TURN_D;
    if(HP_D%ATK_H > P || (ATK_H>P && HP_D%ATK_H == 0))
        TURN_D = (HP_D%ATK_H == 0) ? HP_D/ATK_H : HP_D/ATK_H+1;
    else{
        HP_D+=S;
        TURN_D = (HP_D%ATK_H == 0) ? HP_D/ATK_H : HP_D/ATK_H+1;
    }
    //cout<<TURN_H<<" "<<TURN_D<<endl;
    if(TURN_H >= TURN_D)
        cout<<"Victory!";
    else
        cout<<"gg";
}

