#include <bits/stdc++.h>
using namespace std;
int dp[501][501];
int sum[501];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int a;
            cin>>a;
            sum[i] = sum[i-1] + a;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n-i;j++){

                dp[j][i+j]=2e9;
                for(int k=j;k<i+j;k++){
                    dp[j][i+j] = min(dp[j][i+j],dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }
        cout<<dp[1][n]<<'\n';
    }
}