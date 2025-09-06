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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,k,m; cin>>n>>k>>m;
    vector<ll> v;
    rep(i,0,n){
        ll x; cin>>x;
        if(x>=2*k) x-=2*k;
        else if(x>k) x-=k;
        else continue;

        v.push_back(x);
    }

    ll st = 0, en = 2e15;
    while(st+1<en){
        ll mid = (st+en)/2;

        ll cnt = 0;
        for(auto x: v){
            cnt += x/mid;
        }

        if(cnt<m){
            en = mid;
        }
        else{
            st = mid;
        }
    }

    if(st==0||st==2e15) cout<<-1<<'\n';
    else cout<<st<<'\n';
}