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
typedef pair<ld,ld> pld;
typedef tuple<int,int,int> ti3;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
/*----------------------*/

void solve(){
    int n,k; cin>>n>>k;
    vector<int> v(n);
    rep(i,0,n) cin>>v[i];
    sort(all(v));
    

    int st = 0, en = n-1;
    int cnt = 0;
    int mn = 2e9;
    while(st<en){
        int sum = v[st]+v[en];
        if(sum==k){
            st++; en--;
        }
        else if(sum<k) st++;
        else en--;

        if(abs(k-sum)<mn){
            mn = abs(k-sum);
            cnt = 1;
        }
        else if(abs(k-sum)==mn){
            cnt++;
        }
    }
    cout<<cnt<<'\n';

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--) solve();
} 