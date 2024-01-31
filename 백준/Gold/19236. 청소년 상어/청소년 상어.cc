#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {-1,-1,0,1,1,1,0,-1}; // 1 ~ 8 ; --
int dy[] = {0,-1,-1,-1,0,1,1,1};
vector<vector<int>> inputBoard(5,vector<int>(5));
vector<vector<int>> inputDirection(5,vector<int>(5));
int MX = 4;
int ans = 0;
void in(){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            cin>>inputBoard[i][j]>>inputDirection[i][j];
            inputDirection[i][j]--;
        }
    }
}
bool OOB(int x,int y){
    return (x<0||x>=MX||y<0||y>=MX);
}
void print(vector<vector<int>> board){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            cout<<board[i][j]<<' ';
        }
        cout<<'\n';
    }
}
pii getFishNum(int n, vector<vector<int>> board){
    for(int i=0;i<MX;i++){
        for(int j=0;j<MX;j++){
            if(board[i][j]==n){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}
void fishMove(vector<vector<int>> &board, vector<vector<int>> &direction){
    for(int i=1;i<=16;i++){
        pii cur = getFishNum(i,board);
        if(cur.X==-1 && cur.Y==-1) continue;
        int d = direction[cur.X][cur.Y];
        for(int dir=0;dir<8;dir++){
            int nx = cur.X + dx[(d+dir)%8];
            int ny = cur.Y + dy[(d+dir)%8];
            if(OOB(nx,ny)) continue;
            if(board[nx][ny]==-1) continue;
            direction[cur.X][cur.Y]= (d+dir)%8;
            swap(board[cur.X][cur.Y], board[nx][ny]);
            swap(direction[cur.X][cur.Y], direction[nx][ny]);
            break;
        }
    }
    return;
}
vector<pii> sharkMove(int x,int y,vector<vector<int>> board, vector<vector<int>> direction){
    vector<pii> ret;
    int dir = direction[x][y];
    for(int i=1;i<=3;i++){
        int nx = x + i*dx[dir];
        int ny = y + i*dy[dir];
        if(OOB(nx,ny)) continue;
        if(board[nx][ny]==0) continue;
        ret.push_back({nx,ny});
    }
    return ret;
}
void func(int x,int y, int val,vector<vector<int>> board, vector<vector<int>> direction){
    fishMove(board, direction);
    vector<pii> pos = sharkMove(x,y,board,direction);
    if(pos.empty()){
        ans = max(ans,val);
        return;
    }
    for(auto nxt : pos){
        int tmp = board[nxt.X][nxt.Y];       
        board[x][y] = 0;
        board[nxt.X][nxt.Y] = -1;
        func(nxt.X, nxt.Y, val + tmp, board, direction);
        board[nxt.X][nxt.Y] = tmp;
        board[x][y] = -1;
    }
    return;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
    in();
    int val = inputBoard[0][0];
    inputBoard[0][0] = -1;
    func(0,0,val, inputBoard, inputDirection);
    // printBoard();
    // cout<<'\n';
    // printDir();
    cout<<ans<<'\n';
}