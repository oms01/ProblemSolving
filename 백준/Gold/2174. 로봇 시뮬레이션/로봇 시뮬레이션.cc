#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int dx[] = {-1,0,1,0}; // 북 서 남 동
int dy[] = {0,-1,0,1};
int board[101][101];
int a,b;
int n,m; //로봇 수, 명령 수 
vector<pair<int,int>> robot;
int front(int idx){ //로봇의 좌표, 방향 // -1:이동성공, 0:벽충돌, 그외:로봇 충돌
    int curX, curY; //현재 로봇 좌표
    tie(curX,curY) = robot[idx];
    int dir = board[curX][curY]; //로봇 방향

    int nx = curX + dx[dir-1]; //다음 로봇 좌표
    int ny = curY + dy[dir-1];
    if(nx<0||nx>=a||ny<0||ny>=b) return 0; //벽
    if(board[nx][ny]!=0){ //로봇

        for(int i=0;i<robot.size();i++){
            if(robot[i].X==nx && robot[i].Y==ny){
                return i+1;
            }
        }
    }


    board[nx][ny] = dir;
    board[curX][curY] = 0;
    robot[idx] = {nx,ny};
    return -1;
}

int right(int idx){
    
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>b>>a;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        int x,y;
        char z;
        cin>>y>>x>>z;
        if(z=='N') board[a-x][y-1] = 1; //북
        else if(z=='W') board[a-x][y-1] = 2; //서
        else if(z=='E') board[a-x][y-1] = 4; //남
        else board[a-x][y-1] = 3; //동
        robot.push_back({a-x,y-1});
    }


    for(int i=0;i<m;i++){
        int x,z;
        char y;
        cin>>x>>y>>z;

        int curX, curY; //현재 로봇 좌표
        tie(curX,curY) = robot[x-1];
        int dir = board[curX][curY]; //로봇 방향

        if(y=='L'){
            dir+=z;
            if(dir%4==0) dir=4;
            else dir%=4;

            board[curX][curY] = dir;
        }
        else if(y=='R'){
            z%=4;
            dir-=z;
            if(dir<=0) dir+=4;
            
            board[curX][curY] = dir;
        }
        else{ //y==F
            for(int j=0;j<z;j++){
                int ret = front(x-1);

                if(ret==0){
                    cout<<"Robot "<<x<<" crashes into the wall\n";
                    return 0;
                }
                else if(ret!=-1){
                    cout<<"Robot "<<x<<" crashes into robot "<<ret<<"\n";
                    return 0;
                }

            }
        }
    }
    cout<<"OK\n";

    // for(int i=0;i<a;i++){
    //     for(int j=0;j<b;j++){
    //         cout<<board[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
}


