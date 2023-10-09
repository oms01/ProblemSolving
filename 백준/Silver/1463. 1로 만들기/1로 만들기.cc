#include<bits/stdc++.h>
using namespace std;
int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> dp(n+1);
	dp[1]=0;
	for(int i=2;i<=n;i++){ // 밑에서부터 올라가는 방식
		dp[i]=dp[i-1]+1; // 1로 뺀 경우
		if(!(i%3)){ //3으로 나눈 경우
			dp[i]=min(dp[i],dp[i/3]+1);
		} 
		if(!(i%2)){ //2로 나눈 경우
			dp[i]=min(dp[i],dp[i/2]+1);
		}
	}
	cout<<dp[n];
}