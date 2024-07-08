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

char board[7000][7000];
void f(pii loc, int sz){ // 시작 좌표, 크기
    if(sz==1){
        board[loc.X][loc.Y] = '*';
        return;
    }
    int t = sz/3;
    f({loc.X,loc.Y}, t); f({loc.X, loc.Y+t},t); f({loc.X, loc.Y+2*t},t);

    f({loc.X+t,loc.Y}, t);                      f({loc.X+t, loc.Y+2*t},t);

    f({loc.X+2*t,loc.Y}, t); f({loc.X+2*t, loc.Y+t},t); f({loc.X+2*t, loc.Y+2*t},t);


}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    f({0,0},n);

    rep(i,0,n){
        rep(j,0,n){
            if(board[i][j]!='*') cout<<' ';
            else cout<<board[i][j];
        }
        cout<<'\n';
    }

}