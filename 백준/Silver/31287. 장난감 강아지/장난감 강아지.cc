#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

ll n,k;
string str;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	cin>>n>>k;
	cin>>str;

	ll x=0,y=0;
	if(k>1000) k=1000;
	for(int i=0;i<n*k;i++){
		if(str[i%n]=='U') x--;
		else if(str[i%n]=='D') x++;
		else if(str[i%n]=='L') y--;
		else if(str[i%n]=='R') y++;

		if(x==0 && y==0){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

}