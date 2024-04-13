#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*------------------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());

    vector<int> dif;
    rep(i,1,v.size()) dif.push_back(v[i]-v[i-1]);
    sort(dif.begin(),dif.end());

    int ans = 0;
    rep(i,0,min(dif.size()-k+1,dif.size())) ans+=dif[i];
    cout<<ans<<'\n';

}
