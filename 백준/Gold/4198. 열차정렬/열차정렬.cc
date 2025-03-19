#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(ll i=x;i<y;i++)
#define REP(i,x,y) for(ll i=x;i<=y;i++)
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

    int n; cin>>n;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];

    int ans = 0;
    vector<int> lis(n),lds(n);
    for(int st=n-1;st>=0;st--){
        for(int i=st+1;i<n;i++){
            if(v[st]<v[i]) lis[st] = max(lis[st],lis[i]);
            else lds[st] = max(lds[st],lds[i]);
        }
        lis[st]++;
        lds[st]++;
        int len = lis[st]+lds[st]-1;
        ans = max(ans, len);
    }
    cout<<ans<<'\n';
}