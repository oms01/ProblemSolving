#include <bits/stdc++.h>
using namespace std;
int dp[101][100'001];
int v[101], w[101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;i++){
        cin>>w[i]>>v[i];
    }

    for(int j=1;j<=k;j++){
        for(int i=1;i<=n;i++){
            if(j-w[i]>=0) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    cout<<dp[n][k];
}