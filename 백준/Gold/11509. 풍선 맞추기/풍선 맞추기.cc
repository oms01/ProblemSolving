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

int cnt[2'000'001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    int ans = 0;
    rep(i,0,n){
        int val; cin>>val;
        if(cnt[val]){
            cnt[val]--;
            cnt[val-1]++;
        }
        else{
            ans++;
            cnt[val-1]++;
        }
    }
    cout<<ans<<'\n';
}
