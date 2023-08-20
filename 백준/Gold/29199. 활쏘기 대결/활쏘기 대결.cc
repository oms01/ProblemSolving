#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll s[1001];
ll dp[1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int n;
        cin>>n;
        s[i] = s[i-1] + n;
    }
    dp[1] = max(0ll,s[1]);
    for(int i=2;i<=n;i++){
        dp[i] = max(dp[i-1],s[i]-dp[i-1]);
    }
    
    cout<<dp[n]<<'\n';

}
