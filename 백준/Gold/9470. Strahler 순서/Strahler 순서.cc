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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int k,m,p; cin>>k>>m>>p;
        vector<int> adj[1001];
        vector<int> strahler(1001,0);
        vector<int> in[1001];
        vector<int> deg(1001,0);
        rep(i,0,p){
            int s,e; cin>>s>>e;
            adj[s].push_back(e);
            deg[e]++;
        }
        queue<int> q;
        rep(i,1,m+1){
            if(deg[i]) continue;
            q.push(i);
            strahler[i]=1;
        }

        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]){
                in[nxt].push_back(strahler[cur]);
                if(--deg[nxt]) continue;
                q.push(nxt);
                int mx = *max_element(all(in[nxt]));
                int cnt=0;
                for(auto x : in[nxt]){
                    cnt+=(x==mx);
                }
                if(cnt>1) strahler[nxt] = mx+1;
                else strahler[nxt] = strahler[cur];

            }
        }
        cout<<k<<' '<<*max_element(all(strahler))<<'\n';
    }

}