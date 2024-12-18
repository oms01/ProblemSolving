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

const int MX = 1'002;
const int ST = MX-2;
const int EN = MX-1;
const int MID = (MX-2)/2;
vector<int> adj[MX];
int c[MX][MX], f[MX][MX], d[MX][MX]; //용량, 흐름, 비용
void maxflow(int st, int en){
    int cnt = 0;
    int ans = 0;
    while(1){
        bool inq[MX]; fill(inq,inq+MX,0); //큐 안에 있는지
        int prev[MX]; fill(prev,prev+MX,-1); //이전 노드
        int dist[MX]; fill(dist,dist+MX,2e9); //st부터의 거리

        queue<int> q;
        q.push(st);
        dist[st] = 0;
        inq[st] = true;
        
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            inq[cur] = false;
            for(auto nxt : adj[cur]){

                //잔여 용량이 있고, 지금까지 찾은 경로보다 더 짧은 경우
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


        // 최대로 흘릴 수 있는 양 계산
        int flow = 2e9;
        for(int i=en;i!=st;i=prev[i]){
            flow = min(flow, c[prev[i]][i]-f[prev[i]][i]);
        }

        for(int i=en;i!=st;i=prev[i]){
            ans += d[prev[i]][i]*flow;
            f[prev[i]][i]+=flow;
            f[i][prev[i]]-=flow;
        }
        cnt+=flow;
    }
    cout<<cnt<<' '<<-ans<<'\n';
}
int CCW(pll a, pll b, pll c){
    ll ret = (b.X*(c.Y-a.Y))+(a.X*(b.Y-c.Y))+(c.X*(a.Y-b.Y));
    return !ret ? 0 : (ret<0 ? -1 : 1);
}
bool isCross(pair<pii,pii> ve, pair<pii,pii> ho){
    return (CCW(ve.X,ve.Y,ho.X)!=CCW(ve.X,ve.Y,ho.Y) 
        && CCW(ho.X,ho.Y,ve.X)!=CCW(ho.X,ho.Y,ve.Y));
}

void solve(){

    rep(i,0,MX) adj[i].clear();
    memset(c,0,sizeof(c)); memset(f,0,sizeof(f)); memset(d,0,sizeof(d));

    int n,m; cin>>n>>m;

    vector<pair<pii,pii>> vertical(n), horizontal(m);
    vector<int> costH(m);
    vector<int> costV(n);
    rep(i,0,n){
        int x1,y1,x2,y2,w;
        cin>>x1>>y1>>x2>>y2>>w;
        vertical[i] = {{x1,y1},{x2,y2}};
        costV[i] = w;

        c[ST][i] = 1;
        adj[ST].push_back(i);
        adj[i].push_back(ST);
    }

    rep(i,0,m){
        int x1,y1,x2,y2,w;
        cin>>x1>>y1>>x2>>y2>>w;
        horizontal[i] = {{x1,y1},{x2,y2}};
        costH[i] = w;


        c[MID+i][EN] = 1;
        adj[EN].push_back(MID+i);
        adj[MID+i].push_back(EN);
    }
    
    rep(i,0,n) rep(j,0,m){
        if(!isCross(vertical[i],horizontal[j])) continue;

        d[i][MID+j] = -costV[i]*costH[j];
        d[MID+j][i] = -d[i][MID+j];

        c[i][MID+j] = 1;

        adj[i].push_back(MID+j);
        adj[MID+j].push_back(i);
    }

    maxflow(ST,EN);

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }
}
