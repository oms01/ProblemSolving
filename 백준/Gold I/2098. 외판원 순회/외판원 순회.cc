
#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;

ll n, dist[17][17];
ll cache[17][1<<17];
ll shortestPath(ll cur, ll vis){
    if(vis==(1<<n)-1){
        return dist[cur][0]; //모두 방문 완료
    }
    ll& ret = cache[cur][vis];
    if(ret!=-1) return ret;
    ret = 2e9;
    for(int nxt=0;nxt<n;nxt++){
        if(vis & (1<<nxt)) continue; //이미 방문한 도시
        if(dist[cur][nxt]==2e9) continue;
        ll cand = dist[cur][nxt] + shortestPath(nxt,vis+(1<<nxt));
        ret = min(ret,cand);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(cache,-1,sizeof(cache));

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
            if(dist[i][j]==0) dist[i][j]=2e9;
        }
    }
    cout<<shortestPath(0,1);
    // cout<<"!";
}