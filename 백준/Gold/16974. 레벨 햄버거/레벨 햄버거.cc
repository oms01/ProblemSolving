#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

ll len[51];
ll p[51];

ll f(ll n,ll x){
    if(n==0){
        return 1;
    }

    if(x==1){
        return 0;
    }
    else if(x<=(1+len[n-1])){
        return f(n-1,x-1);
    }
    else if(x==(2+len[n-1])){
        return p[n-1]+1;
    }
    else if(x<=(2+len[n-1]*2)){
        return p[n-1] + 1 + f(n-1,x-(2+len[n-1]));
    }
    else{
        return p[n-1]*2 + 1;
    }
}   
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,x; cin>>n>>x;
    len[0] = 1;
    p[0] = 1;
    REP(i,1,50){
        len[i] = len[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }
    cout<<f(n,x)<<'\n';
}