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
typedef tuple<int,int,int> tiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

const int MX = 2'000;
string board[MX+1];
int vis[MX+1][MX+1];
int ddx[] = {-1,-1,-1,0,1,1,0};
int ddy[] = {-1,0,1,1,1,-1,-1};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n) cin>>board[i];

    pii st;
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]=='F') st = {i,j};
    }
    
    queue<pii> q;
    q.push(st);
    vis[st.X][st.Y] = 1;
    int cnt = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<7;dir++){
            int nx = cur.X + ddx[dir];
            int ny = cur.Y + ddy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(vis[nx][ny]) continue;
            if(board[nx][ny]!='.') continue;
            vis[nx][ny] = 1;
            cnt++;
            q.push({nx,ny});
        }
    }
    cout<<cnt<<'\n';
    

}
