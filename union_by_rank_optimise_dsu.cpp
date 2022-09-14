#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class graph{
 public:
  map<ll,list<ll>> m;
 void addEdge(ll a,ll b){
     m[a].push_back(b);
 }
 ll find_set(ll x,ll *parent){
   if(parent[x]==-1)return x;
   // optimisation
   return parent[x]=find_set(parent[x],parent); 
 }
 void union_set(ll x,ll y,ll *parent,ll *rank){
    ll s1=find_set(x,parent);
    ll s2=find_set(y,parent);
    if(s1!=s2){
        if(rank[s1]>rank[s2]){
            rank[s1]+=rank[s2]; // no need to change rank of s2 
                                // i.e node having lower rank
            parent[s2]=s1;
        }
        else{
            rank[s2]+=rank[s1];
            parent[s1]=s2;
        }
    }
    return;
 }

 bool detect_cycle(){
     ll parent[m.size()];
     // rank array
     ll rank[m.size()];
     for(ll i=0;i<m.size();i++){
         parent[i]=-1;  rank[i]=1;
     } 
     for(auto it:m){
         for(auto nbr:it.second){
            ll s1=find_set(it.first,parent);
            ll s2=find_set(nbr,parent);
            if(s1==s2)return true;
            union_set(it.first,nbr,parent,rank);
         } 
     }
     return false;
     
 }
 
};

int main(){
    graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    cout<<g.detect_cycle();
    return 0;
}