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
/*------------------------------*/

vector<tuple<int,int,int>> v;
int bag[2'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,c,m; cin>>n>>c>>m; //마을 수, 용량
    rep(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({b,a,c});
    }
    sort(all(v));
    int ans = 0;
    rep(i,0,m){
        int a,b,w;
        tie(b,a,w) = v[i];
        // cout<<a<<' '<<b<<' '<<w<<'\n';
        int mx = *max_element(bag+a,bag+b);
        int tmp = min(c-mx, w);
        ans+=tmp;
        rep(j,a,b) bag[j] += tmp;
    }
    cout<<ans<<'\n';

}