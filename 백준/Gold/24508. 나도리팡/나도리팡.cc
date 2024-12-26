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
    
    ll n,k,t; cin>>n>>k>>t;
    vector<ll> v(n);
    ll sum = 0;
    rep(i,0,n){
        cin>>v[i];
        sum+=v[i];
    }

    ll cnt = 0;
    sort(rall(v));
    rep(i,0,sum/k) cnt+=k-v[i];

    bool flag = (sum%k) | (cnt>t);
    cout<<(flag?"NO":"YES");

    
}
