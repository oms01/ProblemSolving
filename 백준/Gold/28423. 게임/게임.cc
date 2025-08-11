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
typedef pair<ld,ld> pldld;
typedef tuple<int,int,int> ti3;
typedef tuple<ll,ll,ll> tl3;
typedef tuple<int,int,int,int> ti4;
int dx[] = {-1,0,0,1};
int dy[] = {0,-1,1,0};
/*----------------------*/

const int MX = 100'000;
int chk[MX+1];
bool vis[MX+1];
string f(string s){
    int A=0,B=1;
    for(auto x: s){
        A+=x-'0';
        B*=x-'0';
    }
    string ret = to_string(A)+to_string(B);
    if(stoi(ret) > MX){
        return "-1";
    }
    return ret;
}

int dfs(string cur){
    string nxt = f(cur);
    int n = stoi(nxt);
    if(nxt=="-1"){
        return chk[n] = -1;
    }
    if(nxt!=cur && vis[n]){
        return chk[n];
    }

    vis[n] = 1;
    if(nxt==cur){
        return chk[n] = 1;
    }
    return chk[n] = dfs(nxt);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    REP(n,1,MX){
        string cur = to_string(n);
        vis[n] = 1;
        chk[n] = dfs(cur);
    }


    int l,r; cin>>l>>r;
    int ans = 0;
    for(int i=l;i<=r;i++) ans+=chk[i];
    cout<<ans<<'\n';


}
