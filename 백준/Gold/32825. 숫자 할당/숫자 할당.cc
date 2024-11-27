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

int vis = 0;
bool chk(int x){
    if(!(1<=x && x<=13) || vis&(1<<x)) return 0;
    vis |= (1<<x);
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int A,B,C,D,E,F,G,H; cin>>A>>B>>C>>D>>E>>F>>G>>H;

    int ans = 0;
    rep(f,1,14) rep(g,1,14) rep(h,1,14) rep(j,1,14) rep(k,1,14) rep(m,1,14){
        
        vis = 0;
        if(!chk(f) || !chk(g) || !chk(h) || !chk(k) || !chk(m)) continue;

        int b = B - f - j - m;
        if(!chk(b)) continue;
  
        int c = C - g - k;
        if(!chk(c)) continue;

        int d = D - h;
        if(!chk(d)) continue;

        int l = H - m;
        if(!chk(l)) continue;

        int i = G - j - k;
        if(!chk(i)) continue;

        int e = F - f - g - h;
        if(!chk(e)) continue;

        int a = E - b - c - d;
        if(!chk(a) || a!=A-e-i-l) continue;

        ans++;
    }
    cout<<ans<<'\n';
}