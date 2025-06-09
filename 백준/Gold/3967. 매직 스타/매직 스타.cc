#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

string board[5];
vector<pii> loc;
int sum(int a,int b, int c, int d, vector<int> v){
    return v[a-1]+v[b-1]+v[c-1]+v[d-1];
}
bool f(int a, int b, int c, int d, int vis){ //a,b,c,d가 채워졌는지
    return (vis&(1<<a-1) && vis&(1<<b-1) && vis&(1<<c-1) && vis&(1<<d-1));
}
bool chk(vector<int> v, int vis){
    if(f(2,3,4,5,vis) && sum(2,3,4,5,v)!=26) return 1;
    if(f(1,3,6,8,vis) && sum(1,3,6,8,v)!=26) return 1;
    if(f(1,4,7,11,vis) && sum(1,4,7,11,v)!=26) return 1;
    if(f(8,9,10,11,vis) && sum(8,9,10,11,v)!=26) return 1;
    if(f(2,6,9,12,vis) && sum(2,6,9,12,v)!=26) return 1;
    if(f(5,7,10,12,vis) && sum(5,7,10,12,v)!=26) return 1;
    return 0;
}

void func(vector<int> v, int vis, int use){
    if(chk(v,vis)) return;
    if(vis == (1<<12)-1){
        for(int i=0;i<loc.size();i++){
            board[loc[i].X][loc[i].Y] = v[i]+'A'-1;
        }
        for(int i=0;i<5;i++) cout<<board[i]<<'\n';
        exit(0);
        // cout<<'\n';
        // return;
    }
    int idx = -1;
    for(int i=0;i<12;i++){
        if(v[i]!=-1) continue;
        idx = i;
        break;
    }

    for(int i=1;i<=12;i++){
        if(use&(1<<i)) continue;
        v[idx] = i;
        func(v,vis|(1<<idx),use|(1<<i));
        v[idx] = -1;
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<int> num(12,0);
    rep(i,0,5){
        cin>>board[i];
        rep(j,0,board[i].length()){
            if(board[i][j]=='.') continue;
            loc.push_back({i,j});
            num[loc.size()-1]=(board[i][j]=='x' ? -1 : board[i][j]-'A'+1);
        }
    }
    int use=0, vis=0;
    rep(i,0,12){
        if(num[i]==-1) continue;
        use |= 1<<num[i]; //숫자 사용
        vis |= 1<<i; //칸 채워짐
    }

    func(num, vis, use);

}