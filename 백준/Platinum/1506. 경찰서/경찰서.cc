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

vector<int> adj[100'001];
int n,m;
int vis[100'001];
stack<int> s;
vector<vector<int>> scc;

int isScc[100'001];
int num;
int dfs(int i){ //타잔
    vis[i] = ++num;
    s.push(i);
    int p = vis[i];
    for(auto nxt : adj[i]){
        if(!vis[nxt]) p = min(p, dfs(nxt));
        if(!isScc[nxt]) p = min(p,vis[nxt]);
    }
    if(p==vis[i]){
        vector<int> v;
        while(1){
            int cur = s.top(); s.pop();
            isScc[cur] = 1;
            v.push_back(cur);
            if(cur==i) break;
        }
        sort(all(v));
        scc.push_back(v);
    }
    return p;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    vector<int> v(n+1,0);
    rep(i,1,n+1) cin>>v[i];

    rep(i,1,n+1){
        string str; cin>>str;
        rep(j,0,n){
            if(str[j]=='1') adj[i].push_back(j+1);
        }
    }


    rep(i,1,n+1){
        if(!vis[i]) dfs(i);
    }
    sort(all(scc));

    int ans = 0;
    rep(i,0,scc.size()){
        int mn = 2e9;
        for(auto x : scc[i]){
            mn = min(mn,v[x]);
        }
        ans += mn;
    }
    cout<<ans<<'\n';

}