#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/


string board[2001],type[2001];
int s[2001][2001];
int n,m,k;
int sol(int t){
    rep(i,0,n){
        rep(j,0,m){
            s[i+1][j+1] = (board[i][j]!="WB"[(i+j+t)%2]) + s[i+1][j];
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            s[i+1][j+1] += s[i][j+1];
        }
    }
    int ret=2e9;
    rep(i,1,n-k+2){
        rep(j,1,m-k+2){
            pii st = {i,j};
            pii en = {i+k-1,j+k-1};
            int tmp = s[en.X][en.Y] - s[en.X][st.Y-1] - s[st.X-1][en.Y] + s[st.X-1][st.Y-1];
            ret = min(ret,tmp);
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i,0,n) cin>>board[i];
    cout<<min(sol(0),sol(1))<<'\n';



}