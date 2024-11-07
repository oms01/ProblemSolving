#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

vector<int> v[100'001];
int depth[100'001];
int dp[100'001][20];
int chk[100'001];

void get_dp(int cur,int pa){
    depth[cur] = depth[pa] + 1;
    dp[cur][0] = pa;
    for(int i=1;i<17;i++){
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
    }
    for(auto nxt : v[cur]){
        if(nxt!=pa) get_dp(nxt,cur); 
    }
}
void solve(){
    memset(dp,0,sizeof(dp));
    memset(depth,0,sizeof(depth));
    memset(chk,0,sizeof(chk));
    rep(i,0,100'001) v[i].clear();


    int n; cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        chk[b] = 1;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int root = -1;
    rep(i,1,n+1){
        if(!chk[i]) root = i;
    }
    
    depth[0] = -1;
    get_dp(root,0);

    int x,y; cin>>x>>y;

    if(depth[x] > depth[y]) swap(x,y);

    for(int i=17;i>=0;i--){
        if(depth[x]<=depth[dp[y][i]]){
            y = dp[y][i];
        }
    }
    int lca = x;

    if(x!=y){
        for(int i=16;i>=0;i--){
            if(dp[x][i]!=dp[y][i]){
                x = dp[x][i];
                y = dp[y][i];
            }
            lca = dp[x][i];
        }
    }
    cout<<lca<<'\n';

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}