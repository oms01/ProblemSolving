#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(i==0){
            dp[0][a] = b;
            dp[0][c] = max(dp[0][c],d);
            continue;
        }
        for(int j=0;j<=m;j++){
            if(dp[i-1][j]==0) continue;
            if(j+a<=m) dp[i][j+a] = max(dp[i][j+a],dp[i-1][j]+b);
            if(j+c<=m) dp[i][j+c] = max(dp[i][j+c],dp[i-1][j]+d);
        }
    }
    ll ans = 0;
    for(int i=0;i<=m;i++){
        ans = max(ans,dp[n-1][i]);
    }
    cout<<ans<<'\n';

}