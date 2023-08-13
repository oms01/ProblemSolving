#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int func(char op,int a,int b){
    return op=='*' ? (a*b)%7 : (a+b)%7;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<vector<bool>> dp(n+1,vector<bool>(7));
        dp[0][1] = true;
        //dp[i][m] = ith 선택지를 고른 이후, k mod 7 = m 
        for(int j=1;j<=n;j++){
            char op1,op2;
            int v1,v2;
            cin>>op1>>v1>>op2>>v2;
            for(int k=0;k<7;k++){
                if(dp[j-1][k]){
                    dp[j][func(op1,k,v1)] = true;
                    dp[j][func(op2,k,v2)] = true;
                }
            }
        }
        cout<<(dp[n][0] ? "LUCKY\n" : "UNLUCKY\n");
    }
}
