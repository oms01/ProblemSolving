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
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> ans(n);
    int cnt = 0;
    for(int i=0;i<n;i+=2){
        ans[i] = ++cnt;
    }
    cnt = 0;
    for(int i=1;i<n;i+=2){
        ans[i] = n - cnt++;
    }

    for(auto x: ans) cout<<x<<' '; cout<<'\n';
}