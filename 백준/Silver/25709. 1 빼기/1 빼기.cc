#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

string f(string s){
    rep(i,0,s.length()){
        if(s[i]=='1'){
            string ret = s.substr(0,i) + s.substr(i+1,s.length());
            return (ret==""?"0":ret);
        }
    }
    return "-1";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;

    int cnt = 0;
    while(s!="0"){
        int ret = stoi(f(s));
        s = to_string(ret==-1?stoll(s)-1:ret);
        cnt++;
    }
    cout<<cnt<<'\n';
}