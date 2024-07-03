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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    map<int,int> m;

    int st=0, en=1; // m : [st, en)
    m[v[0]]++;

    int ans = 0;
    while(st<en && en<n){
        m[v[en]]++;
        while(m[v[en]] > k){
            m[v[st++]]--;
        }
        en++;
        ans = max(ans, en-st);
    }
    cout<<ans<<'\n';
}