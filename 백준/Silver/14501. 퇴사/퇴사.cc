#include <bits/stdc++.h>
using namespace std;
int t[1001], p[1001];
int dp[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>p[i];
    }

    int ans = 0;
    for(int i=1;i<=n+1;i++){
        dp[i] = max(ans,dp[i]);
        if(t[i]+i<=n+1) dp[t[i]+i] = max(dp[t[i]+i], dp[i]+p[i]);
        ans = max(ans,dp[i]);
    }

    cout<<ans<<'\n';

}
