#include<bits/stdc++.h>
using namespace std;
int num[100001];
int dp[100001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>num[i];
		dp[i]=num[i];
	}
	int ans=dp[0];
	for(int i=1;i<t;i++){
		dp[i]=max(dp[i],dp[i-1]+num[i]);
		ans=max(ans,dp[i]);
	}
	cout<<ans;
}