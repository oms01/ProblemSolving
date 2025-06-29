#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
vector<set<pair<int,int>>> f(vector<vector<int>> board, int val){
    int n = board.size(); 
    vector<set<pair<int,int>>> ret;
    
    int vis[51][51] = {0,};
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        if(board[i][j]==val || vis[i][j]) continue;

        set<pair<int,int>> v;
        v.insert({0,0});

        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i,j});
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                if(board[nx][ny]==val || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                v.insert({nx-i,ny-j});
                q.push({nx,ny});
            }
        }
        ret.push_back(v);
    }
    return ret;
}

void spin(set<pair<int,int>>& a){
    set<pair<int,int>> tmp;
    for(auto [x,y]: a){
        tmp.insert({y,5-x});
    }
    pair<int,int> loc = *tmp.begin();
    
    set<pair<int,int>> ret;
    for(auto [x,y]: tmp){
        ret.insert({x-loc.X,y-loc.Y});
    }
    a = ret;
}

bool chk(set<pair<int,int>> a, set<pair<int,int>> b){
    if(a.size()!=b.size()) return 0;
    for(int i=0;i<4;i++){
        spin(a);
        bool flag = 1;
        for(auto [x,y]: a){
            if(!b.count({x,y})) flag = 0;
        }
        if(flag) return 1;
    }
    return 0;
}
int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    vector<set<pair<int,int>>> space = f(game_board,1);
    vector<set<pair<int,int>>> frag = f(table,0);
    
    int ret = 0;
    int vis[3000] = {0,};
    for(auto sp: space) for(int i=0;i<frag.size();i++){
        if(vis[i]) continue;
        if(chk(sp,frag[i])){
            ret += sp.size();
            vis[i] = 1;
            break;
        }
    }
    return ret;
}