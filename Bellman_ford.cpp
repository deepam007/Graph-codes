#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<ll> bellman(ll v,ll src, vector<vector<ll>> edgeList){
   vector<ll> dist(v+1,INT16_MAX);  // nodes starts from 1 not 0 (1,2,3,...)
   dist[src]=0;

   // relaxing v-1 times
   for(ll i=0;i<v-1;i++){
       for(auto edge:edgeList){
           ll u=edge[0];
           ll v=edge[1];
           ll wt=edge[2];
           
           if(dist[u]!=INT16_MAX && dist[v]>dist[u]+wt)
              dist[v]=dist[u]+wt;
       }
        
      //  cout<<endl;
   }
    
    // -ve wt cycle detection
    for(auto edge:edgeList){
           ll u=edge[0];
           ll v=edge[1];
           ll wt=edge[2];
            
         if(dist[u]!=INT16_MAX && dist[v]>(dist[u]+wt)){
             cout<<"Negative wt cycle ";
             return dist;
         }
    }
   return dist;
}

int main(){
    int v,e; 
    cin>>v>>e;  // vrtx,edges
    vector<vector<ll>> edgeList;
    for(ll i=0;i<e;i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        edgeList.push_back({x,y,wt});
    }
    ll src;
    cin>>src;
    vector<ll> dist=bellman(v,src,edgeList);
    for(int i=1;i<dist.size();i++){
        cout<<"node num: "<<i<<" dist from src: 1  "<<dist[i]<<endl;
    }
    return 0;
}

// 3 3
// 1 2 3
// 2 3 4
// 3 1 -10
// 1
