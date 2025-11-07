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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n); rep(i,0,n) cin>>v[i];
    sort(rall(v));

    ll cur = 0;
    ll idx = 0;
    ll t,q;
    rep(i,0,m){
        cin>>t>>q;
        while(idx<n && cur<q){
            cur += t + v[idx++];
        }
    }

    while(idx<n){
        cur += t + v[idx++];
    }

    if(cur<q) return !(cout<<-1<<'\n');
    cout<<cur<<'\n';
}
