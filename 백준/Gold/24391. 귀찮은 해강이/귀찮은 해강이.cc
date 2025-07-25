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

const int MX = 100'000;
int p[MX+1];
int Find(int a){
    if(p[a]==a) return a;
    return p[a] = Find(p[a]);
}
void Union(int a,int b){
    a = Find(a); b = Find(b);
    if(a!=b) p[a] = b;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    REP(i,0,MX) p[i] = i;

    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        Union(s,e);
    }

    int cur; cin>>cur;
    cur = Find(cur);
    int cnt = 0;
    rep(i,1,n){
        int nxt; cin>>nxt;
        nxt = Find(nxt);
        if(cur!=nxt){
            cnt++;
        }
        cur = nxt;
    }
    cout<<cnt<<'\n';
    
}