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
    ll n,l; cin>>n>>l;
    vector<pll> v(n);
    rep(i,0,n){
        ll st,en; cin>>st>>en;
        v[i] = {st,en};
    }
    sort(v.begin(),v.end());

    ll cnt = 0;
    ll en = 0; //널빤지 설치할 수 있는 가장 왼쪽
    rep(i,0,n){
        auto cur = v[i];
        if(en > cur.Y) continue;

        en = max(en,cur.X);

        cnt += (cur.Y-en+l-1)/l;
        en += (cur.Y-en+l-1)/l*l;
    }
    cout<<cnt<<'\n';
}
