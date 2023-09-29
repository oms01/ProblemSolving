#include<bits/stdc++.h>
using namespace std;
int n,t;
int board[101][101];
int dx[] = {-3,-2,-2,-1,-1,-1,0,0,0,0,1,1,1,2,2,3};
int dy[] = {0,-1,1,-2,0,2,-3,-1,1,3,-2,0,2,-1,1,0};
const int INF = 2e9;
int d[101][101];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
        cin>>board[i][j];
    }
    for(int i=0;i<n;i++) fill(d[i],d[i]+101,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    d[0][0] = 0;

    int ans = 2e9;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int x = cur.second / n;
        int y = cur.second % n;
        int cost = cur.first;
        if(d[x][y]!=cost) continue;
        int tmp = (n-x-1) + (n-y-1);
        if(tmp<=2){
            ans = min(ans,cost+tmp*t);
        }

        for(int dir=0;dir<16;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int ncost = cost + 3*t + board[nx][ny];
            if(nx<0||nx>=n||ny<0||ny>=n) continue;
            if(d[nx][ny] < ncost) continue;
            d[nx][ny] = ncost;
            pq.push({d[nx][ny], nx*n+ny});
        }
    }
    cout<<ans<<'\n';
    
    
}