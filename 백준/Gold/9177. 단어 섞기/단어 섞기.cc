#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

const int MX = 1000;
int dp[MX+1][MX+1];
void solve(){

    string s1,s2,str; cin>>s1>>s2>>str;
    REP(i,0,MX) REP(j,0,MX) dp[i][j] = 2e9;

    s1 = "-"+s1;
    s2 = "-"+s2;

    dp[1][1] = 0;
    REP(i,1,s1.length()){
        REP(j,1,s2.length()){
            if(i==1&&j==1) continue;
            
            if(dp[i-1][j]!=2e9){
                if(str[dp[i-1][j]]==s1[i-1]){
                    dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                }
            }
            if(dp[i][j-1]!=2e9){
                if(str[dp[i][j-1]]==s2[j-1]){
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
    }

    // cout<<'\n';
    // REP(i,1,s1.length()){
    //     REP(j,1,s2.length()){
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    


    cout<<(dp[s1.length()][s2.length()]==str.length() ? "yes" : "no")<<'\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    REP(tc,1,t){
        cout<<"Data set "<<tc<<": ";
        solve();
    }

}