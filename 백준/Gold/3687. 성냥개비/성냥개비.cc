#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

vector<vector<int>> dp(101,vector<int>(11,0));
ll atoll(vector<int> a){
    string ret="";
    for(int i=1;i<10;i++){
        while(a[i]--){
            ret+=(i+'0');
        }
    }

    string s = "";
    while(a[0]--) s+='0';
    if(ret.length()) ret = ret.substr(0,1) + s + ret.substr(1,ret.length()-1);
    if(ret=="") ret = "6";

    return stoll(ret);
}

void init(){
    dp[2][1]++; dp[3][7]++; dp[4][4]++; dp[5][2]++;
    dp[6][6]++; dp[7][8]++; dp[8][1]++; dp[8][0]++;
    dp[9][1]++; dp[9][8]++;
    
    for(int i=9;i<101;i++){
        ll a = 2e15;
        for(int j=7;j>=1;j--){
            vector<int> tmp;
            if(j==1){
                tmp = dp[i-6];
                tmp[0]++;
            }
            else{
                tmp = dp[i-j];
                tmp[atoll(dp[j])]++;
            }
            ll b = atoll(tmp);
            if(a < b) continue;

            a=b;
            for(int k=0;k<10;k++){
                dp[i][k] = tmp[k];
            }
        }
    }

}

string mx(int n){
    string ans = ""; //1이랑 7쓰는게 항상 최선
    if(n%2){
        ans+='7';
        n-=3;
    }
    n/=2;
    rep(i,0,n) ans+='1';
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    init();
    while(t--){
        int n; cin>>n;
        cout<<atoll(dp[n])<<' '<<mx(n)<<'\n';
    }
}