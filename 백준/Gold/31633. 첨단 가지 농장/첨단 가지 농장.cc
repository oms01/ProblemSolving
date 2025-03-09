#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

int board[1001][1001];
int h[1'000'001];
vector<int> adj[1'000'001];

struct union_find{
    union_find(int n) : p(n,-1){}
    int find(int a){
        return p[a]<0 ? a: p[a] = find(p[a]);
    }
    bool merge(int a,int b){
        a = find(a); b = find(b);
        if(a==b) return 0;
        p[a] += p[b];
        p[b] = a;
        return 1;
    }
    private: vector<int> p;
};

int f(int cur){
    int& ret = h[cur];
    if(ret!=-1) return ret;
    ret = 0;
    for(auto nxt: adj[cur]){
        ret = max(ret, f(nxt)+1);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    rep(i,0,n) rep(j,0,m) cin>>board[i][j];
    
    union_find uf(n*m);
    rep(i,0,n) rep(j,0,m){
        for(int dir=0;dir<4;dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[i][j]==board[nx][ny]) uf.merge(i*m+j, nx*m+ny);
        }
    }
    rep(i,0,n) rep(j,0,m){
        for(int dir=0;dir<4;dir++){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[i][j]>board[nx][ny]) adj[uf.find(i*m+j)].push_back(uf.find(nx*m+ny));
        }
    }
    
    
    REP(i,0,1'000'000) h[i] = -1;
    for(int i=0;i<n*m;i++){
        if(h[i]==-1) f(i);
    }

    rep(i,0,n){
        rep(j,0,m) cout<<h[uf.find(i*m+j)]<<' '; cout<<'\n';
    }

}
 