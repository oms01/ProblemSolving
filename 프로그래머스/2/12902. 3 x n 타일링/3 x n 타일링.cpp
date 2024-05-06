#include <bits/stdc++.h>

using namespace std;


long long dp[5001];
int solution(int n) {
    if(n%2) return 0;
    
    dp[0] = 1;
    long long val = 0;
    for(int i=2;i<=5000;i+=2){
        dp[i] = (dp[i-2] * 3 + val)%1'000'000'007;
        val+=2*dp[i-2];
    }
    
    return dp[n];
}