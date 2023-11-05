#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int board[21][21];
int n,m,x,y,k;
int a[6];
pii cur;
/*
    a[0]
a[4]a[1]a[5]
    a[2]
    a[3]
a[1] : 바닥, a[3] : 위
*/
int func(int dir){
    if(dir==1){ //동
        swap(a[4],a[1]); swap(a[1],a[5]); swap(a[5],a[3]);
    }
    else if(dir==2){ //서
        swap(a[5],a[1]); swap(a[1],a[4]); swap(a[4],a[3]);
    }
    else if(dir==3){ //북
        swap(a[3],a[2]); swap(a[2],a[1]); swap(a[1],a[0]);
    }
    else{ //남
        swap(a[0],a[1]); swap(a[1],a[2]); swap(a[2],a[3]);
    }
    return a[3];
}
bool chk(int dir){ //이동 가능 여부 체크
    if(dir==1){//동
        if(cur.Y + 1 >= m ) return 0;
    }
    else if(dir==2){//서
        if(cur.Y - 1 < 0 ) return 0;
    }
    else if(dir==3){//북
        if(cur.X - 1 < 0 ) return 0;
    }
    else{//남
        if(cur.X + 1 >= n ) return 0;
    }
    return 1;
}
void update(int dir){
    if(dir==1){//동
        cur.Y++;
    }
    else if(dir==2){//서
        cur.Y--;
    }
    else if(dir==3){//북
        cur.X--;
    }
    else{//남
        cur.X++;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>x>>y>>k; //지도크기 n,m / 주사위좌표 x,y / 명령 k
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin>>board[i][j];
    }
    cur = {x,y};
    while(k--){
        int dir; cin>>dir;
        if(!chk(dir)) continue;
        cout<<func(dir)<<'\n';
        update(dir);
        if(board[cur.X][cur.Y]==0){
            board[cur.X][cur.Y]=a[1];
        }
        else{
            a[1] = board[cur.X][cur.Y];
            board[cur.X][cur.Y] = 0;
        }
    }

}