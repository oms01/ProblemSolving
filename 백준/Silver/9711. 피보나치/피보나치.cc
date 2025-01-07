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
ll fibo[10'001];

void solve(int caseNo){
    ll p,q; cin>>p>>q;

    fibo[1] = 1;
    rep(i,2,p+1){
        fibo[i] = (fibo[i-1] + fibo[i-2])%q;
    }
    cout<<"Case #"<<caseNo<<": "<<fibo[p]%q<<'\n';
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}