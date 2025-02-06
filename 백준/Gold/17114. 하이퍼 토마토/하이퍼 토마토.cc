#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> tiii;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	
    vector<int> sz(11,0);
    rep(i,0,11) cin>>sz[i];

    int board[sz[0]][sz[1]][sz[2]][sz[3]][sz[4]][sz[5]][sz[6]][sz[7]][sz[8]][sz[9]][sz[10]];
    int dist[sz[0]][sz[1]][sz[2]][sz[3]][sz[4]][sz[5]][sz[6]][sz[7]][sz[8]][sz[9]][sz[10]];

    queue<array<int, 11>> Q;

    rep(w,0,sz[10]) rep(v,0,sz[9]) rep(u,0,sz[8]) rep(t,0,sz[7]) rep(s,0,sz[6]) rep(r,0,sz[5])
        rep(q,0,sz[4]) rep(p,0,sz[3]) rep(o,0,sz[2]) rep(n,0,sz[1]) rep(m,0,sz[0]){

            int num; cin>>num;
            board[m][n][o][p][q][r][s][t][u][v][w] = num;
            dist[m][n][o][p][q][r][s][t][u][v][w] = 0;

            if(num==1){
                Q.push({m,n,o,p,q,r,s,t,u,v,w});
            }
            if(num==0){
                dist[m][n][o][p][q][r][s][t][u][v][w] = -1;
            }
    }

	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
        for(int dir=0;dir<22;dir++){
            auto nxt = cur;
            int idx = dir/2;
            nxt[idx] += (dir%2 ? 1: -1);
            if(nxt[idx]<0||nxt[idx]>=sz[idx]) continue;
            auto& nxtDist = dist[nxt[0]][nxt[1]][nxt[2]][nxt[3]][nxt[4]][nxt[5]][nxt[6]][nxt[7]][nxt[8]][nxt[9]][nxt[10]];
            auto& curDist = dist[cur[0]][cur[1]][cur[2]][cur[3]][cur[4]][cur[5]][cur[6]][cur[7]][cur[8]][cur[9]][cur[10]];
            if(nxtDist!=-1) continue;
            nxtDist = curDist + 1;
            Q.push(nxt);
        }
	}

	int ans=0;
    rep(w,0,sz[10]) rep(v,0,sz[9]) rep(u,0,sz[8]) rep(t,0,sz[7]) rep(s,0,sz[6]) rep(r,0,sz[5])
        rep(q,0,sz[4]) rep(p,0,sz[3]) rep(o,0,sz[2]) rep(n,0,sz[1]) rep(m,0,sz[0]){
            if(dist[m][n][o][p][q][r][s][t][u][v][w]==-1){
                cout<<-1<<'\n';
                return 0;
            }
            ans = max(ans, dist[m][n][o][p][q][r][s][t][u][v][w]);
    }

	cout<<ans<<'\n';

}