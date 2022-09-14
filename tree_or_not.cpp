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

  bool detect_tree(){
      bool b=true;
      map<ll,bool> visited;
      ll parent_child[m.size()];
      auto it=m.begin();
      queue<ll> q;
      // start with first node
      q.push(it->first);
      visited[it->first]=true;
    
      while(!q.empty()){
          if(!b)break;
          ll parent=q.front();
          q.pop();
          for(ll child:m[parent]){
              if(!visited[child]){
                  q.push(child);
                  visited[child]=true;
                  parent_child[child]=parent;
              }
              else if(visited[child] && parent_child[parent]!=child){
                 
                  b=false;
                  break;
              }
          }
      }
      return b;

  }

};

int main(){
     graph g;
     g.AddEdge(0,1);
     g.AddEdge(0,2);
     g.AddEdge(3,1);
     g.AddEdge(2,3);
    if(g.detect_tree())cout<<"tree";
     else cout<<"no";
    return 0;
}