#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> l(n),c(n);
        rep(i,0,n) cin>>l[i];
        rep(i,0,n) cin>>c[i];

        ll sum_c = 0;
        rep(i,0,n) sum_c+=c[i];

        ll mul = 0;
        rep(i,0,n) mul += l[i]*c[i];

        ll l_c = 0;
        ll r_c = sum_c;
        ll l_lc = 0;
        ll r_lc = mul;
        
        ll mn = 2e16;
        ll ans = -1;
        rep(i,0,n){
            r_c -= c[i];
            r_lc -= l[i] * c[i];

            ll a = (l[i] * l_c) - l_lc;
            ll b = r_lc - (l[i] * r_c);
            ll val = a+b;
            // cout<<val<<' ';
            if(mn > val){
                mn = val;
                ans = l[i];
            }
            l_c += c[i];
            l_lc += l[i]*c[i];
        }
        cout<<ans<<'\n';
    }


}