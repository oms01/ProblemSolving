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
/*------------------------------*/

pii parent[1'001][1'001];
pii Find(int x,int y){
    if(parent[x][y]==make_pair(x,y)) return {x,y};
    return parent[x][y] = Find(parent[x][y].X,parent[x][y].Y);
}
void Union(pii x, pii y){ // x to y
    pii a = Find(x.X,x.Y);
    pii b = Find(y.X,y.Y);
    parent[a.X][a.Y] = {b.X,b.Y};
}
string board[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,1001) rep(j,0,1001){
        parent[i][j] = {i,j};
    }
    map<char,int> ma;
    ma['D']=2; ma['U']=3;
    ma['R']=0; ma['L']=1;

    int n,m; cin>>n>>m;
    rep(i,0,n) cin>>board[i];

    rep(i,0,n) rep(j,0,m){
        int nx = i + dx[ma[board[i][j]]];
        int ny = j + dy[ma[board[i][j]]];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        Union({i,j},{nx,ny});
    }
    
    int ans = 0;
    rep(i,0,n) rep(j,0,m){
        ans+=(parent[i][j]==make_pair(i,j));
    }
    cout<<ans<<'\n';

}