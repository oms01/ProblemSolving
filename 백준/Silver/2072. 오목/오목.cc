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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int ddx[] = {-1,0,1,1};
int ddy[] = {1,1,1,0};
const int MX = 19;
int board[MX+1][MX+1];
bool chk(int x,int y){
    // cout<<x<<' '<<y<<" :\n";
    rep(dir,0,4){
        int a = 1;
        while(1){
            int nx = x + ddx[dir]*a;
            int ny = y + ddy[dir]*a;
            if(nx<0||nx>=MX||ny<0||ny>=MX) break;
            if(board[x][y]!=board[nx][ny]) break;
            // cout<<nx<<' '<<ny<<'\n';
            a++;
        }
        int b = 1;
        while(1){
            int nx = x - ddx[dir]*b;
            int ny = y - ddy[dir]*b;
            if(nx<0||nx>=MX||ny<0||ny>=MX) break;
            if(board[x][y]!=board[nx][ny]) break;
            // cout<<nx<<' '<<ny<<'\n';
            b++;
        }
        if(a+b==6){
            return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,MX) rep(j,0,MX) board[i][j] = -1;

    int n; cin>>n;
    rep(i,0,n){
        int x,y; cin>>x>>y;
        board[x-1][y-1] = i%2;
        if(chk(x-1,y-1)){
            return !(cout<<i+1<<'\n');
        }
    }
    cout<<-1<<'\n';

}