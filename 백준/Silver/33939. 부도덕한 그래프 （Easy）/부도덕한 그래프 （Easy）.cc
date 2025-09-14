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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 2000;
vector<int> adj[MX+1];
int tmp[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        adj[e].push_back(s);
        tmp[s][e] = 1;
    }

    int cnt = 0;
    REP(z,1,n){
        rep(i,0,adj[z].size()) rep(j,i+1,adj[z].size()){
            int x = adj[z][i], y = adj[z][j];
            if(tmp[x][y]||tmp[y][x]) continue;
            cnt++;
        }
    }
    cout<<cnt<<'\n';
}