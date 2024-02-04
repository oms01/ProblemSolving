#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
string board[501];
int n,m;
bool func(int x,int y){
    for(int dir=0;dir<4;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx<0||nx>=n||ny<0||ny>=m) continue;
        if(board[nx][ny]=='W') return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>board[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='S'){
                if(!func(i,j)){
                    cout<<0<<'\n';
                    return 0;
                }
            }
        }
    }

    cout<<1<<'\n';
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='.') cout<<"D";
            else cout<<board[i][j];
        }
        cout<<'\n';
    }

}