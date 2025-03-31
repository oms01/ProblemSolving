#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 100;
vector<int> adj[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    REP(i,1,n){
        vector<int> dist(n+1,2e9);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(dist[nxt]!=2e9) continue;
                dist[nxt] = dist[cur]+1;
                q.push(nxt);
            }
        }
        int mx = *max_element(dist.begin()+1,dist.end());
        if(mx > 6) return !(cout<<"Big World!\n");
    }

    cout<<"Small World!\n";
}
