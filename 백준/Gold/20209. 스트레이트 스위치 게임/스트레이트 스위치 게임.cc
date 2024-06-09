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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<int> v(n); 
    rep(i,0,n) cin>>v[i];
    vector<vector<int>> btn(m);
    rep(i,0,m){
        int x; cin>>x;
        btn[i].resize(x);
        rep(j,0,x) cin>>btn[i][j];
    }

    int ans = 2e9;
    int brute = 1;
    rep(i,1,m+1) brute*=5;
    rep(i,0,brute){
        int idx = i;
        vector<int> cur(n);
        rep(j,0,n) cur[j] = v[j];
        int cnt = 0;
        rep(j,0,m){
            //j번 버튼을 idx%5번 누르기
            // cout<<idx%5<<' ';
            cnt+=idx%5;
            for(int x: btn[j]){
                cur[x-1] = (cur[x-1] + ((j+1)*(idx%5)))%5;
            }
            idx/=5;
        }
        // cout<<'\n';
        // rep(j,0,n) cout<<cur[j]<<' ';
        // cout<<'\n';
        // cout<<*max_element(all(cur))<<" : "<<*min_element(all(cur))<<'\n';
        if(*max_element(all(cur))==*min_element(all(cur))){
            ans = min(ans,cnt);
        }
    }
    cout<<(ans==2e9 ? -1 : ans)<<'\n';

}
