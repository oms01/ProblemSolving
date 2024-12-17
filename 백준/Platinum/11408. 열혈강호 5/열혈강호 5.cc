#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 1'000;
vector<int> adj[MX];
int c[MX][MX], f[MX][MX], d[MX][MX];
void maxflow(int st, int en){
    int cnt = 0;
    int ans = 0;
    while(1){
        bool inq[MX]; fill(inq,inq+MX,0);
        int prev[MX]; fill(prev,prev+MX,-1);
        int dist[MX]; fill(dist,dist+MX,2e9);


        queue<int> q;
        q.push(st);
        dist[st] = 0;
        inq[st] = true;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            inq[cur] = false;
            for(auto nxt : adj[cur]){
                if(c[cur][nxt] - f[cur][nxt] > 0 && dist[cur] + d[cur][nxt] < dist[nxt]){
                    dist[nxt] = dist[cur] + d[cur][nxt];
                    prev[nxt] = cur;
                    if(!inq[nxt]){
                        q.push(nxt);
                        inq[nxt] = true;
                    }
                }
            }
        }
        if(prev[en]==-1) break;


        int flow = 2e9;
        
        for(int i=en;i!=st;i=prev[i]){
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        }
        for(int i=en;i!=st;i=prev[i]){
            ans += flow*d[prev[i]][i];
            f[prev[i]][i]+=flow;
            f[i][prev[i]]-=flow;
        }
        cnt++;
    }

    cout<<cnt<<' '<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    int st = 900;
    int en = 901;
    for(int i=1;i<=n;i++){
        c[st][i] = 1;
        adj[st].push_back(i);
        adj[i].push_back(st);
    }

    for(int i=1;i<=m;i++){
        c[400+i][en] = 1;
        adj[400+i].push_back(en);
        adj[en].push_back(400+i);
    }

    for(int i=1;i<=n;i++){
        int w; cin>>w;
        for(int j=0;j<w;j++){
            int num,cost; cin>>num>>cost;

            adj[i].push_back(400+num);
            adj[400+num].push_back(i);

            d[i][400+num] = cost;
            d[400+num][i] = -cost;

            c[i][400+num] = 1;
        }
    }
    maxflow(st,en);
}
