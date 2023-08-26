#include <bits/stdc++.h>
using namespace std;
int dp[10'001];
int input[101];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    dp[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=input[i];j<=k;j++){
            dp[j] += dp[j-input[i]];
        }
    }
    cout<<dp[k]<<'\n';

    

}