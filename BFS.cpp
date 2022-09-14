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

   void bfs(T source){
     queue<T> q;
     map<T,bool> visited;
     q.push(source);
     visited[source]=true;
     while(!q.empty()){
       T crnt=q.front();
       q.pop();
       cout<<crnt<<" ";
       for(T it:m[crnt]){       // m[crnt] gives next element of list every time
         if(!visited[it]){       // checking the node in visited map
           q.push(it);
           visited[it]=true;
         }      
       }
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