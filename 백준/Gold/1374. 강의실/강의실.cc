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
    vector<pii> v;
    rep(i,0,n){
        int s,e,x;
        cin>>x>>s>>e;
        v.push_back({s,1});
        v.push_back({e,0});
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    int ans = 0;
    rep(i,0,v.size()){
        if(v[i].Y==1) ans = max(ans,++cnt);
        else cnt--;
    }
    cout<<ans<<'\n';
}

