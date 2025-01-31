#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

/*----------------------*/


ll dp[1'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<ll> v(n+1,0);
    REP(i,1,n) cin>>v[i];


    REP(i,1,n){
        ll mn = v[i];
        ll mx = v[i];
        for(int j=i;j>0;j--){
            mn = min(mn, v[j]);
            mx = max(mx, v[j]);
            dp[i] = max(dp[i], dp[j-1] + mx-mn);
        }
    }

    cout<<dp[n]<<'\n';

}