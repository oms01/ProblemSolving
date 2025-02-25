#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

const ll MOD = 1'000'000'007;
ll dp[5'001];

ll mod_inv(ll a, ll m) {
    ll ret=1, b=m-2;
    while(b){
        if(b&1) ret=ret*a%m;
        a=a*a%m;
        b>>=1;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    dp[0] = 1;
    REP(i,1,2500){
        dp[i] = (dp[i-1] * (4*i-2)%MOD*mod_inv(i+1,MOD))%MOD;
    }


    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n%2){
            cout<<0<<'\n';
        }
        else{
            cout<<dp[n/2]<<'\n';
        }
    }
    
}