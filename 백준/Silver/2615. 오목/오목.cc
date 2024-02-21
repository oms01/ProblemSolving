#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;


int dx[] = {-1,0,1,1};
int dy[] = {1,1,1,0};
int board[20][20];
bool vis[20][20];
pii bwin = {-1,-1};
pii wwin = {-1,-1};
vector<pii> black,white;
bool OOB(int x,int y){
    return (x<0||x>=19||y<0||y>=19);
}
void dfs(int x,int y, int color, int dir, int cnt){
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(cnt==5){
        if(!OOB(nx,ny)&&board[nx][ny]==color){
            return;
        }
        x -= dx[dir]*4;
        y -= dy[dir]*4;

        if(!OOB(x-dx[dir],y-dy[dir])&&board[x-dx[dir]][y-dy[dir]]==color){
            return;
        }

        if(color==1) bwin = {x,y};
        if(color==2) wwin = {x,y};
        return;
    }
    if(OOB(nx,ny)) return;
    if(board[nx][ny]!=color) return;
    dfs(nx,ny,color,dir,cnt+1);
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    rep(i,0,19){
        rep(j,0,19){
            cin>>board[i][j];
            if(board[i][j]==1) black.push_back({i,j});
            if(board[i][j]==2) white.push_back({i,j});
        }
    }
    for(auto cur: black){
        rep(dir,0,4){
            if(bwin.X!=-1);
            dfs(cur.X,cur.Y,1,dir,1);
        }
    };

    for(auto cur: white){
        rep(dir,0,4){
            if(wwin.X!=-1);
            dfs(cur.X,cur.Y,2,dir,1);
        }
    };

    if(bwin.X==-1 && wwin.X==-1){
        cout<<0<<'\n';
    }
    else if(bwin.X!=-1){
        cout<<1<<'\n';
        cout<<bwin.X+1<<' '<<bwin.Y+1<<'\n';
    }
    else if(wwin.X!=-1){
        cout<<2<<'\n';
        cout<<wwin.X+1<<' '<<wwin.Y+1<<'\n';
    }

}