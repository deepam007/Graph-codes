#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void floyd_marshall(vector<vector<ll>> &dist){
   ll v=dist.size();
   for(ll i=0;i<v;i++){   // v times for each D^i
     
      for(ll j=0;j<v;j++){
          if(i==j)continue;
          for(ll k=0;k<v;k++){
             if(i==k)continue;
             if(dist[j][i]!=INT16_MAX && dist[i][k]!=INT16_MAX &&
                        dist[j][k]>(dist[j][i]+dist[i][k]))
                        
                dist[j][k]=(dist[j][i]+dist[i][k]);
          }
      }
   }

}

int main(){
    vector<vector<ll>> dist={
                        {0, 4, 3, INT_MAX, INT_MAX, INT_MAX, INT_MAX},
						{4, 0, INT_MAX, INT_MAX, 12, 5, INT_MAX},
						{3, INT_MAX, 0, 7, 10, INT_MAX, INT_MAX},
						{INT_MAX, INT_MAX, 7, 0, 2, INT_MAX, INT_MAX},
						{INT_MAX, 12, 10, 2, 0, INT_MAX, 5},
						{INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX, 0, 16},
						{INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 16, 0}
					};
    floyd_marshall(dist);
    for(auto it: dist){
        for(auto node: it) cout<<node<<" ";
        cout<<endl;
    } 
    return 0;
}