#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 200'002;
const int MOD = 10'007;
ll dp[MX+1];
int solution(int n, vector<int> tops) {
    dp[0] = 1;
    dp[1] = tops[0]==0 ? 2 : 3;
    dp[2] = tops[0]==0 ? 3 : 4;
    for(int i=3;i<=2*n;i++){
        if(i%2 && tops[(i-1)/2]){
            dp[i] = dp[i-1]*2 + dp[i-2];
        }
        else{
            dp[i] = dp[i-1] + dp[i-2];
        }
        dp[i] %= MOD;
    }
    return dp[2*n]%MOD;
}