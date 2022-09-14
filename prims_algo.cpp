#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
  public:
   ll vrtx;
   vector<pair<ll,ll>> *adjList;  // v[x]({y,wt},{z,wt}...)
  graph(ll x){
      vrtx=x;
      adjList=new vector<pair<ll,ll>>[x];
  }
  void AddEdge(ll x,ll y,ll wt){
     adjList[x].push_back({y,wt});
     adjList[y].push_back({x,wt});
  }
  

  // PRIM'S ...
  ll prims(){
   
    priority_queue<pair<ll,ll>, 
        vector<pair<ll,ll>>, greater<pair<ll,ll>>> q;  //({wt,node})
    ll visited[vrtx];
    for(ll i=0;i<vrtx;i++)visited[i]=0;
      // startng with source node (wt,node)
     ll total_wt=0;

     q.push({0,0});
     while(!q.empty()){
       ll node=q.top().second;
       ll wt=q.top().first;
       q.pop();
       if(visited[node]==1){
         continue; // visited i.e. already in mst
       }
       visited[node]=1;
       total_wt+=wt;
       for(auto nbr:adjList[node]){
         if(visited[nbr.first]==0)
         q.push({nbr.second,nbr.first}); // q contains (wt,node)
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
    cout<<"The cost of MST is:  "<<g.prims();
    return 0;
}