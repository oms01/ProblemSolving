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

const int MX = 3e5;
int deg[MX+1];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pii> v(n);
    rep(i,0,n-1){
        cin>>v[i].X>>v[i].Y;
        deg[v[i].X]++; deg[v[i].Y]++;
    }

    int cnt = 0;
    REP(i,1,n){
        if(deg[i]>2) cnt += deg[i]-2;
    }
    cout<<cnt<<'\n';
}
