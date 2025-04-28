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

const int MX = 1000;
ll board[MX+2][MX+2];
ll imos[MX+2][MX+2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n,m; cin>>n>>m;
    REP(i,1,n) REP(j,1,n) cin>>board[i][j];

    bool flag = 0;
    while(m--){
        ll q; cin>>q;
        if(q==1){
            ll a,b,x,y; cin>>a>>b>>x>>y;
            a++;b++;x++;y++;
            ll val; cin>>val;
            imos[a][b]+=val;
            imos[x+1][y+1]+=val;
            imos[x+1][b]-=val;
            imos[a][y+1]-=val;
        }
        else{
            if(!flag){
                REP(i,1,n){
                    REP(j,1,n){
                        imos[i][j] += imos[i][j-1];
                    }
                }
                REP(j,1,n){
                    REP(i,1,n){
                        imos[i][j] += imos[i-1][j];
                    }
                }
                REP(i,1,n){
                    REP(j,1,n) board[i][j]+=imos[i][j];
                }
                REP(i,1,n){
                    REP(j,1,n){
                        board[i][j] += board[i][j-1];
                    }
                }
                REP(j,1,n){
                    REP(i,1,n){
                        board[i][j] += board[i-1][j];
                    }
                }
                
                // REP(i,1,n){
                //     REP(j,1,n) cout<<board[i][j]<<' ';
                //     cout<<'\n';
                // }
                flag = 1;
            }
            int a,b,x,y; cin>>a>>b>>x>>y;
            a++;b++;x++;y++;
            cout<<board[x][y] - board[a-1][y] - board[x][b-1] + board[a-1][b-1]<<'\n';
            
        }
    }
}