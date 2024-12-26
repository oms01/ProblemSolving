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
    
    int n,m; cin>>n>>m;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    sort(all(v));

    rep(i,0,n){
        if(v[i]==m){
            cout<<1<<'\n';
            return 0;
        }
        int st = i+1, en = n-1;
        while(st<en){
            ll cur = v[st] + v[en] + v[i];
            
            if(cur==m || cur-v[i]==m || cur-v[st]==m || cur-v[en]==m){
                cout<<1<<'\n';
                return 0;
            }

            if(cur < m){
                st++;
            }
            else{
                en--;
            }
        }
    }
    cout<<0<<'\n';

}
