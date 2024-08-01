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
int vis[11];
int n; 
int ans;
void f(int idx, int val,vector<int> v){
    if(idx==n-2){
        ans = max(ans,val);
        return;
    }
    for(int i=1;i<v.size()-1;i++){
        vector<int> tmp;
        for(int j=0;j<v.size();j++){
            if(i==j) continue;
            tmp.push_back(v[j]);
        }
        f(idx+1,val+(v[i-1]*v[i+1]),tmp);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    f(0,0,v);
    cout<<ans<<'\n';
}