#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stack>

using namespace std;
string map[10];
int check[10][10];
int dir[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
int dir2[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};


bool compare(pair<int, int>a, pair<int, int>b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}

vector<pair<int, int>> v,d;
stack<pair<int, int >> st;



int triangletest(){
    int last = 3;
    for(int i=0;i<3;i++){
        for(int j=i+1;j<3;j++){
            if(v[i].first == v[j].first){
                //cout<<"type1"<<endl;
                last = last - i - j;
                int length = v[j].second - v[i].second;
                //cout<<"length : "<<length<<endl;
                if((v[i].second+v[j].second)/2 == v[last].second && abs(v[i].first - v[last].first) == length/2 ){
                    return 1;
                }
                else{
                    if((v[i].second==v[last].second || v[j].second == v[last].second) && length == abs(v[j].first - v[last].first))
                        return 1;
                    return 0;
                }
            }
            if(v[i].second == v[j].second){
                last = last - i - j;
                int length = v[j].first - v[i].first;
                
                if((v[i].first+v[j].first)/2 == v[last].first && abs(v[i].second - v[last].second) == length/2 ){
                    return 1;
                }
                else{
                    if((v[i].first==v[last].first || v[j].first == v[last].first) && length == abs(v[j].second - v[last].second))
                        return 1;
                    return 0;
                }
            }
        }
    }
    return 1;
}

int main(){
    
    for(int i=0;i<10;i++)
        cin>>map[i];
    
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(!check[i][j]&&map[i][j] == '1')
            {
                st.push(make_pair(i, j));
                check[i][j] = 1;
                
                while(!st.empty())
                {
                    int a = st.top().first, b = st.top().second;
                    st.pop();
                    int cnt = 0;
                    for(int k = 0; k<8;k++)
                    {
                        int na=a+dir[k][0], nb=b+dir[k][1];
                        
                        if(na<0 || nb <0 || na>=10 || nb>=10 )
                        {
                            cnt++;
                            continue;
                        }
                        
                        if(map[na][nb] == '1')
                        {
                            if(!check[na][nb])
                            {
                                st.push(make_pair(na, nb));
                                check[na][nb] = 1;
                            }
                        }
                        else{
                            cnt++;
                        }
                    }
                    
                    if(cnt>=5 ){
                        cnt=0;
                        for(int k=0;k<4;k++){
                            int na=a+dir[k][0], nb=b+dir[k][1];
                            
                            if(na<0 || nb <0 || na>=10 || nb>=10 )
                            {
                                continue;
                            }
                            
                            if(map[na][nb] == '0')
                            {
                                if(!check[na][nb])
                                {
                                    st.push(make_pair(na, nb));
                                    check[na][nb] = 1;
                                }
                            }
                            else{
                                cnt++;
                            }
                        }
                        if(cnt<=2)
                            v.push_back(make_pair(a, b));
                    }
                }
            }
            
            if(!check[i][j]&&map[i][j] == '0')
            {
                st.push(make_pair(i, j));
                check[i][j] = 1;
                
                while(!st.empty())
                {
                    int a = st.top().first, b = st.top().second;
                    st.pop();
                    int cnt = 0;
                    for(int k = 0; k<8;k++)
                    {
                        int na=a+dir[k][0], nb=b+dir[k][1];
                        
                        if(na<0 || nb <0 || na>=10 || nb>=10 )
                        {
                            continue;
                        }
                        
                        if(map[na][nb] == '0')
                        {
                            if(!check[na][nb])
                            {
                                st.push(make_pair(na, nb));
                                check[na][nb] = 1;
                            }
                        }
                        else{
                            cnt++;
                        }
                    }
                    
                    if(cnt>=5 ){
                        d.push_back(make_pair(a, b));
                    }
                }
            }
        }
    }
    
    sort(v.begin(),v.end());
//    for(int i=0;i<v.size();i++){
//        cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
//    }
//    cout<<endl;
//    for(int i=0;i<d.size();i++){
//        cout<<d[i].first+1<<" "<<d[i].second+1<<endl;
//    }
    if(v.size() != 3 || !triangletest() || d.size()>0){
//        if(v.size()!=3)
//            cout<<"점개수 아님"<<endl;
//        else if(!triangletest())
//            cout<<"삼각형테스트 오류"<<endl;
//        else
//            cout<<"구멍"<<endl;
        cout<<0;
    }
    else{
        for(int i=0;i<v.size();i++){
            cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
        }
    }
    
}

/*
0000000000
0000000000
1111110000
0111110000
0011110000
0001110000
0000110000
0000000000
0000000000
0000000000
 */

/*
0000000000
0000000000
0011100000
0001000000
0001000000
0000000000
0000000000
0000000000
0000000000
0000000000
 */


/*
0000000000
0000000000
1000000000
1100000000
1110000000
1111000000
1111100000
1111111000
0000000000
0000000000
 */
