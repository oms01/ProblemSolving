#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int parent[100'001];
int candy[100'001];
int sz[100'001];
int Find(int n){
    if(parent[n]==n) return n;
    return parent[n] = Find(parent[n]);
}
void Union(int a, int b){
    a = Find(a); b = Find(b);
    parent[b] = a;
}

int dp[3001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    rep(i,1,n+1){
        cin>>candy[i];
        parent[i]=i;
        sz[i]=1;
    }

    rep(i,0,m){
        int a,b; cin>>a>>b;
        Union(a,b);
    }
    rep(i,1,n+1){
        if(parent[i]!=i){
            int t = Find(i);
            candy[t]+=candy[i];
            sz[t]+=sz[i];
        }
    }

    rep(i,1,n+1){
        if(Find(i)!=i) continue;
        for(int j=k-1;j-sz[i]>=0;j--){
            dp[j] = max(dp[j], dp[j-sz[i]]+candy[i]);
        }
    }
    cout<<dp[k-1];

}