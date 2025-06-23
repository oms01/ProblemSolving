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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int ddx[] = {0,1,1,1};
int ddy[] = {1,1,0,-1};
const int MX = 1000;
int board[MX+1][MX+1];
int dp[4][MX+1][MX+1];
int n;

bool OOB(int x, int y){
    return x<0||x>=n||y<0||y>=n;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    rep(i,0,n) rep(j,0,n) cin>>board[i][j];

    vector<pii> white,black;
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]==2) white.push_back({i,j});
        if(board[i][j]==1) black.push_back({i,j});
    }
    
    int mx = -1;
    rep(dir,0,4){
        for(auto [i,j]: black){
            if(dp[dir][i][j]) continue;
            int x = i, y = j, len = 1;
            while (true){
                int nx = x + ddx[dir];
                int ny = y + ddy[dir];
                if(OOB(nx,ny)) break;
                if(board[nx][ny] != board[x][y]) break;
                x = nx;
                y = ny;
                len++;
            }
            int nx = i, ny = j;
            rep(k,0,len){
                dp[dir][nx][ny] = len;
                nx += ddx[dir];
                ny += ddy[dir];
            }
            mx = max(mx, len);
        }
    }

    for(auto [i,j]: white){
        rep(dir,0,4){
            int tmp = 0;
            pii a = {i + ddx[dir], j + ddy[dir]};
            if(!OOB(a.X,a.Y)) {
                tmp += dp[dir][a.X][a.Y];
            }
            pii b = {i - ddx[dir], j - ddy[dir]};
            if(!OOB(b.X,b.Y)) {
                tmp += dp[dir][b.X][b.Y];
            }
            mx = max(mx, tmp+1);
        }
    }
    cout<<mx<<'\n';
}