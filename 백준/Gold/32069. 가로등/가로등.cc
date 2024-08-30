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
    ll l,n,k; cin>>l>>n>>k;

    queue<pll> q;
    unordered_set<ll> s;
    rep(i,0,n){
        ll x; cin>>x;
        q.push({0,x});
        s.insert(x);
    }

    while(k--){
        pll cur = q.front(); q.pop();
        cout<<cur.X<<'\n';
        if(cur.Y-1 >= 0 && s.find(cur.Y-1)==s.end()){
            s.insert(cur.Y-1);
            q.push({cur.X+1,cur.Y-1});
        }

        if(cur.Y+1 <= l && s.find(cur.Y+1)==s.end()){
            s.insert(cur.Y+1);
            q.push({cur.X+1,cur.Y+1});
        }
    }

}