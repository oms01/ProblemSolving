#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    ll mn,mx; cin>>mn>>mx;

    set<int> s;
    for(ll i=2;i*i<=mx;i++){
        ll n = mn/(i*i);
        if(mn%(i*i)) n++;

        while(n*i*i<=mx){
            s.insert(n*i*i-mn);
            n++;
        }
    }
    cout<<mx-mn-s.size()+1<<'\n';
}
