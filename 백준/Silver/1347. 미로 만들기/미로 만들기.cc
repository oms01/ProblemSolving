#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
int dir; //0남, 1서, 2북, 3동
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string str; cin>>str;
    pii cur = {0,0};
    vector<pii> v;
    v.push_back(cur);
    rep(i,0,n){
        if(str[i]=='R'){
            dir = (dir+1)%4;
        }    
        else if(str[i]=='L'){
            dir = (dir+3)%4;
        }
        else{
            cur.X += dx[dir];
            cur.Y += dy[dir];
            v.push_back(cur);
        }
    }
    pii maxpos = {-2e9,-2e9};
    pii minpos = {2e9,2e9};
    for(auto pos: v){
        maxpos.X = max(maxpos.X, pos.X);
        maxpos.Y = max(maxpos.Y, pos.Y);
        minpos.X = min(minpos.X, pos.X);
        minpos.Y = min(minpos.Y, pos.Y);
    }
    pii sz = {maxpos.X-minpos.X+1, maxpos.Y-minpos.Y+1};
    vector<vector<char>> board(sz.X+1, vector<char>(sz.Y+1));
    rep(i,0,sz.X){
        fill(board[i].begin(),board[i].end(),'#');
    }
    for(auto pos : v){
        // cout<<pos.X+abs(minpos.X)<<" "<<pos.Y+abs(minpos.Y)<<'\n';   
        // cout<<pos.X<<' '<<pos.Y<<'\n';
        board[pos.X+abs(minpos.X)][pos.Y+abs(minpos.Y)] = '.';
    }

    rep(i,0,sz.X){
        rep(j,0,sz.Y){
            cout<<board[i][j];
        }
        cout<<'\n';
    }
}