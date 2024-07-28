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
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
vector<int> adj[10];
int f(int cur){
    if(!adj[cur].size()) return 2;

    int cnt = 1;
    for(int nxt : adj[cur]){
        cnt *= f(nxt);
    }
    return cnt+1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n){
        int x; cin>>x;
        adj[x].push_back(i);
    }
    cout<<f(n)-1;

}