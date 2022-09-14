#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
  public:
   map<ll,list<ll>> m;
  void AddEdge(ll a,ll b){
      m[a].push_back(b);
      m[b].push_back(a);
  }

  bool dfs(ll node,map<ll,bool> &visited,map<ll,ll> &child_parent){
        visited[node]=true;
        for(auto nbr:m[node]){
           if(visited[nbr] && 
            child_parent[node]!=nbr){
             //   cout<<node<<" "<<nbr;   
                return true;}
           
           else if(!visited[nbr]){
               child_parent[nbr]=node;
            bool b= dfs(nbr,visited,child_parent);
            if(b)return true;
         }
        }
     return false;
  }

  bool cycle_detect(){
      map<ll,bool> visited;
      map<ll,ll> child_parent;  //map(chil,parent)
      auto it=m.begin();
     return dfs(it->first,visited,child_parent);

  }

};

int main(){
    graph g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
    g.AddEdge(2,3);
    g.AddEdge(3,0);
    cout<<g.cycle_detect();
    return 0;

}