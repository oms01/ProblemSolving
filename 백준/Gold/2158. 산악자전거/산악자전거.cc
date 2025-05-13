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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

const int MX = 100;
int board[MX+1][MX+1];
pldld dist[MX+1][MX+1]; // {시간, 속도}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int v,n,m; cin>>v>>n>>m;
    rep(i,0,n) rep(j,0,m) cin>>board[i][j];


    rep(i,0,n) rep(j,0,m) dist[i][j] = {2e16,-1};
    priority_queue<pair<pldld,pii>, vector<pair<pldld,pii>>,greater<>> pq;
    dist[0][0] = {0,v};
    pq.push({dist[0][0],{0,0}});

    ld ans = 2e16;
    while(!pq.empty()){
        auto [state,cur] = pq.top(); pq.pop();
        auto [ct,cv] = state;
        auto [cx,cy] = cur;

        if(cx==n-1 && cy==m-1){
            ans = min(ans,ct);
            continue;
        }
        //현재보다 더 빠른 시간에 cur에 도착하는 경우
        if(dist[cx][cy].X < ct) continue;
        //같은 시간에 더 빠른 속도로 cur에 도착하는 경우
        if(dist[cx][cy].X==ct && dist[cx][cy].Y>cv) continue;

        for(int dir=0;dir<4;dir++){
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            ld nt = ct + (1/cv);
            ld nv = cv * pow(2,board[cx][cy]-board[nx][ny]);
            if(dist[nx][ny].X < nt) continue;
            if(dist[nx][ny].X==nt && dist[nx][ny].Y>=nv) continue;
            dist[nx][ny] = {nt,nv};
            pq.push({{nt,nv},{nx,ny}});
        }
    }
    cout<<fixed;
    cout.precision(10);
    cout<<ans<<'\n';

}