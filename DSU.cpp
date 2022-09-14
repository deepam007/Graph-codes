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
   return find_set(parent[x],parent); 
 }
 void union_set(ll x,ll y,ll *parent){
    ll s1=find_set(x,parent);
    ll s2=find_set(y,parent);
    if(s1!=s2)parent[s2]=s1;
    return;
 }

 bool detect_cycle(){
     ll parent[m.size()];
     for(ll i=0;i<m.size();i++)parent[i]=-1;
     for(auto it:m){
        ll s1=find_set(it.first,parent);
         for(auto nbr:it.second){
            
            ll s2=find_set(nbr,parent);
            if(s1==s2)return true;
            union_set(it.first,nbr,parent);
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