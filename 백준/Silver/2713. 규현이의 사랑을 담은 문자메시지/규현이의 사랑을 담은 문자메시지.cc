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
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/

int n,m; 
bool vis[30][30];
void solve(){
    memset(vis,0,sizeof(vis));
    cin>>n>>m;
    cin.ignore();
    string str; getline(cin,str);
    string seq = "";
    for(char x: str){
        int cur = 0;
        if(cur!=' ') cur = x-'A'+1;
        
        string s = "";
        int tmp = 16;
        while(tmp!=0){
            s+="10"[cur<tmp];
            if(cur>=tmp) cur-=tmp;
            tmp/=2;
        }
        seq+=s;
    }

    int idx = 0;
    pii cur = {0,0};
    vis[0][0] = 1;
    int dir = 0;
    vector<vector<int>> board(n,vector<int>(m,0));
    while(idx<seq.length()){
        board[cur.X][cur.Y] = seq[idx]-'0';

        int nx = cur.X + dx[dir];
        int ny = cur.Y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny]){
            dir = (dir+1)%4;
            nx = cur.X + dx[dir];
            ny = cur.Y + dy[dir];
        }

        cur = {nx,ny};
        vis[nx][ny] = 1;
        idx++;
    }

    rep(i,0,n) rep(j,0,m) cout<<board[i][j];
    cout<<'\n';
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();

}
