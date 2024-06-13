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

int sum[301][301][11]; //0,0 에서 i,j까지 k의 개수
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,1,n+1) rep(j,1,n+1){
        int x; cin>>x;
        sum[i][j][x]=1;
    }

    rep(i,1,n+1) rep(j,1,n+1) rep(k,1,11) sum[i][j][k] += sum[i][j-1][k];
    rep(i,1,n+1) rep(j,1,n+1) rep(k,1,11) sum[j][i][k] += sum[j-1][i][k];


    int m; cin>>m;
    rep(i,0,m){
        int a,b,c,d; cin>>a>>b>>c>>d;
        int cnt = 0;
        rep(k,1,11){
            cnt += (bool)(sum[c][d][k] + sum[a-1][b-1][k] - sum[a-1][d][k] - sum[c][b-1][k]);
        }
        cout<<cnt<<'\n';
    }


}
