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

int cur[100'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    
    cur[v[0]]++;
    int st=0, en=1; // m : [st, en)

    int ans = 0;
    while(st<en && en<n){
        cur[v[en]]++;
        while(cur[v[en]] > k) cur[v[st++]]--;
        ans = max(ans, ++en - st);
    }
    cout<<ans<<'\n';
}