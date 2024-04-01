#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
string board[51];
int n;
int cnt(vector<char> v){
    int ret = 0;
    rep(i,0,n){
        int idx = i;
        while(idx<n && v[idx]==v[i]) idx++;
        ret = max(ret,abs(idx-i));
    }
    return ret;
}
int chk(pii cur, pii nxt){
    int mx = 0;
    vector<vector<char>> v;
    rep(i,0,n){
        vector<char> tmp;
        rep(j,0,n) tmp.push_back(board[i][j]);
        v.push_back(tmp);
    }
    rep(i,0,n){
        vector<char> tmp;
        rep(j,0,n) tmp.push_back(board[j][i]);
        v.push_back(tmp);
    }
    rep(i,0,v.size()){
        mx = max(mx, cnt(v[i]));
    }

    return mx;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i,0,n) cin>>board[i];

    int ans = chk({0,0},{0,0});
    
    rep(i,0,n){
        rep(j,0,n){
            for(int dir=0;dir<4;dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny]==board[i][j]) continue;
                swap(board[i][j],board[nx][ny]);
                ans = max(ans,chk({i,j},{nx,ny}));
                swap(board[i][j],board[nx][ny]);
            }
        }
    }
    cout<<ans<<'\n';
}