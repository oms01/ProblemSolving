#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vector<long double> v(n);
    rep(i,0,n){
        cin>>v[i];
    }
    ll cnt = 0;

    ll tmp = 0;
    rep(i,0,n-1){
        tmp = max(ceil(log2(v[i]/v[i+1])+tmp),(long double)0);
        cnt += tmp;
    }
    cout<<cnt<<'\n';
}
