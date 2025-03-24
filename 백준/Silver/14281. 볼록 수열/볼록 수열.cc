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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n; cin>>n;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    bool flag = 1;
    ll ans = 0;
    while(flag){
        flag = 0;
        rep(i,1,n-1){
            if(v[i-1]+v[i+1] >= 2*v[i]) continue;
            ll val = (v[i-1]+v[i+1])/2;
            ans += v[i] - val;
            v[i] = val;
            flag = 1;
        }
    }
    cout<<ans<<'\n';
}