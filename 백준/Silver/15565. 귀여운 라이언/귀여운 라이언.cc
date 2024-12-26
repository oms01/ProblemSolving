#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    vector<int> v;
    rep(i,0,n){
        int x; cin>>x;
        if(x==2) continue;
        v.push_back(i);
    }

    if(v.size() < m){
        cout<<-1<<'\n';
        return 0;
    }

    int ans = 2e9;
    for(int i=0;i<v.size()-m+1;i++){
        ans = min(ans, v[i+m-1] -v[i]+1);
    }

    cout<<ans<<'\n';

}
