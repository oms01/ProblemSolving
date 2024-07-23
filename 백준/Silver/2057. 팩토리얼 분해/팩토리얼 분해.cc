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
vector<ll> f(20);
set<ll> s;
void ff(ll idx, ll val){
    if(idx==20){
        s.insert(val);
        return;
    }

    ff(idx+1,val);
    ff(idx+1,val+f[idx]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    f[0] = 1;
    rep(i,1,20){
        f[i] = f[i-1]*i;
    }
    ff(0,0);
    s.erase(0);

    ll n; cin>>n;
    cout<<(s.find(n)!=s.end() ? "YES\n":"NO\n");



}
