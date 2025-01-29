#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

ll dp[300'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll d = 1;
    ll tmp = 2;
    ll cur = 0;
    vector<int> v;
    while(cur<=300'000){
        cur += d;
        d+=tmp++;
        v.push_back(cur);
    }
    fill(dp,dp+300'001,2e9);
    dp[0] = 0;

    for(int i=1;i<300'001;i++){
        for(auto x: v){
            if(x>i) break;
            dp[i] = min(dp[i],dp[i-x]+1);

        }
    }
    
    int n; cin>>n;
    cout<<dp[n]<<'\n';

}