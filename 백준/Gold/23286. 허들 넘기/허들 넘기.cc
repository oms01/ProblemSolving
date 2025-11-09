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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 300;
int d[MX+1][MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,MX) rep(j,0,MX) d[i][j] = 2e9;
    int n,m,t; cin>>n>>m>>t;
    rep(i,0,m){
        int s,e,c; cin>>s>>e>>c;
        d[s][e] = c;
    }

    REP(k,1,n) REP(i,1,n) REP(j,1,n) d[i][j] = min(d[i][j], max(d[i][k],d[k][j]));

    rep(i,0,t){
        int s,e; cin>>s>>e;
        cout<<(d[s][e]==2e9?-1:d[s][e])<<'\n';
    }
    
}
