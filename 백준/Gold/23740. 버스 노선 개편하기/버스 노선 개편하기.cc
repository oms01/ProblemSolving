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
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ti3> ans;

    int n; cin>>n;
    vector<ti3> v(n);
    for(auto& [s,e,c]: v) cin>>s>>e>>c;

    sort(all(v));
    int st = -1;
    int en = -1;
    int mn = 2e9;
    for(auto& [s,e,c]: v){
        if(en<s){
            ans.push_back({st,en,mn});
            st = s; en = e;
            mn = c;
        }
        else {
            en = max(en,e);
            mn = min(mn,c);
        }
    }
    ans.push_back({st,en,mn});

    cout<<ans.size()-1<<'\n';
    rep(i,1,ans.size()){
        auto [a,b,c] = ans[i];
        cout<<a<<' '<<b<<' '<<c<<'\n';
    }
}