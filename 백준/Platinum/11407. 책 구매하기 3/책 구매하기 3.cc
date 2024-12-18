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
    cout<<cnt<<'\n'<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    int st = 900;
    int en = 901;

    //사람 -> 종료점 간선 설정
    for(int i=1;i<=n;i++){
        cin>>c[400+i][en];
        adj[400+i].push_back(en);
        adj[en].push_back(400+i);
    }

    //시작점 -> 서점 간선 설정
    for(int i=1;i<=m;i++){
        cin>>c[st][i];
        adj[st].push_back(i);
        adj[i].push_back(st);
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            adj[i].push_back(400+j);
            adj[400+j].push_back(i);
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>c[i][400+j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>d[i][400+j];
            d[400+j][i] = -d[i][400+j];
        }
    }

    maxflow(st,en);
}
