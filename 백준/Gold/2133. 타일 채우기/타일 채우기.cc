#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dp[31];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if(n%2){
        cout<<0<<'\n';
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4;i<=n;i+=2){
        dp[i] = dp[i-2]*dp[2];
        for(int j=i-4;j>=0;j-=2){
            dp[i]+=dp[j]*2;
        }
    }
    cout<<dp[n];

}
