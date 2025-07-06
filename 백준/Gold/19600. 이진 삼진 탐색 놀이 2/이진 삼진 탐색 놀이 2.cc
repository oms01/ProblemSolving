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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

const int MX = 5000;
int bsVis[MX+1][MX+1]; //{구간 길이, 값}
int tsVis[MX+1][MX+1];
void bs(int n, int st, int en, int cnt){
    if(st>en) return;
    int mid = (st+en)/2;
    bsVis[n][mid] = cnt;
    bs(n,st,mid-1,cnt+1);
    bs(n,mid+1,en,cnt+1);
}
void ts(int n, int st, int en, int cnt){
    if(st>en) return;
    if(st==en){
        tsVis[n][st] = cnt;
        return;
    }
    int l = st + (en-st)/3;
    int r = en - (en-st)/3;
    tsVis[n][l] = cnt;
    tsVis[n][r] = cnt+1;
    ts(n,st,l-1,cnt+2);
    ts(n,l+1,r-1,cnt+2);
    ts(n,r+1,en,cnt+2);

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    REP(i,1,MX){
        bs(i,0,i-1,0);
        ts(i,0,i-1,0);
        REP(j,1,i){
            bsVis[i][j] += bsVis[i][j-1];
            tsVis[i][j] += tsVis[i][j-1];
        }
    }

    int t; cin>>t;
    while(t--){
        int n,s,e; cin>>n>>s>>e;
        int bsSum = bsVis[n][e] - (s == 0 ? 0 : bsVis[n][s - 1]);
        int tsSum = tsVis[n][e] - (s == 0 ? 0 : tsVis[n][s - 1]);
        cout << tsSum - bsSum << '\n';
    }
} 