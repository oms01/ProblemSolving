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

string board[51];
vector<pii> adj[251];
int n,m; 
map<pii,int> ma;
int func(pii st){
    int vis[51][51];
    memset(vis,-1,sizeof(vis));
    queue<pii> q;
    vis[st.X][st.Y] = 0;
    q.push(st);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir = 0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(vis[nx][ny]!=-1) continue;
            if(board[nx][ny]=='1') continue;
            vis[nx][ny] = vis[cur.X][cur.Y] + 1;
            if(board[nx][ny]=='K' || board[nx][ny]=='S'){
                adj[ma[st]].push_back({vis[nx][ny], ma[{nx,ny}]});
            }
            q.push({nx,ny});
        }
    }

    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    
    rep(i,0,n){
        cin>>board[i];
        rep(j,0,n){
            if(board[i][j]=='S'||board[i][j]=='K'){
                ma[{i,j}] = ma.size();
            }
        }
    }

    for(auto cur : ma) func(cur.X);

    vector<int> vis(m+1,0);
    int ans = 0;
    int cnt = 1;
    priority_queue<pii, vector<pii>, greater<>> pq;
    vis[0] = 1;
    for(auto cur : adj[0]){
        pq.push(cur);
    }
    while(cnt<m+1 && !pq.empty()){
        auto cur = pq.top(); pq.pop();
        if(vis[cur.Y]) continue;
        vis[cur.Y] = 1;
        ans += cur.X;
        cnt++;
        for(auto nxt: adj[cur.Y]){
            if(vis[nxt.Y]) continue;
            pq.push(nxt);
        }
    }
    if(cnt<m+1) cout<<-1<<'\n';
    else cout<<ans<<'\n';


}