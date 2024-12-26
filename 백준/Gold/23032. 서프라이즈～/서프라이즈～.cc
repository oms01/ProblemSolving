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

    int n; cin>>n;
    vector<int> v(n+1);
    vector<int> sum(n+1);
    rep(i,1,n+1){
        cin>>v[i];
        sum[i] = sum[i-1] + v[i];
    }

    int mn = 2e9;
    int ans = -1;

    // st~i / i+1~en
    rep(i,1,n){
        int st = 1;
        int en = n;
        while(st<=i && i+1<=en){
            int l = sum[i]-sum[st-1];
            int r = sum[en]-sum[i];
            int dif = abs(l-r);
            if(mn>=dif){
                ans = (mn==dif ? max(ans,l+r) : l+r);
                mn = dif;
            }
            if(l<r) en--;
            else st++;

        }
    }
    cout<<ans<<'\n';

}
