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

    ll n,m; cin>>n>>m;
    ll dist = m-n;

    if(dist<=3){
        cout<<dist<<'\n';
        return 0;
    }

    ll tmp = ceil(sqrt(dist));

    if(tmp*tmp==dist){
        cout<<2*tmp-1<<'\n';
    }
    else{
        if(dist-(tmp-1)*(tmp-1) <= (tmp-1)){
            cout<<2*tmp-2<<'\n';
        }
        else{
            cout<<2*tmp-1<<'\n';
        }
    }

}
