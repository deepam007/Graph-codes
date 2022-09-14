#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void flood_fill(vector<vector<char>> &v,ll x,ll y, char color){
    if(x<0 || x>=v.size() || y<0 || y>=v[x].size())return;
    if(v[x][y]!='.')return;
    v[x][y]='b';
    flood_fill(v,x-1,y,color);
    flood_fill(v,x+1,y,color);
    flood_fill(v,x,y-1,color);
    flood_fill(v,x,y+1,color);
    return;
}

int main(){

    vector<vector<char>> v(10);
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++){
            char c;
            cin>>c;
            v[i].push_back(c);
        }
    }
    flood_fill(v,0,0,'b');
    for(ll i=0;i<10;i++){
        for(ll j=0;j<10;j++)cout<<v[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}