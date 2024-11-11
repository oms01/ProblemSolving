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

const int MX = 2222;
vector<int> adj[MX];
int c[MX][MX], f[MX][MX], d[MX];
int maxflow(int st, int en){
    int ret = 0;
    while(1){
        memset(d,-1,sizeof(d));
        queue<int> q;
        q.push(st);
        bool flag = 0;
        while(!q.empty()){
            if(flag) break;
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                if(c[cur][nxt] - f[cur][nxt]>0 && d[nxt]==-1){
                    q.push(nxt);
                    d[nxt] = cur;
                    if(nxt == en){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if(d[en]==-1) break;
        int flow = 2e9;
        
        for(int i=en;i!=st;i=d[i]){
            flow = min(flow, c[d[i]][i]-f[d[i]][i]);
        }
        for(int i=en;i!=st;i=d[i]){
            f[d[i]][i]+=flow;
            f[i][d[i]]-=flow;
        }
        ret += flow;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    rep(i,4,n+4){
        int t; cin>>t;
        while(t--){
            int a; cin>>a;
            adj[i].push_back(a+n+3);
            adj[a+n+3].push_back(i);
            c[i][a+n+3] = 1;
        }
    }

    int st = 1;
    int en = 2;
    int tmp = 3;

    rep(i,4,n+4){
        adj[st].push_back(i); adj[i].push_back(st);
        c[st][i] = 1;
        adj[tmp].push_back(i); adj[i].push_back(tmp);
        c[tmp][i] = 1;
    }

    adj[st].push_back(tmp); adj[tmp].push_back(st);
    c[st][tmp] = k;
    
    rep(i,n+4,n+m+4){
        adj[i].push_back(en);
        c[i][en] = 1;
    }


    cout<<maxflow(1,2)<<'\n';
    
}
