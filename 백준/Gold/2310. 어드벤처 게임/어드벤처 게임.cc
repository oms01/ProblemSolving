#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

void solve(int n){
    vector<int> adj[1001];
    vector<char> room(n+1,0);
    vector<int> cost(n+1,0);
    REP(i,1,n){
        cin>>room[i]>>cost[i];
    
        int nxt;
        while(cin>>nxt){
            if(nxt==0) break;
            adj[i].push_back(nxt);
        }
    }

    adj[0].push_back(1);

    vector<int> vis(1001,-1);
    queue<int> q;
    q.push(0);
    vis[0] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(room[nxt]=='L'){
                if(vis[nxt] >= max(cost[nxt],vis[cur])) continue;
                vis[nxt] = max(cost[nxt], vis[cur]);
            }
            else if(room[nxt]=='T'){
                if(vis[cur]-cost[nxt] < 0) continue;
                if(vis[nxt] >= vis[cur]-cost[nxt]) continue;
                vis[nxt] = max(vis[nxt], vis[cur]-cost[nxt]);
            }
            else{
                if(vis[nxt] >= vis[cur]) continue;
                vis[nxt] = vis[cur];
            }
            q.push(nxt);
        }
    }
    cout<<(vis[n]==-1 ? "No\n" : "Yes\n");
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    while(cin>>n){
        if(n==0) break;
        solve(n);
    }

}