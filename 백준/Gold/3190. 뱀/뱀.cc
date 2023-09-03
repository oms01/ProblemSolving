#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
int board[101][101]; // -1: 사과, 1:뱀, 0:빈칸
deque<pair<int,int>> dq;
int dir = 0; // 0,1,2,3 : 동,남,서,북
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int n,k,l;
int ans = 0;
bool gameOver = false;
int check(int x,int y){ //OOB,뱀칸 : 0, 사과 먹음: 1, 아무것도 없음: 2;
    if((x<=0||x>n||y<=0||y>n) || board[x][y]==1){
        return 0;
    }
    if(board[x][y]==-1){
        return 1;
    }
    else{
        return 2;
    }
}
void movehead(){//머리 이동
    pair<int,int> head = dq.front();
    head.X+=dx[dir]; head.Y+=dy[dir];
    dq.push_front({head.X,head.Y});
    board[head.X][head.Y] = 1;
}
void movetail(){//꼬리 이동
    pair<int,int> tail = dq.back();
    board[tail.X][tail.Y] = 0;
    dq.pop_back();
}
void move(){
    pair<int,int> nxt = dq.front(); //다음칸의 좌표
    nxt.X+=dx[dir]; nxt.Y+=dy[dir];

    int tmp = check(nxt.X,nxt.Y); //다음칸 검사
    if(tmp==0){ //OOB, 몸과 부딪힘
        ans++;
        gameOver = 1;
        return;
    }
    else if(tmp==1){ //사과 먹음
        movehead();
    }
    else{ //사과 안먹음
        movehead();
        movetail();
    }
    ans++;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k; // 보드 크기, 사과 개수
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        board[x][y] = -1;
    }
    dq.push_back({1,1});
    board[1][1] = 1;

    cin>>l;
    for(int i=0;i<l;i++){
        int x; char c;
        cin>>x>>c;
        for(int j=ans;j<x;j++){
            move();
            if(gameOver){
                cout<<ans<<'\n';
                return 0;
            }
        }
        if(c=='D'){ //오른쪽 회전
            dir = (dir+1)%4;
        }
        else{ //왼쪽 회전
            dir = (dir+3)%4;
        }
    }
    while(!gameOver){
        move();
    }
    cout<<ans<<'\n';
}
