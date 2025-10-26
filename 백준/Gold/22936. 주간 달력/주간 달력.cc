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

const int MX = 50'000;
int arr[MX*2], chk[MX*2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        arr[s]++;
        arr[e+1]--;
        chk[e+1]++;
    }

    REP(i,1,MX) arr[i] += arr[i-1];
    REP(i,1,MX) arr[i] += arr[i-1];

    int mx = -2e9;
    int st = -1;
    REP(i,1,MX){
        if(mx < arr[i+n*7-1]-arr[i-1]){
            mx = arr[i+n*7-1]-arr[i-1];
            st = i;
        }
    }

    int ans = 0;
    rep(i,0,n){
        int s = st + i*7;
        rep(j,s+1,s+7){
            ans += chk[j];
        }
        ans+= arr[s+6]-arr[s+5];
    }
    cout<<ans<<'\n';
}
