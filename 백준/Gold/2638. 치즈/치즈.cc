#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int board[101][101]; //0: 외부, 1: 치즈, 2: 내부
int cnt;
int n,m;
vector<pii> chk(){ //사라질 치즈 찾기
    vector<pii> ret;
    rep(i,0,n) rep(j,0,m){
        if(board[i][j]==0) continue;
        int tmp = 0;
        for(int dir=0;dir<4;dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==0) tmp++;
        }
        if(tmp>=2){
            ret.push_back({i,j});
        }
    }
    return ret;
}
void melt(vector<pii> loc){ //녹이고
    for(pii cur : loc){
        board[cur.X][cur.Y] = 0;
    }
}
void chkOuter(){
    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pii> q;
    q.push({0,0});
    vis[0][0] = 1;
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]!=1) board[i][j]=0;
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==1) continue;
            if(vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]!=1 && vis[i][j]==0) board[i][j] = 2;
    }

    // rep(i,0,n){
    //     rep(j,0,m) cout<<vis[i][j]<<' ';
    //     cout<<'\n';
    // }

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i,0,n) rep(j,0,m){
        cin>>board[i][j];
        if(board[i][j]==1) cnt++;
    }

    int ans = 0;
    while(cnt>0){
        chkOuter();
        vector<pii> v = chk();
        cnt-=v.size();
        melt(v);
        ans++;
        // cout<<v.size()<<'\n';
        // rep(i,0,n){
        //     rep(j,0,m) cout<<board[i][j]<<' ';
        //     cout<<'\n';
        // }
    }
    cout<<ans<<'\n';



}