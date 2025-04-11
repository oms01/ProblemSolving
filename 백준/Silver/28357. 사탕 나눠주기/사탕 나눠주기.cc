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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];

    ll st = 0, en = 2e15;
    while(st<=en){
        ll mid = (st+en)/2;
        ll sum = 0;
        rep(i,0,n){
            sum += max(v[i]-mid,0LL);
        }

        if(sum <= m){
            en = mid-1;
        }
        else{
            st = mid+1;
        }
    }
    cout<<st<<'\n';

}

