#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    priority_queue<ll,vector<ll>,greater<>> pq;
    rep(i,0,n){
        ll val; cin>>val;
        pq.push(val);
    }
    ll ans = 0;
    while(pq.size()!=1){
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        pq.push(a+b);
        ans+=a+b;
    }
    cout<<ans<<'\n';

}