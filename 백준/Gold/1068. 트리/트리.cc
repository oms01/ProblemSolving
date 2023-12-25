#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<ll,ll> pii;
int n;
bool active[51];
int parent[51];
vector<int> adj[51];
int root;
void func(int v){
    active[v] = 0;
    for(auto nxt : adj[v]){
        func(nxt);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        active[i] = 1;
        parent[i] = p;
        if(p==-1) root = i; 
        else adj[p].push_back(i);
    }
    int v;
    cin>>v;
    if(v!=root) adj[parent[v]].erase(find(adj[parent[v]].begin(),adj[parent[v]].end(), v));
    func(v);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(!adj[i].empty() || !active[i]) continue;
        ans++;
    }
    cout<<ans<<'\n';
}