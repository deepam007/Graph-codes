#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template<typename T>
class graph{
   public:
    map<T,list<T>> m;
   
   void AddEdge(T a,T b){
      m[a].push_back(b);
   }
   
   void dfs(T src,map<T,bool> &visited,list<T> &topo_sort){
       visited[src]=true;
       for(auto node:m[src]){
           if(!visited[node])dfs(node,visited,topo_sort);
       }
       topo_sort.push_front(src);
       return;
   }
   void topological_sort_using_dfs(){
        list<T> topo_sort;
        map<T,bool> visited;
        for(auto it:m){
            if(!visited[it.first])dfs(it.first,visited,topo_sort);
        }
       
        // print topological sort
        for(auto it:topo_sort)cout<<it<<" ";
   }
   
};

int main(){
    graph<ll> g;
    g.AddEdge(1,2);
    g.AddEdge(1,3);
    g.AddEdge(2,4);
    g.AddEdge(3,4);
    g.AddEdge(3,5);
    g.AddEdge(4,6);
    g.topological_sort_using_dfs();
   
    return 0;
}