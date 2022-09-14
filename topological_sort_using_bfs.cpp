#include<bits/stdc++.h>
using namespace std;
#define ll long long int

template <typename T>
class graph{
    public:
     map<T,list<T>> m;
    void AddEdge(T a,T b){
       m[a].push_back(b);
    }
    void topo_sort_using_bfs(){
       list<T> topo_sort;
       map<T,T> degree;
       for(auto it:m){
           degree[it.first]=0;
       }
       for(auto it:m){
           for(auto node:it.second){
               degree[node]++;
           }
       }
       while(!degree.empty()){
           for(auto it:degree){
               if(it.second==0){
                  // cout<<it.first<<" ";
                   topo_sort.push_back(it.first);
                   for(auto x:m[it.first])degree[x]--;
                   degree.erase(it.first);
                   break;
               }

           }
       }
       // print list
       for(auto it:topo_sort)cout<<it<<" ";
    }



}; 

int main(){
    graph<char> g;
    g.AddEdge('A','C');
    g.AddEdge('A','D');
    g.AddEdge('B','D');
    g.AddEdge('B','E');
    g.AddEdge('D','F');
    g.AddEdge('D','G');
    g.AddEdge('G','I');
    g.AddEdge('H','I');
    
    g.topo_sort_using_bfs();
    return 0;
}