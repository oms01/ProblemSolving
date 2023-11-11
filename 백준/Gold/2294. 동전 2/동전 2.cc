#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;
vector<int> v;
int dp[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    v.resize(n);
    fill(dp,dp+10'001,2e9);
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(v[i]>k) continue;
        dp[v[i]] = 1;
    }
    for(int i=0;i<=k;i++){
        if(dp[i]!=0){
            for(int j=0;j<n;j++){
                if(i+v[j]>k) continue; 
                dp[i+v[j]] = min(dp[i]+1,dp[i+v[j]]);
            }
        }
    }
    // for(int i=0;i<=k;i++){
    //     cout<<i<<' '<<dp[i]<<'\n';
    // }
    cout<<(dp[k]!=2e9 ? dp[k] : -1);
}