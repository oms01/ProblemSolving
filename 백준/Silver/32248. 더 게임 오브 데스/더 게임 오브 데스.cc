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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll n,t; cin>>n>>t;
    vector<int> v(n+1); REP(i,1,n) cin>>v[i];

    vector<int> dist(n+1,-1);
    int cur = 1;
    dist[cur] = 0;

    bool flag = 0;
    while(t-->0){
        int nxt = v[cur];
        if(!flag && dist[nxt]==-1){ 
            dist[nxt] = dist[cur]+1;
        }
        else if(!flag && dist[nxt]!=-1){
            flag = 1;
            int sz = dist[cur] - dist[nxt]+1;
            t%=sz;
        }
        
        cur = nxt;
    }
    cout<<cur<<'\n';

}