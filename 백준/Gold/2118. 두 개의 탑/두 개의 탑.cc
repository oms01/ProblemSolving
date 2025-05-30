#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,x,y) for(int i=x;i<y;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define all(x) begin(x),end(x)
#define rall(x) rbegin(x),rend(x)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
    int sum = 0;
    rep(i,0,n) sum+=v[i];

    int ans = -2e9;
    for(int st=0, en=1, c=v[st]; st<n;){
        ans = max(ans, min(c,sum-c));
        if(c>=sum-c) c-=v[st++];
        else{
            c+=v[en++];
            en%=n;
        }
    }
    cout<<ans<<'\n';
}