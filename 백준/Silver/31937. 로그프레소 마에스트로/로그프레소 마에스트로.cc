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
    int n,m,k; cin>>n>>m>>k;
    vector<int> v(k);
    rep(i,0,k) cin>>v[i];
    sort(all(v));
    vector<tiii> log(m);
    rep(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        log[i] = {a,b,c};
    }
    sort(all(log));

    //첫 감염자가 i일때
    REP(i,1,n){
        
        set<int> ans;
        set<int> buf;
        ans.insert(i);

        int time = -1;
        for(auto& [t,a,b]: log){
            if(t!=time){
                time = t;
                for(auto x: buf) ans.insert(x);
                buf.clear();
            }
            if(ans.count(a)) buf.insert(b);
        }
        for(auto x: buf) ans.insert(x);
        // cout<<i<<" : ";
        // for(auto x: ans) cout<<x<<' '; cout<<'\n';

        
        if(ans.size()!=k) continue;

        bool flag = 1;
        for(auto x: v){
            if(!ans.count(x)) flag = 0;
        }
        if(!flag) continue;

        cout<<i<<'\n';
        return 0;
    }

}