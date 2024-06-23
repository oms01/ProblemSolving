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

double board[1'000'001];
double ret[1'000'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll h; cin>>h;
    vector<ll> v;
    
    v.push_back(0);
    rep(i,0,h) v.push_back(v.back()+i+1);
    
    ll q,r; cin>>q>>r;
    while(q--){
        ll a,b; cin>>a>>b;
        ll idx = lower_bound(v.begin(),v.end(),a)-v.begin();
        ll st = a - v[idx-1]-1;
        ll en = st + h-idx+1;
        board[st] += (float)b/(en-st+1);
        board[en+1] -= (float)b/(en-st+1);

    }
    rep(i,1,1'000'001) ret[i] = ret[i-1]+board[i-1];
    rep(i,1,1'000'001) ret[i]+=ret[i-1];

    while(r--){
        ll s,e; cin>>s>>e;
        cout<<ret[e]-ret[s-1]<<'\n';
    }
    // cout<<"@";


}