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

ll arr[1001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n+1);
    rep(i,1,n+1){
        ll x; cin>>x;
        v[i] = x + v[i-1];
        arr[v[i]%m]++;
    }

    ll ans = arr[0];
    rep(i,0,m){
        ans += (arr[i]*(arr[i]-1))/2;
    }
    cout<<ans<<'\n';

    
}