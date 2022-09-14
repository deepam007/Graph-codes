#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class DSU{
    public:
     ll *parent;
     ll *rank;
    DSU(ll x){
        parent=new ll[x];
        rank=new ll[x];
        for(ll i=0;i<x;i++){
            parent[i]=-1;
            rank[i]=1;
        }
    }
    ll find_set(ll x){
        if(parent[x]==-1)return x;
        return parent[x]=find_set(parent[x]);
    }
    void union_set(ll x,ll y){
        ll s1=find_set(x);
        ll s2=find_set(y);
        if(s1!=s2){
            if(rank[s1]<rank[s2]){
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else{
               parent[s2]=s1;
               rank[s1]+=rank[s2];
            }
        }
        return;
    }
   
};

class graph{
  public:
   ll v;
   vector<vector<ll>> edgelist;     //vector<vector<wt,x,y>>
   graph(ll x){
       v=x;
   }
  void AddEdge(ll x,ll y,ll wt){
      edgelist.push_back({wt,x,y});
  }

  // kruskal's Algo......
  ll kruskal(){
     DSU s(v);
     ll total_wt=0;
     sort(edgelist.begin(),edgelist.end());
    for(auto edge:edgelist){
       ll wt=edge[0];
       ll x=edge[1];
       ll y=edge[2];
       
       if(s.find_set(x)!=s.find_set(y)){
          // cout<<x<<" "<<y<<endl;
           s.union_set(x,y);
           total_wt+=wt;
       }
       
    }
    return total_wt;
  }
};

int main(){
      graph g(7)    ;
    g.AddEdge(0, 1, 14);  // x,y, wt
    g.AddEdge(0, 2, 21);
    g.AddEdge(0, 3, 5);
    g.AddEdge(0, 5, 7);
    g.AddEdge(1, 2, 15);
    g.AddEdge(1, 5, 2);
    g.AddEdge(1, 6, 19);
    g.AddEdge(2, 4, 4);
    g.AddEdge(2, 6, 3);
    g.AddEdge(3, 4, 22);
    g.AddEdge(3, 5, 13);
    g.AddEdge(4, 5, 15);
    g.AddEdge(4, 6, 2);
    g.AddEdge(5, 6, 18);
    cout<<"The cost of MST is:  "<<g.kruskal();
    return 0;
}