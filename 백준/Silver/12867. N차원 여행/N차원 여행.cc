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

    int n,m; cin>>n>>m;
    vector<int> v(m);
    rep(i,0,m) cin>>v[i];
    string s; cin>>s;

    map<int,int> ma;
    rep(i,0,m){
        if(ma.find(v[i])==ma.end()) ma[v[i]] = ma.size();
    }
    rep(i,0,m){
        v[i] = ma[v[i]];
    }

    vector<int> loc(ma.size(),0);
    vector<vector<int>> vis;
    vis.push_back(loc);

    rep(i,0,m){
        loc[v[i]] += (s[i]=='+'?1:-1);
        for(auto t: vis){
            bool flag = 1;
            rep(j,0,t.size()){
                if(loc[j]!=t[j]) flag = 0;
            }
            if(flag) return !(cout<<0<<'\n');
        }
        vis.push_back(loc);
    }
    cout<<1<<'\n';
}

