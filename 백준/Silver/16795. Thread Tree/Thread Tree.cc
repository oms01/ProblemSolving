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

map<int,vector<int>> adj;
vector<string> v;
void dfs(int cur, int dep){
    rep(i,0,dep) cout<<'.';
    cout<<v[cur]<<'\n';
    // sort(all(adj[cur]));
    for(auto nxt : adj[cur]){
        dfs(nxt,dep+1);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    vector<int> st;
    v.resize(t);
    rep(i,0,t){
        int n; cin>>n;
        cin>>v[i];
        if(n!=0){
            adj[n-1].push_back(i);
        }
        else{
            st.push_back(i);
        }
    }
    for(auto x : st){
        dfs(x,0);
    }
    
}