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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

string board[21];
int dist[21][21];
int n,m;
map<pii,int> ma;
int ans;
void func(pii st){
    int vis[21][21];
    memset(vis,-1,sizeof(vis));
    queue<pii> q;
    q.push(st);
    vis[st.X][st.Y] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]!=-1) continue;
            if(board[nx][ny]=='x') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            if(board[nx][ny]=='*'||board[nx][ny]=='o'){
                dist[ma[st]][ma[{nx,ny}]] = vis[nx][ny];
            }
            q.push({nx,ny});
        }
    }
    return;
}
void f(ll vis, int cur, int val){
    if(vis == (1<<ma.size())-1){
        ans = min(ans,val);
        return;
    }

    for(int i=0;i<ma.size();i++){
        if(vis&(1<<i)) continue;
        vis = vis | (1<<i);
        f(vis, i, val + dist[cur][i]);
        vis = vis & ~(1<<i);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>m>>n){
        if(n==0&&m==0) break;
        ma.clear();
        // memset(dist,0,sizeof(dist));
        for(int i=0;i<21;i++){
            for(int j=0;j<21;j++){
                dist[i][j] = 2e9;
            }
        }
        ans = 2e9;
        pii st;
        rep(i,0,n){
            cin>>board[i];
            rep(j,0,m){
                if(board[i][j]=='o') st = {i,j};
                if(board[i][j]=='*') ma[{i,j}] = ma.size();
            }
        }
        ma[st] = ma.size();
        for(auto cur : ma) func(cur.X);


        //ma[st]에서 시작
        ll vis = 0;
        vis = vis | (1<<ma[st]);
        f(vis, ma[st], 0);
        if(ans>=1e9||ans<0) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }

}