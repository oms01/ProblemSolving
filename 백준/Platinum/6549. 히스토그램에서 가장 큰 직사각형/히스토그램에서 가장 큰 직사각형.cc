#include<bits/stdc++.h>
using namespace std;
long long board[100001];
long long n;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		cin>>n;
		if(n<=0) break;
		for(int i=0;i<n;i++){
			cin>>board[i];
		}
		board[n]=-1;
		
		stack<int> s;
		long long ans=0;
		for(int i=0;i<=n;i++){
			while(!s.empty() && board[i]<board[s.top()]){
				int height, weight;
				height=s.top();
				s.pop();
				if(s.empty()) weight=i;
				else weight=i-s.top()-1;
				ans=max(ans,board[height]*weight);
			}
			s.push(i);
		}
		cout<<ans<<'\n';
	}
}