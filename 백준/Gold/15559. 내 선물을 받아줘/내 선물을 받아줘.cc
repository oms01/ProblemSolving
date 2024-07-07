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
const int MX = 1'001;
int p[MX*MX];
int Find(int x){
    if(x==p[x]) return x;
    return p[x] = Find(p[x]);
}
void Union(int a,int b){
    a = Find(a); b = Find(b);
    p[a] = b;
}
string board[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,MX*MX) p[i]=i;
    map<char,int> ma;
    ma['S']=2; ma['N']=3;
    ma['E']=0; ma['W']=1;

    int n,m; cin>>n>>m;
    rep(i,0,n) cin>>board[i];

    rep(i,0,n) rep(j,0,m){
        int nx = i + dx[ma[board[i][j]]];
        int ny = j + dy[ma[board[i][j]]];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        Union(i*m+j, nx*m+ny);
    }
    
    int ans = 0;
    rep(i,0,n*m) ans+=(p[i]==i);
    cout<<ans<<'\n';

}