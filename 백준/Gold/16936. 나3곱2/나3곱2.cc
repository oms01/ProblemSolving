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
    int n; cin>>n;
    vector<ll> v(n);
    rep(i,0,n) cin>>v[i];
    
    vector<ll> nxt(n), indeg(n);
    int st = 0;
    rep(i,0,n) rep(j,0,n){
        if(v[i]*2==v[j] || (v[i]%3==0 && v[i]/3==v[j])){
            nxt[i] = j; indeg[j]++;
        }
    }
    rep(i,0,n) if(!indeg[i]) st = i;
    rep(i,0,n){
        cout<<v[st]<<' ';
        st = nxt[st];
    }
    
}