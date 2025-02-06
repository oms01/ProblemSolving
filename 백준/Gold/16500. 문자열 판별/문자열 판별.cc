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

int dp[200];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string s; cin>>s;
    int n; cin>>n;
    vector<string> v(n);
    rep(i,0,n) cin>>v[i];

    dp[0]=1;
    rep(i,0,s.length()){
        
        if(!dp[i]) continue;
        // cout<<i<<'\n';
        for(auto x: v){
            bool flag = 1;
            rep(j,0,x.length()){
                // cout<<i<<" "<<s[i+j]<<" / "<<x[j]<<'\n';
                if(s[i+j]!=x[j]){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                dp[i+x.length()] = dp[i];
            }
        }
        // rep(i,0,s.length()) cout<<dp[i]<<' '; cout<<'\n';
    }
    
    // rep(i,0,s.length()) cout<<s[i]<<' '; cout<<'\n';
    // rep(i,0,s.length()) cout<<dp[i]<<' '; cout<<'\n';
    cout<<dp[s.length()]<<'\n';
}