#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,-1,0};
int dy[] = {-1,0,1};
int n,m,d;
int ans;
int input[20][20];
int board[20][20];
pii bfs(int x, int y){
    bool vis[20][20];
    memset(vis,0,sizeof(vis));
    queue<pii> q;
    q.push({x,y});
    vis[x][y] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for(int dir=0;dir<3;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            int dist = abs(x-nx) + abs(y-ny);
            if(nx<0||nx>=n||ny<0||ny>=m) continue; //범위 밖
            if(vis[nx][ny]) continue; //이미 탐색 완료
            if(dist>d) continue; //사거리 밖
            if(board[nx][ny]==1){
                return {nx,ny};
            }
            vis[nx][ny] = 1;
            q.push({nx,ny});
        }
    }
    return {-1,-1};
}
vector<pii> select(vector<pii> archer){
    vector<pii> ret;
    for(int i=0;i<archer.size();i++){
        pii loc = bfs(archer[i].X, archer[i].Y);
        if(loc.X==-1) continue;
        ret.push_back(loc);
    }
    return ret;
}
void move(){
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<m;j++){
            board[i+1][j] = board[i][j];
        }
    }
    rep(0,m) board[0][i] = 0;
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>input[i][j];
    }
    vector<int> p(m,0);
    rep(0,3) p[m-i-1]=1;

    do{
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = input[i][j];
            }
        }
        int cnt = 0;
        //1. 궁수 위치 저장
        vector<pii> archer;
        rep(0,m){
            if(p[i]) archer.push_back({n,i});
        }

        for(int i=0;i<n;i++){
            //2. 적 선정
            vector<pii> enemy = select(archer);
            //3. 적 공격
            for(auto cur : enemy){
                if(cur.X==-1 || !board[cur.X][cur.Y]) continue;
                board[cur.X][cur.Y] = 0;
                cnt++;
            }
            //3. 적 이동
            move();
        }
        ans = max(ans,cnt);

    }while(next_permutation(p.begin(),p.end()));
    cout<<ans<<'\n';
}