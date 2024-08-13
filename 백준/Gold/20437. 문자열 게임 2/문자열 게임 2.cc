#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
void solve(){
    string str; cin>>str;
    int n; cin>>n;
    vector<int> v[30];
    rep(i,0,str.length()){
        v[str[i]-'a'].push_back(i);
    }
    int mn = 2e9;
    int mx = -1;
    rep(i,0,26){
        rep(j,0,(int)v[i].size()-n+1){
            mx = max(mx, v[i][j+n-1] - v[i][j] + 1);
            mn = min(mn, v[i][j+n-1] - v[i][j] + 1);
        }
    }

    if(mn==2e9 || mx==-1) cout<<-1<<'\n';
    else cout<<mn<<' '<<mx<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}