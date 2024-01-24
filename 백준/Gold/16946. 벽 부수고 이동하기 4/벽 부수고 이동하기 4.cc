#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef pair<int,int> pii;
typedef long long ll;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m;
string input[1001];
int vis[1001][1001];
int ans[1001][1001];
int sz[1'000'001];
void bfs(int x,int y,int i){
    int cnt = 1;
    queue<pii> q;
    vis[x][y] = i;
    q.push({x,y});
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(vis[nx][ny]!=0) continue;
            if(input[nx][ny]!='0') continue;
            vis[nx][ny] = i;
            q.push({nx,ny});
            cnt++;
        }
    }
    sz[i] = cnt;
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>input[i];
    }

    int idx = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j]!='0') continue;
            if(vis[i][j]!=0) continue;
            bfs(i,j,idx);
            idx++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(input[i][j]=='0') continue;

            set<int> s;
            for(int dir=0;dir<4;dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=m) continue;
                if(input[nx][ny]=='1') continue;
                s.insert(vis[nx][ny]);
            }
            ans[i][j]+=1;
            for(auto x:s){
                ans[i][j]+=sz[x];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ans[i][j]%10;
        }
        cout<<'\n';
    }
}