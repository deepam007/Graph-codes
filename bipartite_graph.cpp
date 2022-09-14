#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool dfs(vector<ll> *adjList,ll node,ll parent,ll *visited,ll color){
   
    visited[node]=color;
    for(auto nbr: adjList[node]){
        if(visited[nbr]==0){
            // cout<<node<<" "<<nbr<<endl;
            bool sub_graph=dfs(adjList,nbr,node,visited,3-color);
            if(!sub_graph)return false;
        }
        else if(nbr!=parent && visited[nbr]==color)return false;
    }

    return true;
}

void bipartite_using_dfs(vector<ll> *adjList,ll v){
    ll visited[v];  // 0,1,2 . 0 denotes not-visited, 1&2 reprsnt color
    for(ll i=0;i<v;i++)visited[i]=0;
    ll color=1;
    bool b=dfs(adjList,0,-1,visited,color); 
    if(b){
        for(ll i=0;i<v;i++)cout<<i<<" "<<visited[i]<<endl;
    }
    else cout<<"not bipartite";
    return ;
}

int main(){
    ll v,e;
    cin>>v>>e;
    vector<ll> adjList[v];  // undirected graph
    for(ll i=0;i<e;i++){
        ll x,y;
        cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    // for(ll i=0;i<v;i++){
    //     cout<<i<<"  ";
    //   for(auto nbr:adjList[i])cout<<nbr<<" ";
    //   cout<<endl;
    // }
    bipartite_using_dfs(adjList,v);
    return 0;
}