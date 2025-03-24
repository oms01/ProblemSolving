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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tiii;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
/*----------------------*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n,m; cin>>n>>m;
    vector<string> v(n);
    rep(i,0,n){
        rep(j,0,m){
            char c; cin>>c;
            v[i]+=c;
        }
    }
    sort(all(v));
    rep(i,0,n-1){
        string a = v[i];
        string b = v[i+1];
        rep(i,0,m){
            if(a[i]=='1' && b[i]=='0'){
                return !(cout<<"NO\n");
            }
        }
    }
    cout<<"YES\n";
}