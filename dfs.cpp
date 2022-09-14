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
   map<T,bool> visited;
   queue<T> q;
  void dfs(T source){
       visited[source]=true;
       cout<<source<<" ";
       for(auto it:m[source]){
           if(!visited[it])dfs(it);
       }
       return;
  }

};

int main(){

    graph<ll> g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    g.AddEdge(2,1);
    g.AddEdge(2,6);
    g.AddEdge(2,3);
    g.AddEdge(4,3);
    g.AddEdge(5,4);
    g.dfs(0);


    return 0;
}