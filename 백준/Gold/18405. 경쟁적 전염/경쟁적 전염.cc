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

int board[202][202];
vector<pii> idx[1'001];
queue<pii> q;
int n,k; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>k;
    rep(i,0,n) rep(j,0,n){
        cin>>board[i][j];
        if(board[i][j]>0) idx[board[i][j]].push_back({i,j});
    }
    rep(i,1,k+1){
        for(pii a: idx[i]) q.push(a);
    }

    int s,x,y; cin>>s>>x>>y;

    while(s--){
        for(int i=q.size();i;i--){
            pii cur = q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n||board[nx][ny]) continue;
                board[nx][ny] = board[cur.X][cur.Y];
                q.push({nx,ny});
            }
        }
    }

    cout<<board[x-1][y-1]<<'\n';

}