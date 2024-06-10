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
/*----------------------*/

vector<int> adj[30];
int dist[26][26];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    rep(i,0,26) rep(j,0,26) dist[i][j] = 1e9;
    
    int n; cin>>n;
    rep(i,0,n){
        char s,e; string str; cin>>s>>str>>e;
        dist[s-'a'][e-'a'] = 1;
    }

    rep(k,0,26) rep(i,0,26) rep(j,0,26){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }

    int m; cin>>m;
    rep(i,0,m){
        char s,e; string str; cin>>s>>str>>e;
        cout<<(dist[s-'a'][e-'a']!=1e9 ? "T\n" : "F\n");
    }
}
