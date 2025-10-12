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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/
const int MX = 100;
string board[MX+1];
int ddx[] = {-1,-1,-1,0,1,1,1,0};
int ddy[] = {-1,0,1,1,1,0,-1,-1};

void solve(){
    int n; cin>>n;
    set<pii> s;
    rep(i,0,n){
        cin>>board[i];
        rep(j,0,n) if(board[i][j]!='#') s.insert({i,j});
    }
    
    bool flag = 1;
    while(flag){
        flag = 0;
        vector<pii> v;
        for(auto [i,j]: s){
            int cnt = 0;
            vector<pii> tmp;
            rep(dir,0,8){
                int nx = i + ddx[dir];
                int ny = j + ddy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny]=='#') tmp.push_back({nx,ny});
                if(board[nx][ny]=='@') cnt++;
            }
            // # : 모름, @ : 지뢰, - : 없음
            
            //주변 지뢰 다 찾음
            if(cnt==board[i][j]-'0'){
                flag = 1;
                for(auto [a,b]: tmp){
                    board[a][b] = '-';
                }
                v.push_back({i,j});
            }
            //안열린칸이 모두 지뢰임
            else if(tmp.size()+cnt==board[i][j]-'0'){
                flag = 1;
                for(auto [a,b]: tmp){
                    board[a][b] = '@';
                }
                v.push_back({i,j});
            }
        }
        for(auto [i,j]: v) s.erase({i,j});
    }

    int ans = 0;
    rep(i,0,n) rep(j,0,n){
        if(board[i][j]=='@'||board[i][j]=='#') ans++;
    }
    cout<<ans<<'\n';

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();
}
