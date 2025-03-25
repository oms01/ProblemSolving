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
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int ddx[] = {-1,-1,-1,0,1,1,1,0};
int ddy[] = {-1,0,1,1,1,0,-1,-1};
const int MX = 10;
int n,m,k;
int s2d2[MX+1][MX+1];
int energy[MX+1][MX+1];
vector<int> tree[MX+1][MX+1];
vector<tiii> dead;
void spring(){
    dead.clear();
    
    rep(i,0,n) rep(j,0,n){
        sort(all(tree[i][j]));
        vector<int> tmp;
        for(auto cur: tree[i][j]){
            if(cur <= energy[i][j]){
                tmp.push_back(cur+1);
                energy[i][j]-=cur;
            }
            else{
                dead.push_back({i,j,cur});
            }
        }
        tree[i][j] = tmp;
    }
    
}
void summer(){
    for(auto[x,y,age]: dead){
        energy[x][y] += age/2;
    }
}
void autumn(){
    rep(i,0,n) rep(j,0,n){
        for(auto cur: tree[i][j]){
            if(cur%5) continue;
            for(int dir=0;dir<8;dir++){
                int nx = i + ddx[dir];
                int ny = j + ddy[dir];
                if(nx<0||nx>=n||ny<0||ny>=n) continue;
                tree[nx][ny].push_back(1);
            }
        }
    }
}
void winter(){
    rep(i,0,n) rep(j,0,n){
        energy[i][j] += s2d2[i][j];
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i,0,n) rep(j,0,n) cin>>s2d2[i][j];
    rep(i,0,n) rep(j,0,n) energy[i][j] = 5;
    rep(i,0,m){
        int x,y,age; cin>>x>>y>>age;
        x--;y--;
        tree[x][y].push_back(age);
    }

    while(k--){
        spring();
        summer();
        autumn();
        winter();
    }

    int ans = 0;
    rep(i,0,n) rep(j,0,n) ans+=tree[i][j].size();

    cout<<ans<<'\n';
}
