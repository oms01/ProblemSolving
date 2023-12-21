#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int n;
int dp[10'001];
vector<pii> adj[10'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        int s,e,x;
        cin>>s>>e>>x;
        adj[s].push_back({e,x});
    }

    fill(dp,dp+10'001,2e9);
    dp[0] = 0;
    for(int i=0;i<=d;i++){
        if(i!=0) dp[i] = min(dp[i],dp[i-1]+1);
        for(auto x:adj[i]){
            dp[x.X]= min(dp[x.X],dp[i]+x.Y);
        }
    }
    cout<<dp[d];
}