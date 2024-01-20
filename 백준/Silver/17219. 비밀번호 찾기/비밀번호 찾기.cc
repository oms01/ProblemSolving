#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a,b;
	cin>>a>>b;
	map<string,string> m;
	while(a--){
		string adr, pw;
		cin>>adr>>pw;
		m.insert({adr,pw});
	}
	while(b--){
		string str;
		cin>>str;
		cout<<m[str]<<'\n';
	}
}