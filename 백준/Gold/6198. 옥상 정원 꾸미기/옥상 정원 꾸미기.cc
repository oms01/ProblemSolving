#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	long long cnt=0;
	stack<int> S;
	for(int i=0;i<t;i++){
		int height;
		cin>>height;
		while(!S.empty()){
			if(height<S.top()){
				break;
			}
			S.pop();
		}
		cnt+=(long long)S.size();
		S.push(height);
	}
	cout<<cnt;
	
}