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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<ll> v(n); rep(i,0,n) cin>>v[i];

    ll st = 0, en = 2e15;
    while(st<=en){
        ll mid = (st+en)/2;
        ll cnt = 0;
        rep(i,0,n) cnt += (mid/v[i]);

        if(cnt<m){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }
    cout<<st<<'\n';
}