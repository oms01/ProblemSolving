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
    ll cnt = 0;
    ld avg = 0;
    rep(i,0,n){
        cin>>v[i];
        if(v[i]>=2){
            cnt++;
            avg+=v[i];
        }
    }
    if(cnt!=0) avg = (ld)avg/(ld)cnt;

    vector<int> ans(m+1);
    rep(i,0,n){
        if(v[i] > avg) v[i] = 1;
        if(v[i] > m) return !(cout<<-1<<'\n');
        ans[v[i]]++;
    }

    ll sum = n;
    for(int i=1;i<=m;i++){
        cout<<sum<<' ';
        sum=max(sum-ans[i],0LL);
    }
}

