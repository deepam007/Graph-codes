#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template<typename T>
class graph{
   public:
     map<T,list<T>> m;
   void AddEdge(T a,T b){
       m[a].push_back(b);
       m[b].push_back(a);
   }
   
   bfs(T source){
      map<T,ll> dist;
      queue<T> q;
      for(auto it:m){
          dist[it.first]=INT16_MAX;
      } 
      q.push(source);
      dist[source]=0;
      while(!q.empty()){
          T node=q.front();
          q.pop();
          for(T it:m[node]){
              if(dist[it]==INT16_MAX){
                  q.push(it);
                  dist[it]=dist[node]+1;
              }
          }
      }

      for(auto it:dist){
          cout<<"node "<<it.first<<" at dist  "<<it.second;
          cout<<endl;
      }
   }
};

int main(){
    graph<ll> g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    g.AddEdge(2,1);
    g.AddEdge(2,3);
    g.AddEdge(4,3);
    g.AddEdge(5,4);
    g.bfs(0);
    return 0;
}