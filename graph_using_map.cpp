#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
  public:
    ll n;
    map<string,list<pair<string,ll>>> m;
    void Addedge(string x,string y,bool bidir,ll wt){
       m[x].push_back(make_pair(y,wt));
       if(bidir)m[y].push_back(make_pair(x,wt));
       

    }
    void printgraph(){
        for(auto it:m){
            cout<<it.first<<"->";
            for(auto x:it.second){
                cout<<x.first<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    graph g;
    g.Addedge("A","B",true,60);// 1st node,2nd node,bidirectional,weight
    g.Addedge("B","C",false,5);
    g.Addedge("C","X",true,20);
    g.Addedge("A","D",true,30);
    g.printgraph();
    return 0;
}