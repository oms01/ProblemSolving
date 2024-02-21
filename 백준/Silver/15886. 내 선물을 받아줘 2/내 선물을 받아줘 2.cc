#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string str; cin>>str;
    int cnt=0;
    rep(i,1,n){
        if(str[i-1]=='E'&&str[i]=='W') cnt++;
    }
    cout<<cnt<<'\n';
}