#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
string a,b;
string res;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	int idx = b.size();
	for(int i = a.size();i>=1;i--){
		for(int j=idx;j>=1;j--){
			if(dp[i][j]==dp[i-1][j]){
				idx=j;
				break;
			}
			else if(dp[i][j]==dp[i][j-1]) continue;
			else{
				res+=a[i-1];
			}
		}
	}
	cout<<dp[a.length()][b.length()]<<'\n';
	reverse(res.begin(),res.end());
	cout<<res;
}