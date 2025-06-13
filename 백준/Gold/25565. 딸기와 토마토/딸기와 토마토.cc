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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 2000;
int board[MX+1][MX+1];
int d[MX+1][MX+1][5];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,k; cin>>n>>m>>k;
    rep(i,0,n) rep(j,0,m) cin>>board[i][j];


    int mx = 0;
    int cnt = 2*k; //점의 개수
    rep(i,0,n) rep(j,0,m){
        if(!board[i][j]) continue;
        cnt--;
        rep(dir,0,4){
            int nx = i + dx[dir];
            int ny = j + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            d[i][j][0] += board[nx][ny];
            d[i][j][dir+1] += board[nx][ny];
        }
        mx = max(mx,d[i][j][0]);
    }

    cout<<cnt<<'\n';
    if(!cnt) return 0;

    if(mx==4||mx==3){
        // + or ㅗ
        rep(i,0,n) rep(j,0,m) if(d[i][j][0]==4||d[i][j][0]==3) return !(cout<<i+1<<' '<<j+1<<'\n');
    }
    if(mx==2||mx==1){
        // ㄴ
        rep(i,0,n) rep(j,0,m){
            if(d[i][j][0]==2){
                if((d[i][j][1]&&d[i][j][2]) || (d[i][j][2]&&d[i][j][3]) || (d[i][j][3]&&d[i][j][4]) || (d[i][j][4]&&d[i][j][1])){
                    return !(cout<<i+1<<' '<<j+1<<'\n');
                }
            }
        }
        // ㅡ
        rep(i,0,n) rep(j,0,m){
            if(d[i][j][0]==1){
                //i, j가 시작점
                rep(dir,0,4){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(nx<0||nx>=n||ny<0||ny>=m) continue;
                    if(board[nx][ny]){
                        //방향 결정
                        vector<pii> ans;
                        pii cur = {i+dx[dir]*(k-cnt), j+dy[dir]*(k-cnt)};
                        rep(I,0,cnt){
                            int nnx = cur.X + dx[dir]*I;
                            int nny = cur.Y + dy[dir]*I;
                            ans.push_back({nnx,nny});
                        }
                        sort(all(ans));
                        for(auto [a,b]: ans){
                            cout<<a+1<<' '<<b+1<<'\n';
                        }
                        return 0;
                    }
                }
            }
        }
    }
    if(mx==0){
        // .
        rep(i,0,n) rep(j,0,m) if(board[i][j]) return !(cout<<i+1<<' '<<j+1<<'\n');
    }
    
    
}