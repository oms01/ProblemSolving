#include<bits/stdc++.h>
using namespace std;
int n,h,a;
int up[500001];
int down[500001];
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>h;

	for(int i=0;i<n;i++){
		cin>>a;
		if(i%2==0) down[a]++;
		else up[a]++;
	}
	for(int i=h-1;i>=0;i--){
		up[i] += up[i+1];
		down[i] += down[i+1];
	}

	vector<int> ans;
	for(int i=1;i<=h;i++){
		//cout<<"h : "<<i<<" / "<<down[i]<<"+"<<up[h-i+1]<<"\n";
		ans.push_back(up[i] + down[h-i+1]);
	}
	sort(ans.begin(),ans.end());
	int cnt = 0;
	for(int i=0;i<ans.size();i++){
		if(ans[0]==ans[i]) cnt++;
	}
	cout<<ans[0]<<" "<<cnt;

}
