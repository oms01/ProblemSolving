#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int r,c,t;
int ans;
int board[100][100];
vector<pair<int,int>> v;
void diffusion(){ //미세먼지 확산
    int tmp[51][51];
    int tmp2[51][51];
    memset(tmp2,0,sizeof(tmp2));
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j]==0) continue;
            if(board[i][j]==-1){
                tmp[i][j]=-1;
                continue;
            }
            //주변 칸 탐색
            int cnt = 0;
            for(int dir=0;dir<4;dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx<0||nx>=r||ny<0||ny>=c) continue;
                if(board[nx][ny]==-1) continue; 
                cnt++;
                tmp[nx][ny] += board[i][j]/5;
            }
            tmp2[i][j] = board[i][j] - (board[i][j]/5*cnt);


        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //if(board[i][j]==-1) continue;
            board[i][j] = tmp[i][j]+tmp2[i][j];
        }
    }
}
void cleaner(){ //공기청정기 작동
    // vector<pair<int,int>> v;
    // for(int i=0;i<c;i++){
    //     if(board[i][0]==-1){
    //         v.push_back({i,0});
    //     }
    // }
    //윗쪽
    for(int i=v[0].X-1;i>0;i--){
        board[i][0] = board[i-1][0];
    }
    for(int i=0;i<c-1;i++){
        board[0][i] = board[0][i+1];
    }
    for(int i=0;i<v[0].X;i++){
        board[i][c-1] = board[i+1][c-1];
    }
    for(int i=c-1;i>0;i--){
        board[v[0].X][i] = board[v[0].X][i-1];
    }
    board[v[0].X][1] = 0;


    //아랫쪽
    for(int i=v[1].X+1;i<r-1;i++){
        board[i][0] = board[i+1][0];
    }
    for(int i=0;i<c-1;i++){
        board[r-1][i] = board[r-1][i+1];
    }
    for(int i=r-1;i>v[1].X;i--){
        board[i][c-1] = board[i-1][c-1];
    }
    for(int i=c-1;i>0;i--){
        board[v[1].X][i] = board[v[1].X][i-1];
    }
    board[v[1].X][1] = 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>r>>c>>t;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>board[i][j];
            if(board[i][j]==-1) v.push_back({i,0});
        }
    }
    for(int i=0;i<t;i++){
        diffusion(); 
        cleaner();
    }

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //cout<<board[i][j]<<' ';
            ans+=board[i][j];
        }
        //cout<<'\n';
    }
    cout<<ans+2<<'\n';

}