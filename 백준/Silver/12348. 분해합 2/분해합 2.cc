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

ll cal(ll n){
    ll ret = n;
    while(n){
        ret+=n%10;
        n/=10;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    for(ll i = max(0LL,n-170);i<n;i++){
        if(cal(i)==n) return !(cout<<i<<'\n');
    }
    cout<<0<<'\n';

}