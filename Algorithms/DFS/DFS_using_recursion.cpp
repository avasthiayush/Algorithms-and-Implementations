/*
  Time complexity: O(V+E)
  Space Complexity: O(V) ->(extra visited array is needed of size V)
*/

#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mp make_pair
#define pll pair<ll,ll>
#define f first
#define s second
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll vis[1000000];

void addEdge(vector<ll>adj[], ll a, ll b){
    adj[a].pb(b);
    adj[b].pb(a);
}

void DFS(ll p, vector<ll>adj[]){
    vis[p]=1;
    for(ll i=0;i<adj[p].size();i++){
        if(vis[adj[p][i]]==0){
            cout<<adj[p][i]<<" ";
            DFS(adj[p][i],adj);
        }
    }
}

int main(){
    fio;
    ll n=7;
    memset(vis,0,sizeof(vis));
    vector<ll> adj[n+1];                                     
    addEdge(adj,1,2);                                    
    addEdge(adj,2,5);                                   
    addEdge(adj,1,6);                                  
    addEdge(adj,2,7);                                    
    addEdge(adj,5,4);                                
    addEdge(adj,5,6);                               
    addEdge(adj,6,3);                                                                   
    cout<<"DFS starting from node 3:\n";
    cout<<"3 ";
    DFS(3,adj);
    return 0;
}

/*                                                                                    1
                                                                                     / \
                                                                                    /   \
OUTPUT                                                                             2     6
DFS starting from node 3:                                                         / \   / \
3 6 1 2 5 4 7                                                                    7    5    3
                                                                                      |
                                                                                      4 
*/
