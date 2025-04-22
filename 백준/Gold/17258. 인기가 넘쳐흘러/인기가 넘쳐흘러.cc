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
typedef tuple<int,int,int> tiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

const int MX = 301;
int dp[MX+1][MX+1]; //i번째 구간, 사용 가능한 인원 j명
int cnt[MX+1];
int n,m,k,t; 
vector<pii> v;
int f(int idx, int num, int prv){
    if(idx==v.size()) return 0;
    if(dp[idx][num]) return dp[idx][num];

    int& ret = dp[idx][num];

    //이전 구간에서 cost보다 많이 썻으면 비용 안듦
    int cost = max(0, v[idx].Y-prv);

    if(num-cost>=0){
        return ret = max(f(idx+1,num-cost, v[idx].Y)+v[idx].X,f(idx+1,num,0));
    }
    return ret = f(idx+1,num,0);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k>>t;
    rep(i,0,m){
        int s,e; cin>>s>>e;
        rep(j,s-1,e-1) cnt[j] = min(t,cnt[j]+1);
    }

    int len = 1;
    rep(i,1,n){
        if(cnt[i]!=cnt[i-1]){
            v.push_back({len,t-cnt[i-1]});
            len = 0;
        }
        len++;
    }
    v.push_back({len,t-cnt[n-1]});

    cout<<f(0,k,0)<<'\n';


}