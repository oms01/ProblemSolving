#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int n,m;
string board[11];
int vis[11][11][11][11];
pii r,b;
struct state{
    pii r,b;
    int dist;
};
queue<state> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>board[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='R') r = {i,j};
            if(board[i][j]=='B') b = {i,j};
        }
    }
    q.push({r,b,0});
    vis[r.X][r.Y][b.X][b.Y] = 1;
    while(!q.empty()){
        pii rcur = q.front().r;
        pii bcur = q.front().b;
        int d = q.front().dist;
        q.pop();
        if(d>=10) break;
        for(int dir = 0;dir<4;dir++){
            pii rnxt = rcur;
            pii bnxt = bcur;
            int rd=0,bd=0;
            while(board[rnxt.X+dx[dir]][rnxt.Y+dy[dir]]!='#' && board[rnxt.X][rnxt.Y]!='O'){
                rnxt.X+=dx[dir];
                rnxt.Y+=dy[dir];
                rd++;
            }
            while(board[bnxt.X+dx[dir]][bnxt.Y+dy[dir]]!='#' && board[bnxt.X][bnxt.Y]!='O'){
                bnxt.X+=dx[dir];
                bnxt.Y+=dy[dir];
                bd++;
            }

            if(board[bnxt.X][bnxt.Y]=='O') continue;
            if(board[rnxt.X][rnxt.Y]=='O'){
                cout<<d+1;
                return 0;
            }

            if(rnxt == bnxt){
                if(rd > bd){
                    rnxt.X -=dx[dir];
                    rnxt.Y -=dy[dir];
                }
                else{
                    bnxt.X -=dx[dir];
                    bnxt.Y -=dy[dir];
                }
            }

            if(vis[rnxt.X][rnxt.Y][bnxt.X][bnxt.Y]) continue;
            vis[rnxt.X][rnxt.Y][bnxt.X][bnxt.Y] = 1;
            q.push({rnxt,bnxt,d+1});
        }
    }
    cout<<-1<<'\n';
}