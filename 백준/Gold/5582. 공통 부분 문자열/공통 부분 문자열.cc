#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[4002][4002];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string a,b;
    cin>>a>>b;
    int mx = 0;
    for(int i=0;i<a.length();i++){
        for(int j=0;j<b.length();j++){
            if(a[i]==b[j]){
                dp[i][j] = 1;
                if(i!=0 && j!=0){
                    dp[i][j] +=dp[i-1][j-1];
                }
            }
            mx = max(mx,dp[i][j]);
        }
    }
    cout<<mx;
}
