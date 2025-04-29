#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
/*----------------------*/
string toString(vector<string> v){
    string ret = "";
    for(auto s: v) ret+=s;
    return ret;
}
vector<string> toVec(string s){
    vector<string> ret(4,"AAAA");
    rep(i,0,4) rep(j,0,4){
        ret[i][j] = s[i*4+j];
    }
    return ret;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> s(4);
    rep(i,0,4) cin>>s[i];

    vector<string> t(4);
    rep(i,0,4) cin>>t[i];

    queue<string> q;
    q.push(toString(s));
    map<string,int> dist;
    dist[toString(s)] = 1;

    while(!q.empty()){
        auto cur = toVec(q.front()); q.pop();
        auto nxt = cur;
        rep(i,0,4) rep(j,0,4){
            rep(dir,0,4){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx<0||nx>=4||ny<0||ny>=4) continue;
                if(cur[i][j]==cur[nx][ny]) continue;
                swap(nxt[i][j],nxt[nx][ny]);
                if(dist[toString(nxt)]){
                    swap(nxt[i][j],nxt[nx][ny]);
                    continue;
                }
                dist[toString(nxt)] = dist[toString(cur)]+1;
                q.push(toString(nxt));
                swap(nxt[i][j],nxt[nx][ny]);
            }
        }
    }
    cout<<dist[toString(t)]-1<<'\n';



}