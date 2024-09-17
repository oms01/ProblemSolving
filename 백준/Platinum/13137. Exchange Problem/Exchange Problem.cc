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
int dp[200'001];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    sort(all(v));
    int mx = v[n-1]*2;

    fill(dp+1,dp+mx+1,2e9);
    rep(i,0,n){
        rep(j,v[i],mx+1){
            dp[j] = min(dp[j],dp[j-v[i]]+1);
        }
    }

    rep(i,0,mx+1){
        int cnt = 0;
        int cur = i;
        for(int j=n-1;j>=0;j--){
            cnt += cur/v[j];
            cur%=v[j];
        }
        if(cnt!=dp[i]){
            cout<<"No\n";
            return 0;
        }
    }
    cout<<"Yes\n";

}