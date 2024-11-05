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

const int MX = 1'001;
vector<int> LL[MX];
int RR[MX];
bool vis[MX];

bool dfs(int x){
    for(auto nxt : LL[x]){
        if(vis[nxt]) continue;

        vis[nxt] = 1;
        if(RR[nxt]==0 || dfs(RR[nxt])){
            RR[nxt] = x;
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    rep(i,1,n+1){
        int t; cin>>t;
        while(t--){
            int a; cin>>a;
            LL[i].push_back(a);
        }
    }
    int cnt = 0;
    rep(i,1,n+1){
        memset(vis,0,sizeof(vis));
        cnt+=dfs(i);
    }
    cout<<cnt<<'\n';

}