#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000
int dp[5'001];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str;
    cin>>str;
    if(str[0]=='0'){
        cout<<"0\n";
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=str.length();i++){

        if(str[i-1]-'0'>=1 && str[i-1]-'0'<=9){
            dp[i] = (dp[i-1] + dp[i])%MOD;
        }


        if(i==1) continue;
        string tmp = str.substr(i-2,2);

        if(stoi(tmp) >= 10 && stoi(tmp)<=26){
            dp[i] = (dp[i-2] + dp[i])%MOD;
        }

    }
    cout<<dp[str.length()]<<'\n';
    // for(int i=0;i<=str.length();i++){
    //     cout<<dp[i]<<' ';
    // }
}
