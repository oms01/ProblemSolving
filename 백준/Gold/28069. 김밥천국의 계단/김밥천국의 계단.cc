#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int dp[2'000'001];
vector<pair<int,int>> input;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    fill(dp,dp+2'000'001,2e9);
    dp[0]=0;
    for(int i=0;i<=n;i++){
        dp[i+1] = min(dp[i+1],dp[i]+1);
        dp[i+(i/2)] = min(dp[i+(i/2)], dp[i]+1);
    }

    // for(int i=0;i<=n;i++){
    //     cout<<dp[i]<<'\n';
    // }
    if(dp[n]>k) cout<<"water\n";
    else cout<<"minigimbob\n";

}