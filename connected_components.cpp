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

  void connected_comp(){
       map<T,bool> visited;
       auto it=m.begin();
       visited[it->first]=true;
       for(auto x:m){
           auto it=visited.find(x.first);
           if(it==visited.end()){
               for(auto d:visited){
                   cout<<d.first<<" ";
               }
               cout<<endl;
               visited.clear();
               
               visited[x.first]=true;
               for(ll y:x.second){
                   if(!visited[y])visited[y]=true;
               }
           }
           else {
               for(ll y:x.second){
                   if(!visited[y])visited[y]=true;
               }
           }
       }
       for(auto x:visited){
           cout<<x.first<<" ";
       }
  }
   

};

int main(){

    graph<ll> g;
    g.AddEdge(0,1);
    g.AddEdge(0,3);
    g.AddEdge(2,1);
    g.AddEdge(2,3);
    g.AddEdge(4,0);

    g.AddEdge(5,6);
    g.AddEdge(7,6);

    g.AddEdge(8,8);
   
    g.connected_comp();
    

    return 0;
}