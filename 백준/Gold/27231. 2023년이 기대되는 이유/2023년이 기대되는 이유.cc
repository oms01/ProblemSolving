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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/
set<ll> s;
string str;
void f(ll sum, ll cur, ll idx){
    if(idx==str.length()){
        s.insert(sum+cur);
        return;
    }

    //case1 idx에서 분기
    f(sum+cur, str[idx]-'0', idx+1);

    //case2 나중에 분기
    f(sum, cur*10+(str[idx]-'0'), idx+1);

}
ll cal(string str, ll m){
    ll sum = 0;
    for(auto x: str){
        ll ret = 1;
        rep(i,0,m) ret*=x-'0';
        sum += ret;
    }
    return sum;
}
void solve(){
    cin>>str;
    s.clear();

    f(0,0,0);

    ll mx = *max_element(all(s));

    ll ans = 0;
    for(ll i=1;i<=20;i++){
        ll sum = cal(str,i);
        if(s.count(sum)) ans++;
        
        if(sum > mx) break;
    }
    if(ans==20) cout<<"Hello, BOJ 2023!\n";
    else cout<<ans<<'\n';
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--){
        solve();
    }
}
