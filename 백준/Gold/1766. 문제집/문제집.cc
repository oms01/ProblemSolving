#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

vector<int> adj[32'001];
int deg[32'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[s].push_back(e);
        deg[e]++;
    }

    priority_queue<int, vector<int>, greater<>> pq;
    rep(i,1,n+1){
        if(!deg[i]) pq.push(i);
    }

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        cout<<cur<<' ';
        for(auto nxt : adj[cur]){
            if(--deg[nxt]) continue;
            pq.push(nxt);
        }
    }
    cout<<'\n';


}