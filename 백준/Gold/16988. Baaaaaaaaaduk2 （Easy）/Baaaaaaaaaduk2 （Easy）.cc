#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

int n,m;
int board[30][30];
int vis[30][30];
vector<pii> emp, black;

bool nearChk(pii cur, int target){
    for(int dir=0;dir<4;dir++){
        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(board[nx][ny]==target) return 1;
    }
    return 0;
}

int bfs(pii loc){
    vector<pii> tmp;
    tmp.push_back(loc);

    queue<pii> q;
    q.push(loc);
    vis[loc.X][loc.Y] = 1;
    int cnt = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]!=2 || vis[nx][ny]) continue;
            q.push({nx,ny});
            tmp.push_back({nx,ny});
            vis[nx][ny] = 1;
            cnt++;
        }
    }
    for(auto cur: tmp){
        if(nearChk(cur,0)) return 0;
    }
    return cnt;
}
int cnt(){
    rep(i,0,n) rep(j,0,m) vis[i][j] = 0;
    int ret = 0;

    for(auto cur: black){
        if(vis[cur.X][cur.Y]) continue;
        int tmp = bfs(cur);
        ret += tmp;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    rep(i,0,n) rep(j,0,m) cin>>board[i][j];
    rep(i,0,n) rep(j,0,m){
        if(board[i][j]==0) emp.push_back({i,j});
        if(board[i][j]==2) black.push_back({i,j});
    }

    int ans = 0;
    for(auto a: emp) for(auto b: emp){
        if(a==b) continue;

        board[a.X][a.Y] = 1; board[b.X][b.Y] = 1;
        int ret = cnt();
        board[a.X][a.Y] = 0; board[b.X][b.Y] = 0;

        ans = max(ans,ret);
    }

    cout<<ans<<'\n';
}