#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int d;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,q; cin>>n>>q;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    while(q--){
        int a; cin>>a;
        if(a==1){
            int b,c; cin>>b>>c;
            b--;
            v[(b+d)%n]+=c;
        }
        else if(a==3){
            int b; cin>>b;
            d+=b;
            d%=n;
        }
        else{
            int b; cin>>b;
            d-=b;
            d+=n;
            d%=n;
        }
    }

    rep(i,0,n) cout<<v[(i+d)%n]<<' '; cout<<'\n';
}