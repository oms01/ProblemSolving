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


const ll MX = 40;
ll dp[MX+1][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    string str; cin>>str;
    dp[0][0] = 1;
    dp[0][1] = 0;
    rep(i,1,str.length()){
        
        int tmp = (str[i-1]-'0')*10 + str[i]-'0';
        if(tmp==0) continue;

        if(str[i]!='0'){
            dp[i][0] = dp[i-1][0] + dp[i-1][1];
        }

        if(str[i-1]!='0' && tmp <= 34){
            dp[i][1] = dp[i-1][0];
        }
    }

    cout<<dp[str.length()-1][0] + dp[str.length()-1][1];
}