#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

string str;
bool chk(string s){
    rep(i,0,s.length()/2){
        if(s[i]!=s[s.length()-i-1]) return 0;
    }
    return 1;
}
string f(int n){
    string s = to_string(n);
    while(s.length() < str.length()){
        s="0"+s;
    }
    return s;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    while(cin>>str){
        if(str=="0") break;
        int ans = 0;
        while(!chk(str)){
            ans++;
            str = f(stoi(str)+1);
        }
        cout<<ans<<'\n';
    }
}