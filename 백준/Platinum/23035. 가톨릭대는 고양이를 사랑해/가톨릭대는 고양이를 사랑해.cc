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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    int t; cin>>t;
    vector<pii> v(t);
    for(auto&[a,b]: v) cin>>a>>b;

    sort(all(v));
    vector<int> tmp;
    tmp.push_back(v[0].Y);

    for(int i=1;i<t;i++){
        if(v[i].X>n||v[i].Y>m) continue;
        if(tmp.back() < v[i].Y){
            tmp.push_back(v[i].Y);
        }
        else{
            auto it = upper_bound(all(tmp), v[i].Y);
            *it = v[i].Y;
        }
    }
    cout<<tmp.size()<<'\n';
}