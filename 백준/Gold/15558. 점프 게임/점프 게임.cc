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
const int MX = 100'000;
int vis[2][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,0,2) rep(j,0,MX) vis[i][j] = 2e9;

    int n,k; cin>>n>>k;
    string board[2];
    cin>>board[0]>>board[1];

    queue<tiii> q;
    q.push({0,0,0});
    vis[0][0] = 0;
    while(!q.empty()){
        auto [x,y,t] = q.front(); q.pop();
        for(auto [nx,ny] : {make_pair(x,y-1),make_pair(x,y+1), make_pair(1-x,y+k)}){
            if(ny<t) continue;
            if(ny>=n) return !(cout<<1<<'\n');
            if(vis[nx][ny]!=2e9) continue;
            if(board[nx][ny]=='0') continue;
            vis[nx][ny] = ++t;
            q.push({nx,ny,t});
        }
    }
    cout<<0<<'\n';

}

