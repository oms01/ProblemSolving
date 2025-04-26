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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int n,m; 

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    vector<string> tmp(n);
    rep(i,0,n) cin>>tmp[i];
    vector<vector<int>> board(n+2,vector<int>(m+2));
    REP(i,1,n) REP(j,1,m) board[i][j] = tmp[i-1][j-1]-'0';

    int ans = 0;
    REP(h,1,9){

        board[0][0] = h;
        queue<pii> q;
        q.push({0,0});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            rep(dir,0,4){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>n+1||ny<0||ny>m+1) continue;
                if(board[nx][ny]>=h) continue;
                board[nx][ny] = h;
                q.push({nx,ny});
            }
        }

        REP(i,1,n) REP(j,1,m){
            if(board[i][j]<h){
                ans++;
                board[i][j]=h;
            }
        }
    }
    cout<<ans<<'\n';
}