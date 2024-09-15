#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/
int n,m,k,g;
int board[101][101];
int convX(int x){
    return (x+n)%n;
}
int convY(int y){
    return (y+m)%m;
}

int cntNeighbors(int x, int y){
    int cnt = 0;
    pii up = (x==0 ? make_pair(x,y+m/2) : make_pair(convX(x-1), y));
    pii down = (x==n-1 ? make_pair(x,y+m/2) : make_pair(convX(x+1),y));

    // for(int i:{-1,0,1}) cout<<up.X<<','<<convY(up.Y+i)<<' '; cout<<'\n';
    // for(int i:{-1,0,1}) cout<<x<<','<<convY(y+i)<<' '; cout<<'\n';
    // for(int i:{-1,0,1}) cout<<down.X<<','<<convY(down.Y+i)<<' '; cout<<'\n';

    // for(int i:{-1,0,1}) cout<<board[up.X][convY(up.Y+i)]<<' '; cout<<'\n';
    // for(int i:{-1,0,1}) cout<<board[x][convY(y+i)]<<' '; cout<<'\n';
    // for(int i:{-1,0,1}) cout<<board[down.X][convY(down.Y+i)]<<' '; cout<<'\n';


    for(int i : {-1,0,1}){
        cnt += (board[up.X][(up.Y+i+m)%m]);
        cnt += (board[down.X][(down.Y+i+m)%m]);
    }
    for(int i : {-1,1}){
        cnt += board[x][(y+i+m)%m];
    }
    return cnt;
}
void cal(){
    int nxt[n][m];
    rep(i,0,n) rep(j,0,m){
        int cnt = cntNeighbors(i,j);
        nxt[i][j] = ((!board[i][j] && cnt==3) || (board[i][j] && (cnt==2||cnt==3)));
    }
    rep(i,0,n) rep(j,0,m){
        board[i][j] = nxt[i][j];
    }
    // rep(i,0,n){
    //     rep(j,0,m) cout<<board[i][j]<<' ';
    //     cout<<'\n';
    // }
    // cout<<"=========\n";
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int tc = 1;
    while(cin>>n>>m){ //링의 개수, 링 내 칸의 개수
        if(n==0&&m==0) break;
        memset(board,0,sizeof(board));
        cin>>k;
        rep(i,0,k){
            int x,y; cin>>x>>y;
            board[x][y] = 1;
        }

        cin>>g;
        while(g--) cal();

        int cnt = 0;
        vector<pii> loc;
        rep(i,0,n) rep(j,0,m){
            if(board[i][j]) {
                cnt++;
                if(loc.size()==2) loc.pop_back();
                loc.push_back({i,j});
            }
        }
        cout<<"Case "<<tc++<<": ";
        cout<<cnt<<' ';
        rep(i,0,2){
            if(i<loc.size()) cout<<loc[i].X<<' '<<loc[i].Y<<' ';
            else cout<<-1<<' '<<-1<<' ';
        }
        cout<<'\n';
    }

}