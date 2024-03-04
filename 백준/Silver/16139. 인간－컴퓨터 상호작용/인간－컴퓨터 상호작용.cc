#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int dp[200'001][26]; // dp[idx][alphabet] : idx까지 alp의 사용횟수
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str; cin>>str;
    rep(i,0,str.length()){
        dp[i+1][str[i]-'a']++;
    }
    rep(i,0,str.length()){
        rep(j,0,26){
            dp[i+1][j] += dp[i][j];
        }
    }
    int m; cin>>m;
    while(m--){
        char c; int st,en;
        cin>>c>>st>>en;

        cout<<dp[en+1][c-'a'] - dp[st][c-'a']<<'\n';
    }
}