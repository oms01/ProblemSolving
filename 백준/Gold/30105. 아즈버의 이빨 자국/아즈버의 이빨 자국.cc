#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
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

vector<int> v;
unordered_set<int> s;
bool chk(int n){
    rep(i,0,v.size()){
        if(!s.count(v[i]-n) && !s.count(v[i]+n)){
            return 0;
        }
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    v.resize(n);
    rep(i,0,n) cin>>v[i];

    for(auto x: v) s.insert(x);

    vector<int> ans;
    for(int i=1;i<n;i++){
        if(chk(v[i]-v[0])) ans.push_back(v[i]-v[0]);
    }

    cout<<ans.size()<<'\n';
    for(auto x: ans) cout<<x<<' ';
    cout<<'\n';
}