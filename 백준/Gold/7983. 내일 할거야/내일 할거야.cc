#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
    vector<pii> v(n);
    for(auto &[a,b]:v) cin>>a>>b;

    sort(all(v),[](pii a, pii b){
        return a.Y > b.Y;
    });

    int day = 2e9; //일을 시작할 수 있는 가장 늦은 날
    for(auto &[a,b]:v){
        // cout<<a<<' '<<b<<'\n';
        int t = min(day, b);
        day = t-a;
        // day = b-a;
        // cout<<day<<'\n';
    }
    // cout<<day-1<<'\n';
    cout<<day<<'\n';

}