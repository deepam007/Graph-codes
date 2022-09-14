#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
  public:
   vector<pair<ll,ll>> *adjList;  // adjList[x].({y,wt},{z,wt}..)
   ll v;
  graph(ll x){
      v=x;
      adjList=new vector<pair<ll,ll>>[v];
  }
  void addEdge(ll x,ll y,ll wt){
      adjList[x].push_back({y,wt});
      adjList[y].push_back({x,wt});
  }
  void dijkstra(ll src){
      priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,   // (wt,node)
                    greater<pair<ll,ll>>> q;
      ll dist[v];
      for(ll i=0;i<v;i++)dist[i]=INT16_MAX;
      dist[src]=0;
      q.push({0,src});
      while(!q.empty()){
          ll node=q.top().second;
          ll distance=q.top().first;
          q.pop();
          for(auto nbr: adjList[node]){
              if(dist[nbr.first]>(dist[node]+nbr.second)){
                   dist[nbr.first]=(dist[node]+nbr.second);
                   q.push({dist[nbr.first],nbr.first}); //(wt,node)
              }
          }
      }   

      // print 
      for(ll i=0;i<v;i++)cout<<"node num: "<<i<<" "<<" dist from src 0: "<<dist[i]<<endl;
  }

};


int main(){
     graph g(9);

    g.addEdge( 0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.dijkstra(0);
    return 0;
}