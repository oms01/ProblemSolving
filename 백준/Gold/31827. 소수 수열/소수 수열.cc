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

const int MX = 1e6;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;

    vector<bool> state(MX+1,1);
    for(int i=2;i*i<=MX;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=MX;j+=i) state[j] = 0;
    }
    vector<int> ans;
    for(int i=2;i<=MX;i++){
        if(state[i] && (i+1)%k==0) ans.push_back(i);
        if(ans.size()==n) break;
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<' '; cout<<'\n';

}