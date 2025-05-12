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
typedef tuple<int,int,int,int> tiiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

const int MX = 50;
string board[MX+1];
int dist[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n) cin>>board[i];
    rep(i,0,MX) rep(j,0,MX) dist[i][j] = 2e9;
    
    pii loc;
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]=='#') loc = {i,j};
    } 
    int ans = 2e9;

    //거리, 들어온방향, {x,y}
    priority_queue<tiiii, vector<tiiii>, greater<>> pq;
    dist[loc.X][loc.Y] = 0;
    pq.push({0,-1,loc.X,loc.Y});
    while(!pq.empty()){
        auto [x,d,cx,cy] = pq.top(); pq.pop();

        if(dist[cx][cy]!=x) continue;
        for(int dir=0;dir<4;dir++){
            if(dir==d || dir==(d+2)%4) continue;
            for(int i=1;;i++){
                int nx = cx + dx[dir]*i;
                int ny = cy + dy[dir]*i;
                if(nx<0||nx>=n||ny<0||ny>=n) break;
                if(board[nx][ny]=='*') break;
                if(board[nx][ny]=='!'){
                    if(dist[nx][ny]<=dist[cx][cy]+1) continue;
                    dist[nx][ny] = dist[cx][cy]+1;
                    pq.push({dist[nx][ny],dir,nx,ny});
                }
                else if(board[nx][ny]=='#'){
                    ans = min(ans, x);
                }
                else{
                    if(dist[nx][ny]<=dist[cx][cy]) continue;
                    dist[nx][ny] = dist[cx][cy];
                }
            }
        }
        // rep(i,0,n){
        //     rep(j,0,n){
        //         cout<<(dist[i][j]==2e9 ? -1 :dist[i][j])<<' ';
        //     }
        //     cout<<'\n';
        // }
        // cout<<'\n';
    }

    cout<<ans<<'\n';

    // rep(i,0,n) rep(j,0,n){
    //     if(board[i][j]=='#' && i!=loc.X && j!=loc.Y){
    //         return !(cout<<dist[i][j]<<'\n');
    //     } 
    // }



}