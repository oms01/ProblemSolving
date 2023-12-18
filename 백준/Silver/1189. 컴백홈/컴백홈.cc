#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char board[10][10];
int cnt[10][10];
int n,m,k;
int ans = 0;
void dfs(int x,int y){
    if(x==0&&y==m-1){
        if(cnt[x][y]==k) ans++;
        return;
    }
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(cnt[nx][ny]) continue;
        if(board[nx][ny]=='T') continue;
        cnt[nx][ny] = cnt[x][y] + 1;
        dfs(nx,ny);
        cnt[nx][ny] = 0;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    cnt[n-1][0] = 1;
    dfs(n-1,0);
    cout<<ans<<'\n';
}