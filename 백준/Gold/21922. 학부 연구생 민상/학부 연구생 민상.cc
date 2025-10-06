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
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 2000;
int board[MX+1][MX+1];
int vis[MX+1][MX+1][4];
int nxt[5][4];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;

    nxt[0][0] = 0; nxt[0][1] = 1;
    nxt[0][2] = 2; nxt[0][3] = 3;

    nxt[1][1] = nxt[1][3] = -1;
    nxt[1][0] = 0; nxt[1][2] = 2;
    
    nxt[2][0] = nxt[2][2] = -1;
    nxt[2][1] = 1; nxt[2][3] = 3;

    nxt[3][0] = 1; nxt[3][1] = 0;
    nxt[3][2] = 3; nxt[3][3] = 2;

    nxt[4][0] = 3; nxt[4][3] = 0;
    nxt[4][1] = 2; nxt[4][2] = 1;
    
    queue<ti3> q;
    rep(i,0,n) rep(j,0,m){
        cin>>board[i][j];
        if(board[i][j]==9){
            rep(d,0,4){
                vis[i][j][d] = 1;
                q.push({i,j,d});
            }
        }
    }

    while(!q.empty()){
        auto [cx, cy, dir] = q.front(); q.pop();
        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(vis[nx][ny][dir]) continue;
        vis[nx][ny][dir] = 1;
        
        dir = nxt[board[nx][ny]][dir];
        if(dir==-1) continue;

        q.push({nx,ny,dir});
    }

    int cnt = 0;
    rep(i,0,n) rep(j,0,m){
        cnt += vis[i][j][0]|vis[i][j][1]|vis[i][j][2]|vis[i][j][3];
    }
    cout<<cnt<<'\n';
}
