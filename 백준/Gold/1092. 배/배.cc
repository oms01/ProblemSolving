#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> a(n);
    rep(i,0,n) cin>>a[i];
    int m; cin>>m;
    vector<int> b(m);
    rep(i,0,m) cin>>b[i];

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    if(a[0] < b[0]){
        cout<<-1<<'\n';
        return 0;
    }

    vector<int> vis(m,0);
    bool flag = 1;
    int ans = 0;
    while(flag){
        flag = 0;
        int idx=0;
        rep(i,0,m){
            if(idx>=n) break;
            if(vis[i]) continue;
            if(a[idx] >= b[i]){
                vis[i] = 1;
                idx++;
                flag = 1;
            }
        }
        ans++;

        // rep(i,0,m){
        //     cout<<vis[i]<<' ';
        // }
        // cout<<'\n';
    }
    cout<<ans-1<<'\n';

}
