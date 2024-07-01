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
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    ll cur = 0;
    ll ans = 0;
    rep(i,0,n){
        cin>>v[i];
        cur+=v[i];
        if(i>=m) cur-=v[i-m];
        ans += (129<=cur&&cur<=138);

    }

    cout<<ans<<'\n';

}