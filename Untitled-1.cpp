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
   vector<vector<ll>> edgelist;     //vector<vector<wt,x,y>>
  void AddEdge(ll x,ll y,ll wt){
      edgelist.push_back({wt,x,y});
  }

  // kruskal's Algo......
  ll kruskal(){
     DSU s(edgelist.size());
     ll total_wt=0;
     sort(edgelist.begin(),edgelist.end());
    for(auto edge:edgelist){
       ll wt=edge[0];
       ll x=edge[1];
       ll y=edge[2];
       
       if(s.find_set(x)!=s.find_set(y)){
           s.union_set(x,y);
           total_wt+=wt;
       }
       return total_wt;
    }
  
  }

  

};

int main(){
     graph g;
     g.AddEdge(0,1,1);    // x,y,wt
     g.AddEdge(1,3,3);
     cout<<g.kruskal();
    return 0;
}