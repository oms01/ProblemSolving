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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 100;
int vis[MX+1];
vector<int> ans,v;
void f(int cur, int st){
    if(vis[cur]){
        if(cur==st) ans.push_back(cur);
        return;
    }
    vis[cur] = 1;
    f(v[cur],st);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    v.resize(n+1);
    REP(i,1,n) cin>>v[i];

    REP(i,1,n){
        memset(vis,0,sizeof(vis));
        f(i,i);
    }
    sort(all(ans));

    cout<<ans.size()<<'\n';
    for(auto x: ans) cout<<x<<'\n';
}