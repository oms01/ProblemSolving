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
int v[10];
//길이가 i, 마지막 두개가 j,k, 남은게 l,m,n,o,p일때 경우의 수
ll dp[6][6][11][11][11][11][11];
ll nxt[6][6][11][11][11][11][11];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    REP(i,1,n) cin>>v[i];
    int sum = 0;
    REP(i,1,n) sum+=v[i];
    
    dp[0][0][v[1]][v[2]][v[3]][v[4]][v[5]] = 1;

    rep(l,0,sum){
        REP(i,0,n) REP(j,0,n) REP(I,0,v[1]) REP(J,0,v[2]) REP(K,0,v[3]) REP(L,0,v[4]) REP(M,0,v[5]){
            nxt[i][j][I][J][K][L][M] = dp[i][j][I][J][K][L][M];
        }
        REP(i,0,n) REP(j,0,n) REP(I,0,v[1]) REP(J,0,v[2]) REP(K,0,v[3]) REP(L,0,v[4]) REP(M,0,v[5]){
            ll tmp = dp[i][j][I][J][K][L][M];
            if(tmp==0) continue;
            // cout<<l<<' '<<i<<' '<<j<<' '<<I<<' '<<J<<' '<<K<<' '<<L<<' '<<M<<'\n';
            if(I>0 && i!=1 && j!=1){
                nxt[j][1][I-1][J][K][L][M]+=tmp;
            }
            if(J>0 && i!=2 && j!=2){
                nxt[j][2][I][J-1][K][L][M]+=tmp;
            }
            if(K>0 && i!=3 && j!=3){
                nxt[j][3][I][J][K-1][L][M]+=tmp;
            }
            if(L>0 && i!=4 && j!=4){
                nxt[j][4][I][J][K][L-1][M]+=tmp;
            }
            if(M>0 && i!=5 && j!=5){
                nxt[j][5][I][J][K][L][M-1]+=tmp;
            }
        }
        REP(i,0,n) REP(j,0,n) REP(I,0,v[1]) REP(J,0,v[2]) REP(K,0,v[3]) REP(L,0,v[4]) REP(M,0,v[5]){
            dp[i][j][I][J][K][L][M] = nxt[i][j][I][J][K][L][M];
        }
    }

    ll ans = 0;
    REP(i,0,n) REP(j,0,n){
        ans += dp[i][j][0][0][0][0][0];
    }
    cout<<ans<<'\n';
    // cout<<"@";
    
}