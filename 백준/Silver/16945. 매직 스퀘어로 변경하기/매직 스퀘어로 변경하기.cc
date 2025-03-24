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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
vector<vector<int>> square = {
    {2,7,6,9,5,1,4,3,8},
    {2,9,4,7,5,3,6,1,8},
    {4,3,8,9,5,1,2,7,6},
    {4,9,2,3,5,7,8,1,6},
    {6,1,8,7,5,3,2,9,4},
    {6,7,2,1,5,9,8,3,4},
    {8,1,6,3,5,7,4,9,2},
    {8,3,4,1,5,9,6,7,2}
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    vector<int> v(9);
    rep(i,0,9) cin>>v[i];

    int ans = 2e9;
    for(auto& x: square){
        int cnt = 0;
        rep(i,0,9){
            cnt += abs(x[i]-v[i]);
        }
        ans = min(ans, cnt);
    }
    cout<<ans<<'\n';
}