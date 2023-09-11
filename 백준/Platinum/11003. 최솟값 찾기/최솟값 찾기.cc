#include<bits/stdc++.h>
using namespace std;
int n,l;
int arr[5000001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>l;
	for(int i=1;i<=n;i++) cin>>arr[i];
	deque<pair<int,int>> dq;
	for(int i=1;i<=n;i++){
		if(!dq.empty()){
			if(dq.front().second<i-l+1) dq.pop_front();
		}
		while(!dq.empty()&&dq.back().first>arr[i]) dq.pop_back();
		dq.push_back({arr[i],i});
		cout<<dq.front().first<<" ";
	}
	cout<<'\n';
}
/*
d1=a-1 ~ a1
n=12, l=3
1 5 2 3 6 2
3 7 3 5 2 6
*/