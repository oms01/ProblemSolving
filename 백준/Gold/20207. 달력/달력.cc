#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
/*----------------------*/

int board[400];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i,0,n){
        int a,b; cin>>a>>b;
        rep(i,a,b+1) board[i]++;
    }
    int st = 0;
    int cnt = 0;
    int ans = 0;
    rep(i,0,367){
        if(!board[i]){
            // cout<<st<<' '<<i<<' '<<cnt<<'\n';
            ans += (i-st)*cnt;
            cnt = 0;
            st = 0;
            continue;
        }

        if(st==0){
            st = i;
        }
        cnt = max(cnt,board[i]);
    }
    cout<<ans<<'\n';
}