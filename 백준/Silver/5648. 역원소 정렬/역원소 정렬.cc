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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> v(n);
    rep(i,0,n){
        ll x; cin>>x;
        string tmp = to_string(x);
        reverse(all(tmp));
        v[i] = stoll(tmp);
    } 
    sort(all(v));
    rep(i,0,n) cout<<v[i]<<'\n';


}