#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 2'500;
vector<int> adj[MX];
int c[MX][MX], f[MX][MX], d[MX][MX]; //용량, 흐름, 비용
pii maxflow(int st, int en){
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
            ans += d[prev[i]][i];
            f[prev[i]][i]+=flow;
            f[i][prev[i]]-=flow;
        }
        cnt++;
    }

    return {cnt,ans};
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    int st = 2001;
    int mid = 2002;
    int en = 2003;

    adj[st].push_back(mid);
    adj[mid].push_back(st);
    c[st][mid] = k;

    //st->사람, mid->사람
    REP(i,1,n){
        adj[st].push_back(i); 
        adj[i].push_back(st);
        c[st][i] = 1;
        adj[mid].push_back(i);
        adj[i].push_back(mid);
        c[mid][i] = k;
    }

    //일->en
    REP(i,1,m){
        adj[i+1000].push_back(en);
        adj[en].push_back(i+1000);
        c[i+1000][en] = 1;
    }

    REP(i,1,n){
        int t; cin>>t;
        while(t--){
            int x; cin>>x;
            c[i][x+1000] = 1;
            adj[i].push_back(x+1000);
            adj[x+1000].push_back(i);
        }
        c[mid][i] = k;
        c[st][i] = 1;
    }

    REP(i,1,m){
        c[i+1000][en] = 1;
    }

    pii a = maxflow(st,en);
    cout<<a.X<<'\n';


}
