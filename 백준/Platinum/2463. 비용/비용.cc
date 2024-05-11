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

vector<pll> adj[100001];
ll parent[100'001];
ll sz[100'001];
ll Find(ll n){
    if(parent[n]==n) return n;
    return parent[n] = Find(parent[n]);
}
void Union(ll x,ll y){
    ll a = Find(x);
    ll b = Find(y);
    parent[b] = a;
    sz[a] += sz[b];
    sz[b] = 1;
}
vector<tuple<ll,ll,ll>> v;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    ll sum = 0;
    rep(i,1,n+1){
        parent[i] = i;
        sz[i] = 1;
    }
    rep(i,0,m){
        ll a,b,c; cin>>a>>b>>c;
        v.push_back({c,a,b});
        sum+=c;
    }
    sort(rall(v));
    ll ans = 0;
    rep(i,0,v.size()){
        ll a,b,c;
        tie(c,a,b) = v[i];

        ll A = Find(a);
        ll B = Find(b);
        if(A!=B){
            ans+=(((sz[A]*sz[B])%(ll)1e9)*sum)%(ll)1e9;
            ans%=(ll)1e9;
            Union(a,b);
        }
        sum-=c;
    }
    cout<<ans<<'\n';
}