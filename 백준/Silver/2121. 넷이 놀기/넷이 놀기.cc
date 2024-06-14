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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,a,b; cin>>n>>a>>b;
    set<pii> s;
    rep(i,0,n){
        int x,y; cin>>x>>y;
        s.insert({x,y});
    }
    int ans=0;
    for(pii cur : s){
        if(s.find({cur.X,cur.Y+b})!=s.end()
            && s.find({cur.X+a,cur.Y})!=s.end()
            && s.find({cur.X+a,cur.Y+b})!=s.end()) ans++;
    }
    cout<<ans<<'\n';
}
