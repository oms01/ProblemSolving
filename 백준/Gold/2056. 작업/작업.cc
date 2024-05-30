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
vector<int> adj[10'001];
int deg[10'001];
int work[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1){
        cin>>work[i]>>deg[i];
        rep(j,0,deg[i]){
            int x; cin>>x;
            adj[x].push_back(i);
        }
    }

    queue<int32_t> q;
    vector<int> v(10'001,0);
    rep(i,1,n+1){
        if(!deg[i]) q.push(i);
        v[i] = work[i];
    }   
    int ans = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt : adj[cur]){
            v[nxt] = max(v[nxt], v[cur] + work[nxt]);
            if(--deg[nxt]) continue;
            q.push(nxt);
        }
    }
    cout<<*max_element(all(v));
}