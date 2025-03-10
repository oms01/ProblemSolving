#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int n,sum;
int v[10];
//길이가 i, 마지막 두개가 j,k, 남은게 l,m,n,o,p일때 경우의 수
ll dp[6][6][11][11][11][11][11];
int cnt = 0;
ll f(int len, int a, int b){
    if(len==sum) return 1;
    ll& ret = dp[a][b][v[1]][v[2]][v[3]][v[4]][v[5]];
    if(ret!=-1) return ret;

    ret = 0;
    REP(i,1,n){
        if(v[i]>0 && a!=i && b!=i){
            v[i]--;
            ret += f(len+1, b, i);
            v[i]++;
        }
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    REP(i,1,n) cin>>v[i];
    REP(i,1,n) sum+=v[i];

    memset(dp,-1,sizeof(dp));
    
    cout<<f(0,0,0)<<'\n';

    
}