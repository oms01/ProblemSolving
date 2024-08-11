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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<string> board(2);
    cin>>board[0]>>board[1];

    vector<vector<int>> dist(2,vector<int>(n,0));
    queue<pii> q;
    if(board[0][0]=='.'){
        q.push({0,0});
        dist[0][0] = 1;
    }
    if(board[1][0]=='.'){
        q.push({1,0});
        dist[1][0] = 1;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.Y==n-1) break;
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=2||ny<0||ny>=n) continue;
            if(board[nx][ny]=='#'||dist[nx][ny]) continue;
            dist[nx][ny] = dist[cur.X][cur.Y]+1;
            q.push({nx,ny});
        }
    }

    int cnt = 0;
    rep(i,0,2) rep(j,0,n) cnt+=(board[i][j]=='.');

    cout<<cnt-max(dist[0][n-1],dist[1][n-1])<<'\n';

}