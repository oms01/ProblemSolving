#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
const ll MOD = 1'000'000'007;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        while(n--){
            ll x; cin>>x;
            pq.push(x);
        }
        ll ans = 1;
        while(pq.size()!=1){
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            pq.push(a*b);
            ans = (ans%MOD)*((a*b)%MOD);
        }
        cout<<ans%MOD<<'\n';
    }
}