#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int n,m; 
string board[3'001];
void down(int dist){
    rep(i,0,m){
        int land = n-1;
        while(board[land][i]=='#' && land>=0) land--;

        for(int j=land;j>=0;j--){
            if(board[j][i]=='X'){
                swap(board[j][i],board[j+dist][i]);
            }
        }
    }
}

int getDistance(){
    int dist = 2e9;
    rep(i,0,m){
        int meteor = -1;
        int land = -1;
        rep(j,0,n){
            if(board[j][i]=='X') meteor = j;
            if(board[j][i]=='#'){
                land = j;
                break;
            }
        }
        if(meteor==-1) land=2e9;
        dist = min(dist,land-meteor-1);
    }
    return dist;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin>>n>>m;
    rep(i,0,n) cin>>board[i];

    int dist = getDistance();
    down(dist);

    rep(i,0,n) cout<<board[i]<<'\n';

}