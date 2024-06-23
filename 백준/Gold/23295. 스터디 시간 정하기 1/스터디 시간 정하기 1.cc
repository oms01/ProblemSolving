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

ll board[1'000'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,t; cin>>n>>t;
    rep(i,0,n){
        ll a; cin>>a;
        rep(i,0,a){
            ll s,e; cin>>s>>e;
            board[s]++; board[e]--;
        }
    }
    rep(i,1,1'000'001) board[i]+=board[i-1];

    ll sum = 0;
    rep(i,0,t) sum+=board[i];

    ll ans = 0;
    ll mx = sum;
    rep(i,t,1'000'001-t){
        sum +=board[i]-board[i-t];
        if(mx >= sum) continue;
        mx = sum;
        ans = i-t+1;
    }

    cout<<ans<<' '<<ans+t<<'\n';

}