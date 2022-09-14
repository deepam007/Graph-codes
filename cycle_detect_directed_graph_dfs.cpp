#include<bits/stdc++.h>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)
#define endl '\n'
#define ll long long

class graph{
  public:
    map<ll,list<ll>> m;
  void AddEdge(ll a,ll b){
      m[a].push_back(b);
  }

  bool dfs(ll parent, map<ll,bool> &visited, bool *crnt_path){
      
      visited[parent]=true;
      crnt_path[parent]=true;
      
      for(ll child:m[parent]){
        //  cout<<parent<<"  ";
        //  for(ll i=0;i<m.size();i++) cout<<crnt_path[i]<<" ";
         
          if(crnt_path[child])return true;
          else if(!visited[child]){
          bool b=dfs(child,visited,crnt_path);
            if(b)return true;
          }
              
      }
      crnt_path[parent]=false;
      return false;

  }

  bool check_cycle(){
      map<ll,bool> visited;
      bool crnt_path[m.size()];
      for(ll i=0;i<m.size();i++)crnt_path[i]=false;
      return dfs(0,visited,crnt_path);
      

  }
 


};

int main()
{
    graph g;
    g.AddEdge(0,1);
    g.AddEdge(1,2);
     g.AddEdge(2,3);
    g.AddEdge(3,4);
    g.AddEdge(4,5);
    g.AddEdge(1,5);
    g.AddEdge(5,6);
    g.AddEdge(4,2);
    cout<<g.check_cycle();
    return 0;
}
