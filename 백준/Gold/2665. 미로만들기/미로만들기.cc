#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int dist[51][51];
string board[51];
int n;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i,0,n) cin>>board[i];

    rep(i,0,51) fill(dist[i],dist[i]+51,2e9);

    dist[0][0] = 0;
    priority_queue<tiii, vector<tiii>, greater<>> pq;
    pq.push({dist[0][0],0,0});
    while(!pq.empty()){
        int c; pii cur;
        tie(c,cur.X,cur.Y) = pq.top(); pq.pop();
        if(c != dist[cur.X][cur.Y]) continue;
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(c + (board[nx][ny]=='0') >= dist[nx][ny]) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + (board[nx][ny]=='0');
            pq.push({dist[nx][ny],nx,ny});
        }
    }

    cout<<dist[n-1][n-1]<<'\n';

}