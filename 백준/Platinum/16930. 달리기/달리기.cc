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

const int MX = 1000;
string board[MX+1];
int dist[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    rep(i,0,n) cin>>board[i];
    REP(i,0,MX) REP(j,0,MX) dist[i][j] = 2e9;

    pii st; cin>>st.X>>st.Y;
    st.X--;st.Y--;
    pii en; cin>>en.X>>en.Y;
    en.X--;en.Y--;

    queue<pii> q;
    dist[st.X][st.Y] = 0;
    q.push(st);
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            for(int i=1;i<=k;i++){
                int nx = cur.X + dx[dir]*i;
                int ny = cur.Y + dy[dir]*i;
                if(nx<0||nx>=n||ny<0||ny>=m) break;
                if(board[nx][ny]=='#') break;
                if(dist[nx][ny] < dist[cur.X][cur.Y]+1) break;
                
                if(dist[nx][ny]==2e9){
                    q.push({nx,ny});
                    if(nx==en.X && ny==en.Y){
                        return !(cout<<dist[cur.X][cur.Y] + 1<<'\n');
                    }
                }
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            }
        }
    }

    cout<<-1<<'\n';
}

