#include <bits/stdc++.h>
using namespace std;
vector<int> v[50001];
int depth[50001];
int dp[50001][20];
void get_dp(int here,int pa){
    depth[here] = depth[pa] + 1;
    dp[here][0] = pa;
    for(int i=1;i<17;i++){
        dp[here][i] = dp[dp[here][i-1]][i-1];
    }
    for(int i=0;i<v[here].size();i++){
        if(v[here][i]!=pa) get_dp(v[here][i],here);
    }
}
void swap(int& a, int& b) { int t = a; a = b; b = t; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    depth[0] = -1;
    get_dp(1,0);
    
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
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