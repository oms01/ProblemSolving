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
int n,m;
int board[101][101];
int cnt;
void f(pii loc){
    rep(i,loc.X,n) rep(j,loc.Y,m){
        if(board[i][j]==1){
            board[i][j] = 0;
            cnt--;
            f({i,j});
            return;
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i,0,n) rep(j,0,m){
        cin>>board[i][j];
        if(board[i][j]==1) cnt++;
    }

    int ans = 0;
    while(cnt){
        f({0,0});
        ans++;
    }
    cout<<ans<<'\n';

}