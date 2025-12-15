#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9+7;
ll dp[100'001];
int solution(int n, vector<int> money) {
    
    dp[0] = 1;
    for(auto x: money){
        for(int i=x;i<=n;i++){
            dp[i] += dp[i-x];
            dp[i] %= MOD;
        }
    }

    return dp[n];
}