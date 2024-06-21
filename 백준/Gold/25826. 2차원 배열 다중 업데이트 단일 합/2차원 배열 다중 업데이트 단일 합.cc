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

ll input[1002][1002];
ll board[1002][1002];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    rep(i,0,n) rep(j,0,n) cin>>input[i][j];
    while(m--){
        ll x; cin>>x;
        ll s1,e1,s2,e2; cin>>s1>>e1>>s2>>e2;
        if(x==1){
            ll k; cin>>k;
            board[s1][e1]+=k;
            board[s2+1][e2+1]+=k;
            board[s1][e2+1]-=k;
            board[s2+1][e1]-=k;
        }
        else{
            rep(i,0,n) rep(j,1,n) board[i][j] += board[i][j-1];
            rep(i,0,n) rep(j,1,n) board[j][i] += board[j-1][i];
            rep(i,0,n) rep(j,0,n) board[i][j] += input[i][j];
            ll ans = 0;
            rep(i,s1,s2+1) rep(j,e1,e2+1) ans+=board[i][j];
            cout<<ans<<'\n';
        }
    }
    
}
