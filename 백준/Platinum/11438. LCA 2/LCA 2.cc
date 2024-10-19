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

vector<int> v[100001];
int depth[100001];
int dp[100001][20];
void get_dp(int cur,int pa){
    depth[cur] = depth[pa] + 1;
    dp[cur][0] = pa;
    for(int i=1;i<17;i++){
        dp[cur][i] = dp[dp[cur][i-1]][i-1];
    }
    for(int i=0;i<v[cur].size();i++){
        if(v[cur][i]!=pa) get_dp(v[cur][i],cur);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n;
    for(int i=1;i<n;i++){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[0] = -1;
    get_dp(1,0);
    
    cin>>m;
    while(m--){
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
}