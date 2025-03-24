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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
const int MX = 100;
int board[MX+1][MX+1];
int sec[MX+1][MX+1];
int dist[MX+1][MX+1];
bool vol[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m,v; cin>>n>>m>>v;
    pii loc; cin>>loc.X>>loc.Y;
    rep(i,0,n) rep(j,0,m) cin>>board[i][j];

    rep(i,0,n) rep(j,0,m) sec[i][j] = 2e9;

    while(v--){
        int x,y,t; cin>>x>>y>>t;
        x--;y--;
        vol[x][y] = 1;
        if(sec[x][y] <= t) continue;
        queue<pii> q;
        q.push({x,y});
        sec[x][y] = t;
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(sec[nx][ny] <= sec[cur.X][cur.Y]+1) continue;
                sec[nx][ny] = sec[cur.X][cur.Y] + 1;
                q.push({nx,ny});
            }
        }
    }
    

    rep(i,0,n) rep(j,0,m) dist[i][j] = 2e9;

    queue<pii> q;
    dist[--loc.X][--loc.Y] = 0;
    q.push(loc);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vol[nx][ny]) continue;
            if(dist[nx][ny]!=2e9) continue;
            if(sec[nx][ny] <= dist[cur.X][cur.Y]+1) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }

    int mx = -1;
    int d = -1;
    rep(i,0,n){
        rep(j,0,m){
            
            if(dist[i][j]!= 2e9 && mx < board[i][j]){
                mx = board[i][j];
                d = dist[i][j];
            }
        }
    }
    cout<<mx<<' '<<d<<'\n';

}