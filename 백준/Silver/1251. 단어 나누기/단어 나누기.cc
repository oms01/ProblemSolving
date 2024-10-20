#include<bits/stdc++.h>
using namespace std;
string str;
vector<string> ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>str;
	for(int i=1;i<str.length()-1;i++){
		for(int j=i+1;j<str.length();j++){
			string tmp = str;
			reverse(tmp.begin(),tmp.begin()+i);
			reverse(tmp.begin()+i,tmp.begin()+j);
			reverse(tmp.begin()+j,tmp.end());
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0]<<"\n";
}