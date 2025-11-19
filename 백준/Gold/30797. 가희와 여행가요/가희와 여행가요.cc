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
typedef tuple<ll,ll,ll,ll> tl4;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 200'000;
int p[MX+1];
int Find(int a){return p[a]==a ? a : p[a] = Find(p[a]);};
void Union(int a, int b){
    a = Find(a); b = Find(b);
    if(a!=b) p[a] = b;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    REP(i,0,n) p[i] = i;

    vector<tl4> edges(m);
    for(auto&[c,t,a,b]: edges) cin>>a>>b>>c>>t;
    sort(all(edges));

    ll ansc = 0;
    ll anst = 0;
    int cnt = 0;
    for(auto&[c,t,s,e]: edges){
        if(Find(s)==Find(e)) continue;
        Union(s,e);
        ansc += c;
        anst = max(anst, t);
        cnt++;
        if(cnt==n-1) break;
    }
    if(cnt!=n-1) return !(cout<<-1<<'\n');
    cout<<anst<<' '<<ansc<<'\n';

}
