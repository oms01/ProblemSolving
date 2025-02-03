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
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    int st = 0;
    int en = n-1;

    int mn = 2e9;
    int ans = 2e9;
    while(st<en){
        int cur = v[st] + v[en];
        if(mn > abs(cur)){
            ans = cur;
            mn = abs(cur);
        }
        if(cur >= 0) en--;
        else st++;
    }
    cout<<ans<<'\n';

}