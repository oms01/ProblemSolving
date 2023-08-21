#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int board[1001][1001];
int dp[1001][1001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string str;
        cin>>str;
        for(int j=1;j<=m;j++){
            board[i][j] = str[j-1]-'0';
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(board[i][j]==0) continue;
            board[i][j] = min(board[i-1][j-1], min(board[i-1][j],board[i][j-1])) + 1;
            ans = max(ans,board[i][j]);
        }
    }
    cout<<ans*ans<<'\n';
}
