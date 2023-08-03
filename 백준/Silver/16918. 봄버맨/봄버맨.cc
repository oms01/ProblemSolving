#include <bits/stdc++.h>
using namespace std;
#define X first 
#define Y second 
typedef long long ll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int r,c,n;
string board[201];
vector<pair<int,int>> bomb;
void func1(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            board[i][j]='O';
        }
    }
}
void func2(){
    for(auto cur : bomb){
        board[cur.X][cur.Y] = '.';
        for(int dir=0;dir<4;dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0||nx>=r||ny<0||ny>=c) continue;
            board[nx][ny] = '.';
        }
    }
    bomb.clear();
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]=='O') bomb.push_back({i,j});
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c>>n;
    for(int i=0;i<r;i++){
        cin>>board[i];
        for(int j=0;j<c;j++){
            if(board[i][j]=='O') bomb.push_back({i,j});
        }
    }
    for(int sec=2;sec<=n;sec++){
        //if(sec%2==0) continue;
        if(sec%2==0) func1(); 
        if(sec%2==1) func2();
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<board[i][j];
        }
        cout<<'\n';
    }

    /*
    0 초 : 보드판 입력 폭탄의 위치 저장(bomb)

    1 초 : x

    2 초 : 설치 안된 곳에 폭탄 설치 = > 모든 보트판에 폭탄
    3 초 : 0 초에서 설치한(bomb) 폭탄 + 양옆위아래 칸 폭발 / 안터진 폭탄 위치 저장(bomb)

    4 초 : 설치 안된 곳에 폭탄 설치 => 모든 보트판 폭탄
    5 초 : 3초에서 설치한 폭탄 + 양옆위아래 칸 폭발 / 안터진 폭탄 위치 저장
    */
}

