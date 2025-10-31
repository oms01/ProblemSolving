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
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(n); rep(i,0,n) cin>>v[i];
    sort(all(v));
    int cnt = 0;
    rep(i,0,(n+1)/2){
        cnt += log2(v[i]);
    }
    cout<<cnt+1<<'\n';
}
