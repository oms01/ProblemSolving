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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> v(1'000'001,0);
    rep(i,0,n){
        int st,en; cin>>st>>en;
        v[st]++; v[en+1]--;
    }
    rep(i,1,1'000'001) v[i] += v[i-1];

    int m; cin>>m;
    rep(i,0,m){
        int t; cin>>t;
        cout<<v[t]<<'\n';
    }
}
