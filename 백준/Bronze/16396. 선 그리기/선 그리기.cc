#include<bits/stdc++.h>
using namespace std;
bool arr[10001];
int t,s,e,ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s>>e;
		for(int i=s;i<e;i++){
			arr[i]=1;
		}
	}
	for(int i=0;i<10001;i++){
		if(arr[i]==1) ans++;
	}
	cout<<ans;
}
