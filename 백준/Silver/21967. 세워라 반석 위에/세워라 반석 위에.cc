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

    vector<int> cnt(11,0);
    int ans = 0;
    rep(i,0,n){
        if(v[i]-2>0) cnt[v[i]-2]++;
        if(v[i]-1>0) cnt[v[i]-1]++;
        cnt[v[i]]++;

        rep(j,1,v[i]-2){
            ans = max(ans, cnt[j]);
            cnt[j] = 0;
        }
        rep(j,v[i]+1,9){
            ans = max(ans, cnt[j]);
            cnt[j] = 0;
        }
    }
    cout<<max(ans,*max_element(cnt.begin()+1,cnt.begin()+9))<<'\n';

    
}